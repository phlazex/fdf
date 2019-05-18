/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:07:53 by mfahey            #+#    #+#             */
/*   Updated: 2019/04/29 17:25:15 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	info_scnd(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 20, fdf->color,
			"Exit: <Esc>");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 150, 20, fdf->color,
			"Default: <Space>");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 330, 20, fdf->color,
			"On/Off info: <Tab>");
	if (fdf->info)
	{
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1250, 1170, fdf->color,
				"Reset:");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1320, 1170, fdf->color,
				"iso: <1>");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1320, 1190, fdf->color,
				"depth: <5>");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1320, 1210, fdf->color,
				"zoom: <6>");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1450, 1170, fdf->color,
				"Iso +/-: <PageUp>/<PageDown>");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 530, 20, fdf->color,
				"Change color info: <0>");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1440, 20, fdf->color,
				"On/Off iso when rotation: <7>");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1440, 40, fdf->color,
				"On/Off rotation when iso: <8>");
	}
}

void	info_frst(t_fdf *fdf)
{
	if (fdf->info)
	{
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 650, 1170, fdf->color,
				"Rotation:");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 750, 1170, fdf->color,
				"X +/-: <Left>/<Right>");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 750, 1190, fdf->color,
				"Y +/-: <Up>/<Down>");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 750, 1210, fdf->color,
				"Z +/-: <Num 0>/<Num .>");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1000, 1170, fdf->color,
				"Reset rotation:");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1160, 1170, fdf->color,
				"X: <2>");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1160, 1190, fdf->color,
				"Y: <3>");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1160, 1210, fdf->color,
				"Z: <4>");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1450, 1190, fdf->color,
				"Depth +/-: <Num *>/<Num />");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1450, 1210, fdf->color,
				"Zoom +/-: <Num +>/<Num ->");
	}
	info_scnd(fdf);
}

void	info(t_fdf *fdf)
{
	if (fdf->info)
	{
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 1170, fdf->color,
				"Move:");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 80, 1170, fdf->color,
				"Up+Left: <Num 7>");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 270, 1170, fdf->color,
				"Up: <Num 8>");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 430, 1170, fdf->color,
				"Up+Right: <Num 9>");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 80, 1190, fdf->color,
				"Left: <Num 4>");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 270, 1190, fdf->color,
				"Centre: <Num 5>");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 430, 1190, fdf->color,
				"Right: <Num 6>");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 80, 1210, fdf->color,
				"Down+Left: <Num 1>");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 270, 1210, fdf->color,
				"Down: <Num 2>");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 430, 1210, fdf->color,
				"Down+Right: <Num 3>");
	}
	info_frst(fdf);
}
