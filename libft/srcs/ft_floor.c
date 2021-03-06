/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:36:12 by mfahey            #+#    #+#             */
/*   Updated: 2019/04/16 16:44:35 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_floor(double x)
{
	int n;

	if (x < 0)
		n = (int)(x - 1.0);
	else
		n = (int)x;
	return ((double)n);
}
