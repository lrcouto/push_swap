/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:24:57 by lcouto            #+#    #+#             */
/*   Updated: 2021/06/06 18:51:31 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exit_with_error(char *error_message)
{
	ft_putstr_fd(BOLD_RED, 1);
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd(RED, 1);
	ft_putendl_fd(error_message, 2);
	ft_putstr_fd(RESET_COLOR, 1);
	exit(errno);
}
