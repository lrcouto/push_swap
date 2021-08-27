/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 00:44:29 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/27 16:53:21 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_stack_ordered(t_board *stack, int size)
{
	int		i;
	int		number;
	t_node	*current;

	i = 1;
	number = stack->a->number;
	current = stack->a->next;
	while (i < size)
	{
		if (number > current->number)
			return (false);
		number = current->number;
		current = current->next;
		i++;
	}
	return (true);
}

void	return_nodes_to_a(t_board *stack)
{
	while (stack->b != NULL)
		push_a(stack);
}

void	sort_two_nodes(t_board *stack)
{
	if (stack->a->number > stack->a->next->number)
		rotate_a(stack);
}

void	sort_stacks(t_board *stack)
{
	if (is_stack_ordered(stack, stack->node_quantity) == true)
		return ;
	else if (stack->node_quantity == 2)
		sort_two_nodes(stack);
	else if (stack->node_quantity == 3)
		sort_three_nodes(stack);
	else if (stack->node_quantity == 5)
		sort_five_nodes(stack);
	else
		radix_sort(stack);
}
