/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 23:12:32 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/27 16:54:40 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_second_smallest_to_b(t_board *stack, int position)
{
	if (position == 2)
		swap_a(stack);
	if (position == 3)
	{
		rotate_a(stack);
		swap_a(stack);
	}
	if (position == 4)
		reverse_rotate_a(stack);
	push_b(stack);
}

static void	push_smallest_to_b(t_board *stack, int position)
{
	if (position == 2)
		swap_a(stack);
	if (position == 3)
	{
		rotate_a(stack);
		swap_a(stack);
	}
	if (position == 4)
	{
		reverse_rotate_a(stack);
		reverse_rotate_a(stack);
	}
	if (position == 5)
		reverse_rotate_a(stack);
	push_b(stack);
}

static int	find_smallest(t_board *stack, int node_quantity)
{
	int		i;
	int		smallest;
	t_node	*current;

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
	return (smallest);
}

static int	find_smallest_position(t_board *stack, int node_quantity)
{
	int		i;
	int		smallest;
	t_node	*current;

	i = 1;
	smallest = find_smallest(stack, node_quantity);
	current = stack->a;
	while (i < stack->node_quantity)
	{
		if (current->number == smallest)
			break ;
		i++;
		current = current->next;
	}
	return (i);
}

void	sort_five_nodes(t_board *stack)
{
	int	position;

	position = find_smallest_position(stack, 5);
	push_smallest_to_b(stack, position);
	position = find_smallest_position(stack, 4);
	push_second_smallest_to_b(stack, position);
	sort_three_nodes(stack);
	push_a(stack);
	push_a(stack);
}
