/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:32:30 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/27 16:53:44 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	remaining_nodes_are_ordered(t_board *stack)
{
	t_node	*current;
	int		i;

	i = 0;
	current = stack->a;
	while (i < stack->nodes_on_a - 1)
	{
		if (current->number > current->next->number)
			return (false);
		current = current->next;
		i++;
	}
	return (true);
}

static void	push_bits_on_zero(t_board *stack, int i)
{
	int	j;

	j = 0;
	while (j < stack->node_quantity)
	{
		if (get_bit(stack->a->number, i) == 0)
			push_b(stack);
		else
			rotate_a(stack);
		if (remaining_nodes_are_ordered(stack) == true)
			break ;
		j++;
	}
}

void	radix_sort(t_board *stack)
{
	int	i;
	int	loop_count;

	i = 0;
	loop_count = most_significant_bit(stack->largest_number);
	while (i <= loop_count)
	{
		push_bits_on_zero(stack, i);
		return_nodes_to_a(stack);
		i++;
	}
}
