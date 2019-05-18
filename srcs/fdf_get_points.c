/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:01:26 by mfahey            #+#    #+#             */
/*   Updated: 2019/05/18 13:03:13 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_start_step(t_fdf *fdf, int m_pxl, int c_pxl)
{
	int		p;

	fdf->step = 2;
	if (m_pxl > c_pxl)
	{
		p = m_pxl / 100 * 30;
		while ((fdf->step * c_pxl) < p)
			fdf->step++;
	}
}

void	get_default(t_fdf *fdf)
{
	if (fdf->width > fdf->height)
		get_start_step(fdf, WIN_Y, (fdf->height - 1));
	else
		get_start_step(fdf, WIN_X, (fdf->width - 1));
	fdf->grad = 0;
	fdf->grad_x = 0;
	fdf->grad_y = 0;
	fdf->grad_z = 0;
	fdf->min_x = 0;
	fdf->min_y = 0;
	fdf->max_x = 0;
	fdf->max_y = 0;
	fdf->x = 0;
	fdf->y = 0;
	fdf->z = fdf->step;
	fdf->mx = 0;
	fdf->my = 0;
	fdf->mz = (double)fdf->z / ((double)fdf->step / 100.0);
	fdf->rotation = 1;
	fdf->iso = 1;
	fdf->info = 1;
	fdf->color = 0xffffff;
}

int		get_matrix_frst(t_fdf *fdf)
{
	char	**buff;
	int		i;
	int		j;
	int		len;

	if (!(fdf->imatrix = (int **)malloc(sizeof(int *) * fdf->height)))
		return (1);
	i = 0;
	while (i < fdf->height)
	{
		buff = ft_strsplit((fdf->cmatrix)[i], ' ');
		if (((len = ft_str2len(buff)) != fdf->width) ||
				(!(fdf->imatrix[i] = (int *)malloc(sizeof(int) * fdf->width))))
			return (1);
		j = 0;
		while (j < fdf->width)
		{
			fdf->imatrix[i][j] = ft_atoi(buff[j]);
			j++;
		}
		ft_free_mas(&buff);
		i++;
	}
	return (0);
}

int		get_matrix(t_fdf *fdf, char **res)
{
	char	**buff;

	if (fdf->gnl < 0)
		return (1);
	fdf->cmatrix = ft_strsplit(*res, '\n');
	ft_strdel(res);
	buff = ft_strsplit(*(fdf->cmatrix), ' ');
	fdf->height = (int)ft_str2len(fdf->cmatrix);
	fdf->width = (int)ft_str2len(buff);
	ft_free_mas(&buff);
	if (get_matrix_frst(fdf))
		return (1);
	get_default(fdf);
	get_points(fdf);
	return (0);
}

int		read_file(t_fdf *fdf)
{
	char	*res;
	char	*line;
	char	*buff;

	if ((fdf->fd = open(fdf->file_name, O_RDONLY)) == -1)
		return (1);
	res = NULL;
	while ((fdf->gnl = get_next_line(fdf->fd, &line)) > 0)
		if (!(res))
		{
			res = ft_strjoin(line, "\n");
			ft_strdel(&line);
		}
		else
		{
			buff = res;
			res = ft_strjoin(res, line);
			ft_strdel(&buff);
			ft_strdel(&line);
			buff = res;
			res = ft_strjoin(res, "\n");
			ft_strdel(&buff);
		}
	ft_strdel(&line);
	return (get_matrix(fdf, &res));
}
