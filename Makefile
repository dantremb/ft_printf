# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 23:33:38 by root              #+#    #+#              #
#    Updated: 2022/05/12 00:54:12 by dantremb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PRINT_NAME = libftprintf

SRCS_FILES = ft_printf.c ft_printf_utils.c

SRCS_PATH = srcs/

OBJS= $(SRCS:%.c=%.o)

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

AR = ar

ARFLAGS = rcs

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

REMOVE = rm -rf

COMMIT = $(shell date "+%d %B %T")

all: init $(NAME)
	@echo "> Done!.\n"
	@echo "$(PRINT_NAME) Compiled!"
	
init:
	@printf "Compiling -"
	
%.o: %.c
	@printf "-"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) -o $@ $^

clean:
	@$(REMOVE) $(OBJS)

fclean: clean
	@$(REMOVE) $(NAME)

re:	fclean all

git:
	git add *
	git commit -m "$(COMMIT)"
	git push
	
test:
	@clear
	@$(CC) $(CFLAGS) -o $(PRINT_NAME) main.c $(SRCS)
	@(./$(PRINT_NAME))
	@$(REMOVE) $(OBJS)
	@$(REMOVE) $(PRINT_NAME)