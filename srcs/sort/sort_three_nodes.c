/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 20:18:48 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/27 16:54:21 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_int_values(int *first, int *second, int *third, t_board *stack)
{
	*first = stack->a->number;
	*second = stack->a->next->number;
	*third = stack->a->previous->number;
}

void	sort_three_nodes(t_board *stack)
{
	int	first;
	int	second;
	int	third;

	set_int_values(&first, &second, &third, stack);
	if ((first > second && first < third && second < third)
		|| (first > second && first > third && second > third)
		|| (first < second && first < third && second > third))
		swap_a(stack);
	if (is_stack_ordered(stack, stack->node_quantity) == true)
		return ;
	set_int_values(&first, &second, &third, stack);
	if (first < second && first > third && second > third)
		reverse_rotate_a(stack);
	if (first > second && first > third && second < third)
		rotate_a(stack);
}
