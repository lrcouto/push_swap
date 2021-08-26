/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:32:30 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/26 01:44:08 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_bits_on_zero(t_board *stack, int i)
{
	int	j;

	j = 0;
	while (j < stack->node_quantity)
	{
		if (get_bit((double)stack->a->number, i) == 0)
			push_b(stack);
		else
			rotate_a(stack);
		j++;
	}
}

void	radix_sort(t_board *stack)
{
	int	i;
	int	loop_count;

	i = 0;
	loop_count = most_significant_bit((double)stack->largest_number);
	while (i <= loop_count)
	{
		push_bits_on_zero(stack, i);
		return_nodes_to_a(stack);
		i++;
	}
}