/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 15:19:51 by mfahey            #+#    #+#             */
/*   Updated: 2019/05/18 14:14:25 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_X 1750
# define WIN_Y 1250
# define P 3.14159265359
# include "mlx.h"
# include "libft.h"

typedef struct	s_point
{
	int				x;
	int				nx;
	int				y;
	int				ny;
	int				z;
	int				nz;
	char			*str_c;
	int				rgb[3];
	int				color;
	struct s_point	*next;
}				t_point;

typedef struct	s_line
{
	double			dx;
	double			dy;
	double			gradient;
	double			interx;
	double			intery;
	double			percent;
	int				x1;
	int				y1;
	int				color1;
	int				x2;
	int				y2;
	int				color2;
	int				x;
	int				y;
	int				color;
	t_point			*f_point;
	t_point			*s_point;
}				t_line;

typedef struct	s_fdf
{
	char			*file_name;
	void			*mlx_ptr;
	void			*win_ptr;
	char			*win_name;
	int				key;
	int				fd;
	char			**cmatrix;
	int				height;
	int				width;
	int				**imatrix;
	int				step;
	int				min_x;
	int				max_x;
	int				min_y;
	int				max_y;
	int				min_z;
	int				max_z;
	int				x;
	int				y;
	int				z;
	int				mx;
	int				my;
	double			mz;
	int				grad;
	int				grad_x;
	int				grad_y;
	int				grad_z;
	double			rad;
	double			r_x;
	double			r_y;
	double			r_z;
	int				rotation;
	int				iso;
	int				gnl;
	int				info;
	int				color_i;
	int				color;
	t_point			*point;
	t_line			*line;
}				t_fdf;

int				read_file(t_fdf *fdf);
void			get_points(t_fdf *fdf);
void			get_rgb(t_fdf *fdf);
void			get_rgb_sxth(t_point *point, int r, int g, int b);
void			get_rgb_ffth(t_fdf *fdf, t_point *point);
void			draw_line(t_fdf *fdf);
void			draw_line_sxth(t_fdf *fdf, int n);
void			draw_line_ffth(t_fdf *fdf);
void			draw_line_frst(t_fdf *fdf, t_point *f_point, t_point *s_point);
double			percent(int start, int end, int current);
int				get_color(t_fdf *fdf);
void			new_points(t_fdf *fdf);
void			rotation(t_fdf *fdf);
void			rotation_frst(t_fdf *fdf, t_point *point);
void			get_centr(t_fdf *fdf);
void			move(t_fdf *fdf);
void			zoom(t_fdf *fdf);
void			get_z(t_fdf *fdf);
void			get_default(t_fdf *fdf);
void			iso(t_fdf *fdf);
void			iso_frst(t_fdf *fdf, t_point *point);
double			get_rad_frst(t_fdf *fdf, int grad);
void			info(t_fdf *fdf);
void			info_color(t_fdf *fdf);
void			fdf_free(t_fdf *fdf);
void			add_color(t_point *point, char *buff);

#endif
