/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:20:06 by lcouto            #+#    #+#             */
/*   Updated: 2021/06/06 18:45:49 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGE_H
# define ERROR_MESSAGE_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>

/*
** ERROR MESSAGE MACROS:
*/

# define NO_INPUT "This program expects a series of integers as an argument."

/*
** ERROR HANDLING FUNCTIONS:
*/

void	exit_with_error(char *error_message);

#endif