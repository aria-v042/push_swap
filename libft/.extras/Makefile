# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frodrig2 <frodrig2@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/20 21:45:22 by frodrig2          #+#    #+#              #
#    Updated: 2026/05/22 02:06:03 by frodrig2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../libft.a

CC = cc
CFLAGS = -Wall -Wextra
INCLUDES = -I..

TEST = test.c
T_OUT = runtests
DEBUG ?= $(or $(filter %.c, $(MAKECMDGOALS)), $(TEST))
D_OUT = debug

PRINTF_TEST = ft_printf_test.c
PRINTF_T_OUT = test_ft_printf

ifneq ($(filter %.c, $(MAKECMDGOALS)),)
%.c: ;
endif

all: $(NAME)

$(NAME):
	$(MAKE) -C ..

bonus: all

test: all
	$(CC) $(CFLAGS) $(INCLUDES) -g $(TEST) $(NAME) -o $(T_OUT)
	$(MAKE) fclean

debug: all
	$(CC) $(CFLAGS) $(INCLUDES) -g $(DEBUG) $(NAME) -o $(D_OUT)
	$(MAKE) fclean

ft_printf_test: all
	$(CC) $(CFLAGS) $(INCLUDES) -g $(PRINTF_TEST) $(NAME) -o $(PRINTF_T_OUT)
	$(MAKE) fclean

clean:
	$(MAKE) clean -C ..

fclean: clean
	$(MAKE) fclean -C ..

tclean: fclean
	rm -f $(T_OUT)

dclean: fclean
	rm -f $(D_OUT)

pclean: fclean
	rm -f $(PRINTF_T_OUT)

re: fclean all

.PHONY: all bonus clean fclean re test debug ft_printf_test tclean dclean pclean
