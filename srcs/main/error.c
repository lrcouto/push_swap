/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:24:57 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/26 23:09:10 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_int_limit(char *current_arg)
{
	long long int	current_number;

	current_number = ft_atoll(current_arg);
	if (current_number > INT_MAX)
		exit_with_error(INPUT_TOO_HIGH);
	else if (current_number < INT_MIN)
		exit_with_error(INPUT_TOO_LOW);
}

static void	check_for_digits(char *current_arg)
{
	int	i;

	i = 0;
	if (current_arg[0] == '-' || current_arg[0] == '+')
		i = 1;
	while (current_arg[i])
	{
		if (ft_isdigit((int)current_arg[i]) == 0)
			exit_with_error(NOT_DIGIT);
		i++;
	}
}

void	check_for_errors(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 1;
		while (argv[j] != NULL)
		{
			if (i != j && ft_strncmp(argv[i], argv[j], sizeof(argv[i])) == 0)
				exit_with_error(DUPLICATE_INPUT);
			j++;
		}
		check_for_digits(argv[i]);
		check_int_limit(argv[i]);
		i++;
	}
}

void	exit_with_error(char *error_message)
{
	int	fd;

	fd = open("ERROR_LOG.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	ft_putendl_fd(error_message, fd);
	ft_putendl_fd("Error", 2);
	close(fd);
	exit(-1);
}
