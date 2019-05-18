/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 13:43:32 by mfahey            #+#    #+#             */
/*   Updated: 2019/04/28 20:16:37 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_rgb_frth(int a, int b, int *j, t_point *point)
{
	point->rgb[*j] = a * 16 + b;
	(*j)++;
}

int		get_rgb_thrd(int len, t_point *point)
{
	if (len == 2)
		return (2);
	else if (len == 4)
		return (1);
	else if ((len == 3) || (len == 6))
		return (0);
	else
		return (-1);
}

int		get_rgb_scnd(int c, int *i)
{
	(*i)++;
	if ((c >= '0') && (c <= '9'))
		return (c - 48);
	else if ((c >= 'A') && (c <= 'F'))
		return (c - 55);
	else if ((c >= 'a') && (c <= 'f'))
		return (c - 87);
	else
		return (0);
}

void	get_rgb_frst(t_point *point)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while ((point->str_c[i] != '\0') && ((get_rgb_scnd(point->str_c[i], &j)
			>= 0) && (get_rgb_scnd(point->str_c[i], &j) <= 15)))
		i++;
	if ((len = ft_strlen(point->str_c)) == i)
	{
		j = get_rgb_thrd(len, point);
		i = 0;
		if (((len % 2) == 0) && (j >= 0))
			while (point->str_c[i] != '\0')
				get_rgb_frth(get_rgb_scnd(point->str_c[i], &i),
						get_rgb_scnd(point->str_c[i], &i), &j, point);
		else if ((j == 0) && (len == 3))
			while (point->str_c[i] != '\0')
				get_rgb_frth(get_rgb_scnd(point->str_c[i], &len),
						get_rgb_scnd(point->str_c[i], &i), &j, point);
	}
	else
		ft_strdel(&(point->str_c));
}

void	get_rgb(t_fdf *fdf)
{
	t_point	*point;

	point = fdf->point;
	while (point)
	{
		get_rgb_sxth(point, 0, 0, 0);
		if (point->str_c)
			get_rgb_frst(point);
		else
			get_rgb_ffth(fdf, point);
		point->color = ((point->rgb[0] * 256 + point->rgb[1]) * 256 +
				point->rgb[2]);
		point = point->next;
	}
}
