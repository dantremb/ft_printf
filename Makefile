# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 23:33:38 by root              #+#    #+#              #
#    Updated: 2022/04/28 13:04:21 by dantremb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printf_utils.c
		
OBJ = $(SRCS:%c=%o)

NAME = libftprintf.a

AR = ar

ARFLAGs = rcs

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

REMOVE = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
		
git:
	@(git add .)
	@(git commit -m "dantremb")
	@(git push)
	
test:
	clear
	@(gcc -Wall -Wextra -Werror main.c ft_printf.c ft_printf_utils.c)
	@(./a.out)
	@(rm -f *.out)
	@(rm -f *.o)

clean:
	$(REMOVE) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(REMOVE) $(NAME)

re:	fclean all
