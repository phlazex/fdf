/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:11:27 by mfahey            #+#    #+#             */
/*   Updated: 2019/04/28 22:27:21 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	get_rad_frst(t_fdf *fdf, int grad)
{
	return (((double)(grad) * P) / 180.0);
}

void	get_rad(t_fdf *fdf)
{
	fdf->r_x = get_rad_frst(fdf, fdf->grad_x);
	fdf->r_y = get_rad_frst(fdf, fdf->grad_y);
	fdf->r_z = get_rad_frst(fdf, fdf->grad_z);
}

void	rotation_frst(t_fdf *fdf, t_point *point)
{
	int		previous_x;
	int		previous_y;
	int		previous_z;

	if (fdf->grad_x)
	{
		previous_y = point->ny;
		previous_z = point->nz;
		point->ny = previous_y * cos(fdf->r_x) + previous_z * sin(fdf->r_x);
		point->nz = (-previous_y) * sin(fdf->r_x) + previous_z * cos(fdf->r_x);
	}
	if (fdf->grad_y)
	{
		previous_x = point->nx;
		previous_z = point->nz;
		point->nx = previous_x * cos(fdf->r_y) + previous_z * sin(fdf->r_y);
		point->nz = (-previous_x) * sin(fdf->r_y) + previous_z * cos(fdf->r_y);
	}
	if (fdf->grad_z)
	{
		previous_x = point->nx;
		previous_y = point->ny;
		point->nx = previous_x * cos(fdf->r_z) - previous_y * sin(fdf->r_z);
		point->ny = previous_x * sin(fdf->r_z) + previous_y * cos(fdf->r_z);
	}
}

void	rotation(t_fdf *fdf)
{
	if ((fdf->grad) && (fdf->rotation))
		get_default(fdf);
	if (fdf->key == 123)
		fdf->grad_y--;
	else if (fdf->key == 124)
		fdf->grad_y++;
	else if (fdf->key == 126)
		fdf->grad_x--;
	else if (fdf->key == 125)
		fdf->grad_x++;
	else if (fdf->key == 82)
		fdf->grad_z--;
	else if (fdf->key == 65)
		fdf->grad_z++;
	get_rad(fdf);
}
