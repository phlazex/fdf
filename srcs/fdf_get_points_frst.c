/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_points_frst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:34:01 by mfahey            #+#    #+#             */
/*   Updated: 2019/05/18 14:06:32 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	new_point(t_fdf *fdf, t_point *point)
{
	point->nx = point->x * fdf->step;
	point->ny = point->y * fdf->step;
	point->nz = point->z * fdf->z;
	iso_frst(fdf, point);
	rotation_frst(fdf, point);
	fdf->max_x = point->nx;
	fdf->max_y = point->ny;
}

void	new_points(t_fdf *fdf)
{
	t_point	*point;

	point = fdf->point;
	fdf->min_x = point->x * fdf->step;
	fdf->min_y = point->y * fdf->step;
	while (point)
	{
		new_point(fdf, point);
		point = point->next;
	}
	get_centr(fdf);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw_line(fdf);
	info(fdf);
}

void	get_colors(t_fdf *fdf)
{
	t_point	*point;
	char	**buff;
	int		i[2];

	point = fdf->point;
	i[0] = 0;
	while (i[0] < fdf->height)
	{
		buff = ft_strsplit((fdf->cmatrix)[i[0]], ' ');
		i[1] = 0;
		while (i[1] < fdf->width)
		{
			if (ft_strchr(buff[i[1]], 'x'))
				add_color(point, buff[i[1]]);
			fdf->min_z = ft_min(ft_atoi(buff[i[1]]), fdf->min_z);
			fdf->max_z = ft_max(ft_atoi(buff[i[1]]), fdf->max_z);
			point = point->next;
			free(buff[i[1]]);
			i[1]++;
		}
		free(buff);
		buff = NULL;
		i[0]++;
	}
	get_rgb(fdf);
}

t_point	*get_points_frst(t_fdf *fdf, int x, int y, int z)
{
	t_point		*point;

	if (!(point = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	point->str_c = NULL;
	point->next = NULL;
	return (point);
}

void	get_points(t_fdf *fdf)
{
	t_point		*point;
	int			i;
	int			j;

	point = get_points_frst(fdf, 0, 0, fdf->imatrix[0][0]);
	fdf->point = point;
	fdf->min_z = fdf->imatrix[0][0];
	fdf->max_z = fdf->imatrix[0][0];
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		if (!(i))
			j = 1;
		while (j < fdf->width)
		{
			point->next = get_points_frst(fdf, j, i, fdf->imatrix[i][j]);
			point = point->next;
			j++;
		}
		i++;
	}
	get_colors(fdf);
}
