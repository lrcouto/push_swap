/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:04:22 by lcouto            #+#    #+#             */
/*   Updated: 2021/06/07 02:29:31 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** TODO: Write functions to validade int input, convert string to int.
*/

static void	read_and_store_input(char **argv)
{
	int	i;

	i = 1;
	ft_putendl_fd("Here is your input:", 1);
	while (argv[i] != NULL)
	{
		//is_valid_int(argv[i]);
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
