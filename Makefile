# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 23:33:38 by root              #+#    #+#              #
#    Updated: 2022/05/18 02:12:27 by dantremb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# Fichiers sources.
SRCS_FILES = ft_printf.c ft_printf_utils.c

# Ajoute le noms du dossier en avant de chaque sources.
SRCS_PATH = srcs/
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

# Compilateurs
AR = ar
CC = gcc

# Flags
ARFLAGS = rcs
CFLAGS = -Wall -Wextra -Werror -g

# Macros
REMOVE = rm -rf
COMMIT = $(shell date "+%d %B %T")

# Transforme les fichiers .c en fichiers .o
# La premiere utilise le contenu de la 2e pour compiler.
# J'imprime un tiret (sans newline) pour créer ma ligne de progression.
OBJS= $(SRCS:%.c=%.o)
%.o: %.c
	@printf "-"
	@$(CC) $(CFLAGS) -c -o $@ $<
	
# On appel la commande INIT et NAME puis on imprime le message final.
all: init $(NAME)
	@echo "> Done!."
	@echo "$(NAME) Compiled!"

# On imprime le début de la compilation à l'écran (sans newline).
init:
	@printf "Compiling -"

# On appel la création des OBJS et ensuite on compile la librairie.
$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

# Commande de nettoyage.
clean:
	@$(REMOVE) $(OBJS)
fclean: clean
	@$(REMOVE) $(NAME)

# On nettoie et recompile.
re:	fclean all

# On peut choisir le nom de commit avec "make git COMMIT="
git:
	git add .
	git commit -m "$(COMMIT)"
	git push

# Test le programme avec mon main.c
test:
	@clear
	@$(CC) $(CFLAGS) main.c $(SRCS)
	@(./out)
	@$(REMOVE) $(OBJS)
	@$(REMOVE) ./out