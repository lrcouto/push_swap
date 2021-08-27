/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:04:07 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/27 00:06:43 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "error_message.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

/*
** COLOR MACROS:
*/

# define BLACK			"\033[0;30m"
# define BOLD_BLACK		"\033[1;30m"
# define RED			"\033[0;31m"
# define BOLD_RED		"\033[1;31m"
# define GREEN			"\033[0;32m"
# define BOLD_GREEN		"\033[1;32m"
# define YELLOW			"\033[0;33m"
# define BOLD_YELLOW	"\033[1;33m"
# define BLUE			"\033[0;34m"
# define BOLD_BLUE		"\033[1;34m"
# define PURPLE			"\033[0;35m"
# define BOLD_PURPLE	"\033[1;35m"
# define CYAN			"\033[0;36m"
# define BOLD_CYAN		"\033[1;36m"
# define WHITE			"\033[0;37m"
# define BOLD_WHITE		"\033[1;37m"
# define RESET_COLOR	"\033[0m"

/*
** OPERATION MACROS:
*/

# define SWAP_A				"sa\n"
# define SWAP_B				"sb\n"
# define SWAP_BOTH			"ss\n"
# define PUSH_A				"pa\n"
# define PUSH_B				"pb\n"
# define ROTATE_A			"ra\n"
# define ROTATE_B			"rb\n"
# define ROTATE_BOTH		"rr\n"
# define REV_ROTATE_A		"rra\n"
# define REV_ROTATE_B		"rrb\n"
# define REV_ROTATE_BOTH	"rrr\n"

/*
** STRUCTS:
*/

typedef struct s_node
{
	int				number;
	struct s_node	*next;
	struct s_node	*previous;
}						t_node;

typedef struct s_board
{
	t_node	*a;
	t_node	*b;
	int		node_quantity;
	int		largest_number;
}				t_board;

/*
** SUPPORTING STACK OPERATIONS:
*/

void	connect_nodes(t_node *first, t_node *second);
t_node	*pop_node(t_node **stack);
void	push_node(t_node *pop, t_node **stack);
void	swap_nodes(t_node *first, t_node *second);

/*
** PUSH_SWAP STACK OPERATIONS:
*/

void	push_a(t_board	*stack);
void	push_b(t_board	*stack);
void	swap_a(t_board *stack);
void	swap_b(t_board *stack);
void	swap_both(t_board *stack);
void	rotate_a(t_board *stack);
void	rotate_b(t_board *stack);
void	rotate_both(t_board *stack);
void	reverse_rotate_a(t_board *stack);
void	reverse_rotate_b(t_board *stack);
void	reverse_rotate_both(t_board *stack);

/*
** SORTING OPERATIONS:
*/

void	radix_sort(t_board *stack);
int		get_bit(double largest_number, int i);
int		most_significant_bit(double largest_number);
bool	is_stack_ordered(t_board *stack);
void	sort_two_nodes(t_board *stack);
void	sort_three_nodes(t_board *stack);
void	sort_five_nodes(t_board *stack);
void	selection_sort(t_board *stack, int node_quantity);
void	return_nodes_to_a(t_board *stack);
void	sort_stacks(t_board *stack);

#endif