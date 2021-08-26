/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 00:19:03 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/26 00:42:13 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bit(double largest_number, int i)
{
	unsigned long long	bit_position;

	bit_position = (unsigned long long)largest_number;
	return ((unsigned long long)(bit_position >> i) & 1);
}

int	most_significant_bit(double largest_number)
{
	double	i;

	i = 63;
	while (get_bit(largest_number, i) != 1)
		i--;
	return (i);
}