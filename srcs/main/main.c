/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:04:22 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/27 13:22:14 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_last(t_node *list)
{
	t_node	*current;

	if (list == NULL)
		return (list);
	current = list;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	node_add_back(t_node **list, t_node *new_node)
{
	t_node	*current;

	if (new_node == NULL)
		return ;
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	current = node_last(*list);
	current->next = new_node;
	new_node->previous = current;
}

void	setup_stacks(t_board *stack, int *normalized)
{
	int		i;
	t_node	*new_node;

	i = 0;
	while (i < stack->node_quantity)
	{
		new_node = (t_node *)ft_calloc(sizeof(t_node), 1);
		new_node->number = normalized[i];
		new_node->next = NULL;
		new_node->previous = NULL;
		node_add_back(&stack->a, new_node);
		stack->nodes_on_a += 1;
		if (new_node->number > stack->largest_number)
			stack->largest_number = new_node->number;
		i++;
	}
	connect_nodes(stack->a, node_last(stack->a));
}

int	main(int argc, char **argv)
{
	t_board	*stack;
	int		*normalized;

	stack = (t_board *)ft_calloc(sizeof(t_board), 1);
	stack->node_quantity = argc - 1;
	stack->nodes_on_a = 0;
	stack->nodes_on_b = 0;
	stack->largest_number = INT_MIN;
	stack->a = NULL;
	stack->b = NULL;
	if (argc == 1)
		exit(0);
	check_for_errors(argv);
	normalized = normalize_by_index(argv, argc - 1);
	setup_stacks(stack, normalized);
	sort_stacks(stack);
	exit(0);
}
