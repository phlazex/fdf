/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:05:02 by mfahey            #+#    #+#             */
/*   Updated: 2019/04/20 18:00:18 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(int *a, int *b)
{
	*a += *b;
	*b = *a - *b;
	*a -= *b;
}
