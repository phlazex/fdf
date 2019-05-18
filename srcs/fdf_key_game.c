/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 19:32:19 by mfahey            #+#    #+#             */
/*   Updated: 2019/04/28 20:17:47 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_z(t_fdf *fdf)
{
	if ((fdf->key == 67) && ((fdf->z + 1) < 2147483647))
		fdf->z++;
	else if ((fdf->key == 75) && ((fdf->z - 1) > -2147483648))
		fdf->z--;
}

void	zoom(t_fdf *fdf)
{
	fdf->mz = (double)fdf->z / ((double)fdf->step / 100.0);
	if ((fdf->key == 78) && (fdf->step > 2))
		fdf->step--;
	else if ((fdf->key == 69) && ((fdf->max_x + 1) < 2147483647)
			&& ((fdf->max_y + 1) < 2147483647))
		fdf->step++;
	fdf->mz -= (double)fdf->z / ((double)fdf->step / 100.0);
	if (fdf->z >= 0)
		fdf->z += (int)((double)fdf->step / 100.0 * fdf->mz);
	else
		fdf->z -= (int)((double)fdf->step / 100.0 * fdf->mz);
}

void	move_frst(t_fdf *fdf)
{
	if (fdf->key == 89)
	{
		(fdf->mx)--;
		(fdf->my)--;
	}
	else if (fdf->key == 92)
	{
		(fdf->mx)++;
		(fdf->my)--;
	}
	else if (fdf->key == 85)
	{
		(fdf->mx)++;
		(fdf->my)++;
	}
	else if (fdf->key == 83)
	{
		(fdf->mx)--;
		(fdf->my)++;
	}
}

void	move(t_fdf *fdf)
{
	if (fdf->key == 86)
		(fdf->mx)--;
	else if (fdf->key == 88)
		(fdf->mx)++;
	else if (fdf->key == 84)
		(fdf->my)++;
	else if (fdf->key == 91)
		(fdf->my)--;
	else if (fdf->key == 87)
	{
		fdf->mx = 0;
		fdf->my = 0;
	}
	else
		move_frst(fdf);
}
