/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:24:57 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/12 00:58:56 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	is_arg_digits(char *current_arg)
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

void	check_for_duplicates(char **argv)
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
		i++;
	}
}

void	exit_with_error(char *error_message)
{
	ft_putstr_fd(BOLD_RED, 1);
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd(RED, 1);
	ft_putendl_fd(error_message, 2);
	ft_putstr_fd(RESET_COLOR, 1);
	exit(errno);
}
