/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:29:50 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/22 19:56:53 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_board	*stack)
{
	t_node	*pop;

	pop = pop_node(&stack->b);
	push_node(pop, &stack->a);
	ft_putstr_fd(PUSH_A, 1);
}

void	push_b(t_board	*stack)
{
	t_node	*pop;

	pop = pop_node(&stack->a);
	push_node(pop, &stack->b);
	ft_putstr_fd(PUSH_B, 1);
}
