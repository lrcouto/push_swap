/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:06:01 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/27 16:55:38 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_list(t_node **stack)
{
	t_node	*head;

	head = *stack;
	if (head == NULL)
		return ;
	head = head->previous;
	*stack = head;
}

void	reverse_rotate_a(t_board *stack)
{
	reverse_rotate_list(&stack->a);
	ft_putstr_fd(REV_ROTATE_A, 1);
}

void	reverse_rotate_b(t_board *stack)
{
	reverse_rotate_list(&stack->b);
	ft_putstr_fd(REV_ROTATE_B, 1);
}

void	reverse_rotate_both(t_board *stack)
{
	reverse_rotate_list(&stack->a);
	reverse_rotate_list(&stack->b);
	ft_putstr_fd(REV_ROTATE_BOTH, 1);
}
