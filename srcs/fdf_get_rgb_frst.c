/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_rgb_frst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 13:45:11 by mfahey            #+#    #+#             */
/*   Updated: 2019/04/28 20:15:29 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_rgb_tnth(t_fdf *fdf, t_point *point)
{
	double	d;

	if (point->z == 0)
		get_rgb_sxth(point, 0, 255, 0);
	else if (point->z > 0)
	{
		d = (point->z / (fdf->max_z / 100.0));
		get_rgb_sxth(point, (int)(d * 255 / 100),
				(int)(255 - d * 255 / 100), 0);
	}
	else
	{
		d = (point->z / (fdf->min_z / 100.0));
		get_rgb_sxth(point, 0, (int)(255 - d * 255 / 100),
				(int)(d * 255 / 100));
	}
}

void	get_rgb_eghth(t_fdf *fdf, t_point *point)
{
	double	d;

	d = ((point->z - fdf->max_z) / ((fdf->min_z - fdf->max_z) / 100.0));
	get_rgb_sxth(point, 0, (int)(255 - d * 255 / 100), (int)(d * 255 / 100));
}

void	get_rgb_svnth(t_fdf *fdf, t_point *point)
{
	double	d;

	d = ((point->z - fdf->min_z) / ((fdf->max_z - fdf->min_z) / 100.0));
	get_rgb_sxth(point, (int)(d * 255 / 100), (int)(255 - d * 255 / 100), 0);
}

void	get_rgb_sxth(t_point *point, int r, int g, int b)
{
	point->rgb[0] = r;
	point->rgb[1] = g;
	point->rgb[2] = b;
}

void	get_rgb_ffth(t_fdf *fdf, t_point *point)
{
	if ((fdf->min_z < 0) && (fdf->max_z > 0))
		get_rgb_tnth(fdf, point);
	else if ((fdf->min_z >= 0) && (fdf->max_z > 0))
		get_rgb_svnth(fdf, point);
	else if ((fdf->min_z < 0) && (fdf->max_z <= 0))
		get_rgb_eghth(fdf, point);
	else if (fdf->min_z == fdf->max_z)
		get_rgb_sxth(point, 255, 255, 255);
}
