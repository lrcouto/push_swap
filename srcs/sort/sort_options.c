/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 00:44:29 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/26 02:08:01 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_stack_ordered(t_board *stack)
{
	int		i;
	int		number;
	t_node	*current;

	i = 0;
	number = 0;
	current = stack->a;
	while(i < stack->node_quantity)
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
	if (is_stack_ordered(stack) == true)
		return ;
	else if (stack->node_quantity == 2)
		sort_two_nodes(stack);
	else if (stack->node_quantity < 10)
		selection_sort(stack, stack->node_quantity);
	else
		radix_sort(stack);
}
