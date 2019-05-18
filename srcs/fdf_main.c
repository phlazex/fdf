/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 15:18:58 by mfahey            #+#    #+#             */
/*   Updated: 2019/05/18 14:07:53 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_exit(t_fdf *fdf)
{
	ft_putstr("Error, usage: ./fdf source_file\n");
	exit(1);
}

void	get_key_frst(t_fdf *fdf)
{
	if (fdf->key == 18)
		fdf->grad = 0;
	else if (fdf->key == 19)
		fdf->grad_x = 0;
	else if (fdf->key == 20)
		fdf->grad_y = 0;
	else if (fdf->key == 21)
		fdf->grad_z = 0;
	else if (fdf->key == 23)
		fdf->z = 0;
	else if (fdf->key == 22)
		fdf->step = 2;
	else if (fdf->key == 26)
		fdf->iso = ft_bool(fdf->iso);
	else if (fdf->key == 28)
		fdf->rotation = ft_bool(fdf->rotation);
	else if (fdf->key == 48)
		fdf->info = ft_bool(fdf->info);
	else if (fdf->key == 29)
		info_color(fdf);
}

int		get_key(int key, t_fdf *fdf)
{
	if (!(fdf))
		return (1);
	fdf->key = key;
	if (key == 53)
	{
		fdf_free(fdf);
		exit(0);
	}
	else if (((key >= 123) && (key <= 126)) || (key == 82) || (key == 65))
		rotation(fdf);
	else if (((key >= 83) && (key <= 89)) || ((key >= 91) && (key <= 92)))
		move(fdf);
	else if ((key == 69) || (key == 78))
		zoom(fdf);
	else if ((key == 116) || (key == 121))
		iso(fdf);
	else if ((key == 67) || (key == 75))
		get_z(fdf);
	else if (key == 49)
		get_default(fdf);
	else if (((key >= 18) && (key <= 23)) || (key == 26) || (key == 28) ||
			(key == 48) || (key == 29))
		get_key_frst(fdf);
	new_points(fdf);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc == 2)
	{
		if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
			fdf_exit(fdf);
		fdf->file_name = argv[1];
		if (read_file(fdf))
			fdf_exit(fdf);
		fdf->win_name = ft_strjoin("FdF: ", fdf->file_name);
		if ((!(fdf->mlx_ptr = mlx_init())) ||
				(!(fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_X, WIN_Y,
				fdf->win_name))))
			fdf_exit(fdf);
		new_points(fdf);
		mlx_hook(fdf->win_ptr, 2, 0, get_key, fdf);
		mlx_loop(fdf->mlx_ptr);
	}
	return (0);
}
