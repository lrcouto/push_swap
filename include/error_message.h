/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:20:06 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/26 23:06:03 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGE_H
# define ERROR_MESSAGE_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>

/*
** ERROR MESSAGE MACROS:
*/

# define NOT_DIGIT "ERROR: Input contains symbols that are not digits."

# define INPUT_TOO_HIGH "ERROR: Argument higher than the int limit."

# define INPUT_TOO_LOW "ERROR: Argument lower than the int limit."

# define DUPLICATE_INPUT "ERROR: Input contains duplicate arguments."

/*
** ERROR HANDLING FUNCTIONS:
*/

void	exit_with_error(char *error_message);
void	check_for_errors(char **argv);

#endif