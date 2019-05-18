/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_wu_line_frst.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:25:17 by mfahey            #+#    #+#             */
/*   Updated: 2019/04/29 13:07:54 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_eghth(t_fdf *fdf, int n)
{
	t_line	*line;

	line = fdf->line;
	if (n == 2)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, line->x + fdf->x,
				ft_ipart(line->intery) + fdf->y, get_color(fdf));
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, line->x + fdf->x,
				ft_ipart(line->intery) + 1 + fdf->y, get_color(fdf));
	}
	else if (n == 5)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, ft_ipart(line->interx) +
				fdf->x, line->y + fdf->y, get_color(fdf));
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, ft_ipart(line->interx) + 1 +
				fdf->x, line->y + fdf->y, get_color(fdf));
	}
}

void	draw_line_svnth(t_fdf *fdf, int n)
{
	t_line	*line;

	line = fdf->line;
	if (n == 3)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, line->x1 + fdf->x, line->y1 +
				fdf->y, get_color(fdf));
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, line->x1 + fdf->x, line->y1 +
				1 + fdf->y, get_color(fdf));
	}
	else if (n == 4)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, line->x2 + fdf->x, line->y2 +
				fdf->y, get_color(fdf));
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, line->x2 + fdf->x, line->y2 +
				1 + fdf->y, get_color(fdf));
	}
	else
		draw_line_eghth(fdf, n);
}

void	draw_line_sxth(t_fdf *fdf, int n)
{
	t_line	*line;

	line = fdf->line;
	if (n == 0)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, line->x1 + fdf->x, line->y1 +
				fdf->y, get_color(fdf));
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, line->x1 + fdf->x, line->y1 +
				1 + fdf->y, get_color(fdf));
	}
	else if (n == 1)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, line->x2 + fdf->x, line->y2 +
				fdf->y, get_color(fdf));
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, line->x2 + fdf->x, line->y2 +
				1 + fdf->y, get_color(fdf));
	}
	else
		draw_line_svnth(fdf, n);
}

void	draw_line_ffth(t_fdf *fdf)
{
	t_point	*f_point;
	t_point	*s_point;
	int		i;

	f_point = fdf->point;
	s_point = f_point->next;
	i = 0;
	while (i < fdf->width - 1)
	{
		s_point = s_point->next;
		i++;
	}
	while (f_point && s_point)
	{
		draw_line_frst(fdf, f_point, s_point);
		f_point = f_point->next;
		s_point = s_point->next;
	}
}
