/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:20:06 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/12 00:57:48 by lcouto           ###   ########.fr       */
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

# define NOT_DIGIT "Input contains symbols that are not digits."

# define INPUT_TOO_HIGH "One of your arguments is higher than the int limit."

# define INPUT_TOO_LOW "One of your arguments is lower than the int limit."

# define DUPLICATE_INPUT "Input contains duplicate arguments."

/*
** ERROR HANDLING FUNCTIONS:
*/

void	exit_with_error(char *error_message);
void	check_for_duplicates(char **argv);
void	is_arg_digits(char *current_arg);

#endif