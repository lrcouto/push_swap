/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:04:22 by lcouto            #+#    #+#             */
/*   Updated: 2021/06/09 00:47:01 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** TODO: Write functions to validade int input, convert string to int.
*/

static void	is_valid_int(char *current_arg)
{
	int	i;

	i = 0;
	if (current_arg[0] == '-')
		i = 1;
	while (current_arg[i])
	{
		if (ft_isdigit((int)current_arg[i]) == 0)
			exit_with_error(NOT_DIGIT);
		i++;
	}
}

static void	read_and_store_input(char **argv)
{
	int	i;

	i = 1;
	ft_putendl_fd("Here is your input:", 1);
	while (argv[i] != NULL)
	{
		is_valid_int(argv[i]);
		ft_putendl_fd(argv[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		exit_with_error(NO_INPUT);
	read_and_store_input(argv);
	return (0);
}