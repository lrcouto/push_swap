/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:04:22 by lcouto            #+#    #+#             */
/*   Updated: 2021/06/06 01:22:41 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** TODO: Write an actual error handler. Tomorrow, perhaps.
*/

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putendl_fd("This program expect a list of integers as input.", 1);
		exit(0);
	}
	ft_putendl_fd("Here is your input:", 1);
	while (argc >= 1)
	{
		ft_putendl_fd(*argv, 1);
		argv++;
		argc--;
	}
	return (0);
}