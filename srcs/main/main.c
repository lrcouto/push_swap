/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:04:22 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/15 04:16:07 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int_list	*node_last(t_int_list *list)
{
	t_int_list	*temp;

	if (list == NULL)
		return (list);
	temp = list;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	node_add_back(t_int_list **list, t_int_list *new_node)
{
	t_int_list	*temp;

	if (new_node == NULL)
		return ;
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	temp = node_last(*list);
	temp->next = new_node;
	new_node->previous = temp;
}

void	setup_stacks(t_stack *stack, char **argv)
{
	int			i;
	t_int_list	*new_node;

	i = 1;
	while (argv[i])
	{
		new_node = (t_int_list *)ft_calloc(sizeof(t_int_list), 1);
		new_node->number = ft_atoi(argv[i]);
		new_node->next = NULL;
		new_node->previous = NULL;
		node_add_back(&stack->a, new_node);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack		*stack;
	t_int_list	*a;
	t_int_list	*b;

	stack = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	a = NULL;
	b = NULL;
	stack->a = a;
	stack->b = b;
	if (argc == 1)
		exit_with_error(NO_INPUT);
	check_for_errors(argv);
	ft_putendl_fd("Here is your input:", 1);
	print_2d_array_fd(argv, 1);
	setup_stacks(stack, argv);
	return (0);
}
