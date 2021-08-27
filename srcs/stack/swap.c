/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 20:43:23 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/27 16:55:43 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_board *stack)
{
	swap_nodes(stack->a, stack->a->next);
	ft_putstr_fd(SWAP_A, 1);
}

void	swap_b(t_board *stack)
{
	swap_nodes(stack->b, stack->b->next);
	ft_putstr_fd(SWAP_B, 1);
}

void	swap_both(t_board *stack)
{
	swap_nodes(stack->a, stack->a->next);
	swap_nodes(stack->b, stack->b->next);
	ft_putstr_fd(SWAP_BOTH, 1);
}
