# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdescour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 22:06:39 by cdescour          #+#    #+#              #
#    Updated: 2022/10/07 17:29:12 by cdescour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary
NAME = push_swap
LIBFT = libft

# Path
SRC_PATH = ./sources/
OBJ_PATH = ./objets/
CPPFLAGS = -I./includes/

# Name
SRC_NAME =	push_swap.c		\
			memory.c		\
			check_args.c	\
			get_rank.c		\
			check.c			\
			set_value.c		\
			sort.c			\
			sort_tall.c		\
			instructions.c	\
			free.c			\
			error.c			\

OBJ_NAME = $(SRC_NAME:.c=.o)

# Files
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# Flags
LDFLAGS = -L./libft/
LFT = -lft
CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

# Rules

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[34mCreation of $(LIBFT) ...\033[0m"
	@make -C./libft/
	@echo "\033[32m$(LIBFT) created\033[0m"
	@echo "\033[34mCreation of $(NAME) ...\033[0m"
	@$(CC) $(LDFLAGS) $(LFT) $(OBJ) -o $@
	@echo "\033[32m$(NAME) created\n\033[0m"
	@echo "\033[33mEND: everything is complete.\033[0m"


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	@make clean -C ./libft/
	@echo "\033[33mRemoval of .o files of $(NAME) ...\033[0m"
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[31mFiles .o deleted\n\033[0m"
	
fclean: clean
	@make fclean -C ./libft/
	@echo "\033[33mRemoval of $(NAME)...\033[0m"
	@rm -f $(NAME)
	@echo "\033[31mBinary $(NAME) deleted\n\033[0m"

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY: all, clean, fclean, re
