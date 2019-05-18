/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_iso.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 18:03:05 by mfahey            #+#    #+#             */
/*   Updated: 2019/04/29 12:13:31 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_centr(t_fdf *fdf)
{
	int		cx;
	int		cy;

	cx = (fdf->min_x + fdf->max_x) / 2;
	cy = (fdf->min_y + fdf->max_y) / 2;
	fdf->x = WIN_X / 2 - cx + fdf->mx;
	fdf->y = WIN_Y / 2 - cy + fdf->my;
}

void	iso_frst(t_fdf *fdf, t_point *point)
{
	int		previous_x;
	int		previous_y;

	if (fdf->grad)
	{
		fdf->rad = get_rad_frst(fdf, fdf->grad);
		previous_x = point->nx;
		previous_y = point->ny;
		point->nx = (previous_x - previous_y) * cos(fdf->rad);
		point->ny = (previous_x + previous_y) * sin(fdf->rad) - point->nz;
	}
}

void	iso(t_fdf *fdf)
{
	if (((fdf->grad_x) || (fdf->grad_y) || (fdf->grad_z)) && (fdf->iso))
		get_default(fdf);
	if (fdf->grad > 360)
		fdf->grad -= 360;
	else if (!(fdf->grad))
		fdf->grad = 30;
	if (fdf->key == 116)
		fdf->grad--;
	else if (fdf->key == 121)
		fdf->grad++;
	if (!(fdf->grad))
		fdf->grad = 360;
}
