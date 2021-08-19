# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 00:46:31 by lcouto            #+#    #+#              #
#    Updated: 2021/08/18 18:55:18 by lcouto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

INCLUDES	= -I include -I $(LIBFT_DIR)/includes/

LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_DIR	= libft
LFT_FLAGS	= -L $(LIBFT_DIR) -lft

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g
RM			= /bin/rm -f

DIR_SRCS	= srcs
DIR_OBJS	= objs
SUBDIRS		= main stack

SRCS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
OBJS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_OBJS)/, $(dir)))
SRCS		= $(foreach dir, $(SRCS_DIRS), $(wildcard $(dir)/*.c))
OBJS		= $(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

ifeq ($(SANITIZE_A),true)
	CFLAGS += -fsanitize=address -fno-omit-frame-pointer
endif

ifeq ($(SANITIZE_L),true)
	CFLAGS += -fsanitize=leak -fno-omit-frame-pointer
endif

$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.c
			@mkdir -p $(DIR_OBJS) $(OBJS_DIRS)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
			@echo "Compiled "$<" successfully!"

all:		$(NAME)

$(LIBFT):
			@make --no-print-directory -C $(LIBFT_DIR)

$(NAME):	$(OBJS) $(LIBFT)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS) $(LFT_FLAGS)
			@echo "created push_swap executable file successfully!"

clean:
			@make clean --no-print-directory -C $(LIBFT_DIR)
			@$(RM) $(OBJS)
			@$(RM) -r $(DIR_OBJS)
			@echo "Cleanup completed!"

fclean:		clean
			@make fclean --no-print-directory -C $(LIBFT_DIR)
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re