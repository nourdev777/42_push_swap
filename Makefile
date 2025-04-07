# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 19:05:58 by numussan          #+#    #+#              #
#    Updated: 2022/11/09 01:55:23 by numussan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap

SRCS 		= push_swap.c parsing.c parsing2.c actions_swap_push.c \
				actions_rotates.c actions_revrotates.c operations.c \
				operations2.c little_sort.c little_sort2.c \
				big_sort.c big_sort2.c transfer_to_stack_a.c transfer_to_stack_a2.c

OBJS		= $(SRCS:.c=.o)

CCF			= gcc -Wall -Wextra -Werror -g

MAKELIBFT	= cd libft && make
MAKEPRINTF	= cd ft_printf && make

LIBFT		= libft/libft.a
PRINTF		= ft_printf/libftprintf.a

RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKELIBFT)
	@$(MAKEPRINTF)
	@$(CCF) -o $(NAME) $(SRCS) $(LIBFT) $(PRINTF)

%.o : %.c so_long.h
	@$(CCF) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@$(MAKELIBFT) clean
	@$(MAKEPRINTF) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKELIBFT) fclean
	@$(MAKEPRINTF) fclean

re: fclean all

.PHONY: all clean fclean re libft ft_printf