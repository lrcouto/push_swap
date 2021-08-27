/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:06:01 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/27 16:55:25 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_list(t_node **stack)
{
	t_node	*head;

	head = *stack;
	if (head == NULL)
		return ;
	head = head->next;
	*stack = head;
}

void	rotate_a(t_board *stack)
{
	rotate_list(&stack->a);
	ft_putstr_fd(ROTATE_A, 1);
}

void	rotate_b(t_board *stack)
{
	rotate_list(&stack->b);
	ft_putstr_fd(ROTATE_B, 1);
}

void	rotate_both(t_board *stack)
{
	rotate_list(&stack->a);
	rotate_list(&stack->b);
	ft_putstr_fd(ROTATE_BOTH, 1);
}
