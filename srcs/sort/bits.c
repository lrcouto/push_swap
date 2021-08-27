/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 00:19:03 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/27 16:52:39 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bit(int largest_number, int i)
{
	return ((largest_number >> i) & 1);
}

int	most_significant_bit(int largest_number)
{
	int	i;

	i = 31;
	while (get_bit(largest_number, i) != 1)
		i--;
	return (i);
}
