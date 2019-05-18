/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_wu_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:24:06 by mfahey            #+#    #+#             */
/*   Updated: 2019/04/30 15:00:49 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_frth(t_fdf *fdf)
{
	t_line	*line;

	line = fdf->line;
	if (ft_fabs(line->dx) > ft_fabs(line->dy))
	{
		line->x = line->x1 + 1;
		while (line->x < line->x2)
		{
			line->percent = percent(line->x1, line->x2, line->x);
			draw_line_sxth(fdf, 2);
			line->intery += line->gradient;
			(line->x)++;
		}
	}
	else
	{
		line->y = line->y1 + 1;
		while (line->y < line->y2)
		{
			line->percent = percent(line->y1, line->y2, line->y);
			draw_line_sxth(fdf, 5);
			line->interx += line->gradient;
			(line->y)++;
		}
	}
}

void	draw_line_thrd(t_fdf *fdf)
{
	t_line	*line;

	line = fdf->line;
	if (line->y2 < line->y1)
	{
		ft_swap(&(line->x1), &(line->x2));
		ft_swap(&(line->y1), &(line->y2));
		ft_swap(&(line->color1), &(line->color2));
	}
	line->gradient = line->dx / line->dy;
	line->percent = percent(line->y1, line->y2, line->y1);
	draw_line_sxth(fdf, 3);
	line->interx = line->x1 + line->gradient;
	draw_line_frth(fdf);
	line->percent = percent(line->y1, line->y2, line->y2);
	draw_line_sxth(fdf, 4);
}

void	draw_line_scnd(t_fdf *fdf)
{
	t_line	*line;

	line = fdf->line;
	if (line->x2 < line->x1)
	{
		ft_swap(&(line->x1), &(line->x2));
		ft_swap(&(line->y1), &(line->y2));
		ft_swap(&(line->color1), &(line->color2));
	}
	line->gradient = line->dy / line->dx;
	line->percent = percent(line->x1, line->x2, line->x1);
	draw_line_sxth(fdf, 0);
	line->intery = line->y1 + line->gradient;
	draw_line_frth(fdf);
	line->percent = percent(line->x1, line->x2, line->x2);
	draw_line_sxth(fdf, 1);
}

void	draw_line_frst(t_fdf *fdf, t_point *f_point, t_point *s_point)
{
	t_line	*line;

	line = fdf->line;
	line->f_point = f_point;
	line->s_point = s_point;
	line->x1 = line->f_point->nx;
	line->y1 = line->f_point->ny;
	line->color1 = line->f_point->color;
	line->x2 = line->s_point->nx;
	line->y2 = line->s_point->ny;
	line->color2 = line->s_point->color;
	line->dx = line->x2 - line->x1;
	line->dy = line->y2 - line->y1;
	if (ft_fabs(line->dx) > ft_fabs(line->dy))
		draw_line_scnd(fdf);
	else
		draw_line_thrd(fdf);
}

void	draw_line(t_fdf *fdf)
{
	t_point	*point;
	t_line	*line;
	int		i;

	point = fdf->point;
	line = malloc(sizeof(t_line));
	fdf->line = line;
	while (point)
	{
		i = 0;
		while (i < (fdf->width - 1))
		{
			draw_line_frst(fdf, point, point->next);
			point = point->next;
			i++;
		}
		if (point)
			point = point->next;
	}
	draw_line_ffth(fdf);
	fdf->line->f_point = NULL;
	fdf->line->s_point = NULL;
	free(fdf->line);
	fdf->line = NULL;
}
