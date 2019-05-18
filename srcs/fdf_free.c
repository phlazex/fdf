/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:27:22 by mfahey            #+#    #+#             */
/*   Updated: 2019/05/18 14:07:00 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_color(t_point *point, char *buff)
{
	char	*lol;
	size_t	len;

	lol = ft_strchr(buff, 'x') + 1;
	len = ft_strlen(lol);
	point->str_c = ft_strnew(len);
	ft_strcpy(point->str_c, lol);
}

void	free_thrd(t_fdf *fdf)
{
	if (fdf->line)
	{
		if (fdf->line->f_point)
			fdf->line->f_point = NULL;
		if (fdf->line->s_point)
			fdf->line->s_point = NULL;
		fdf->line = NULL;
	}
}

void	free_scnd(t_fdf *fdf)
{
	t_point	*point;
	t_point	*next;

	point = fdf->point;
	while (point)
	{
		next = point->next;
		if (point->str_c)
			ft_strdel(&(point->str_c));
		free(point);
		point = next;
	}
	fdf->point = NULL;
}

void	free_frst(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (i < fdf->height)
	{
		free((fdf->imatrix[i]));
		i++;
	}
	free(fdf->imatrix);
	fdf->imatrix = NULL;
	i = 0;
	while (i < fdf->height)
	{
		ft_strdel(&(fdf->cmatrix[i]));
		i++;
	}
	free(fdf->cmatrix);
	fdf->cmatrix = NULL;
}

void	fdf_free(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	free_frst(fdf);
	free_scnd(fdf);
	free_thrd(fdf);
	fdf->file_name = NULL;
	ft_strdel(&(fdf->win_name));
	free(fdf);
	fdf = NULL;
}
