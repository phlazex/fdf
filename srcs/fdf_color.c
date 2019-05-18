/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:41:12 by mfahey            #+#    #+#             */
/*   Updated: 2019/04/29 17:14:25 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	info_color(t_fdf *fdf)
{
	fdf->color_i++;
	if (fdf->color_i == 7)
		fdf->color_i = 0;
	if (fdf->color_i == 0)
		fdf->color = 0xffffff;
	else if (fdf->color_i == 1)
		fdf->color = 0xff0000;
	else if (fdf->color_i == 2)
		fdf->color = 0xff00ff;
	else if (fdf->color_i == 3)
		fdf->color = 0x00ff00;
	else if (fdf->color_i == 4)
		fdf->color = 0xffff00;
	else if (fdf->color_i == 5)
		fdf->color = 0x0000ff;
	else if (fdf->color_i == 6)
		fdf->color = 0x00ffff;
}

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int		get_color(t_fdf *fdf)
{
	int		color1;
	int		color2;
	int		red;
	int		green;
	int		blue;

	color1 = fdf->line->color1;
	color2 = fdf->line->color2;
	if (color1 == color2)
		return (color1);
	red = get_light((color1 >> 16) & 0xFF, (color2 >> 16) &
			0xFF, fdf->line->percent);
	green = get_light((color1 >> 8) & 0xFF, (color2 >> 8) &
			0xFF, fdf->line->percent);
	blue = get_light(color1 & 0xFF, color2 & 0xFF,
			fdf->line->percent);
	return ((red << 16) | (green << 8) | blue);
}
