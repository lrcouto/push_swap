/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:04:22 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/12 01:13:23 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	arg_string_to_int(char *current_arg)
{
	long long int	current_number;

	current_number = ft_atoll(current_arg);
	if (current_number > INT_MAX)
		exit_with_error(INPUT_TOO_HIGH);
	else if (current_number < INT_MIN)
		exit_with_error(INPUT_TOO_LOW);
	return ((int)current_number);
}

static void	read_and_store_input(char **argv)
{
	int	i;
	int	current_number;

	i = 1;
	check_for_duplicates(argv);
	ft_putendl_fd("Here is your input:", 1);
	while (argv[i] != NULL)
	{
		is_arg_digits(argv[i]);
		current_number = arg_string_to_int(argv[i]);
		ft_putnbr_fd(current_number, 1);
		write(1, "\n", 1);
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
