# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 00:46:31 by lcouto            #+#    #+#              #
#    Updated: 2021/06/06 00:47:12 by lcouto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADERS = include

DIR_SRCS = srcs

DIR_OBJS = objs

SRC = $(wildcard $(DIR_SRCS)/*.c)

OBJS = $(subst $(DIR_SRCS),$(DIR_OBJS),$(SRC:.c=.o))

CC	= clang

RM	= rm -rf

CFLAGS	= -Wall -Wextra -Werror -g3 -I $(HEADERS)

LIBFT = libft

FLAGS = -L $(LIBFT) -lft

ifeq ($(SANITIZE_A),true)
	CFLAGS += -fsanitize=address -fno-omit-frame-pointer
endif

ifeq ($(SANITIZE_L),true)
	CFLAGS += -fsanitize=leak -fno-omit-frame-pointer
endif

$(NAME): $(OBJS)
		@make -C $(LIBFT)
		-$(CC) $(CFLAGS) $(OBJS) $(FLAGS) $(HEADER) -o $(NAME)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
		@mkdir -p objs
		@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@
		@echo "Compiled "$<" successfully!"

all: $(NAME)

clean:
		make clean -C $(LIBFT)
		$(RM) $(OBJS)
		$(RM) $(DIR_OBJS)

fclean:	clean
		make fclean -C $(LIBFT)
		$(RM) $(NAME)
		$(RM) $(DIR_OBJS)

re:		fclean all

PHONY:	all clean fclean re