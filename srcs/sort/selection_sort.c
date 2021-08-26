/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 01:53:00 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/26 01:53:25 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_board *stack, int node_quantity)
{
	int		i;
	int		smallest;
	t_node	*current;

	if (stack->a == NULL)
	{
		return_nodes_to_a(stack);
		return ;
	}
	i = 0;
	smallest = stack->largest_number;
	current = stack->a;
	while (i < node_quantity)
	{
		if (current->number < smallest)
			smallest = current->number;
		current = current->next;
		i++;
	}
	while (stack->a->number != smallest)
		rotate_a(stack);
	push_b(stack);
	return (selection_sort(stack, node_quantity - 1));
}
