# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaly <omaly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 17:18:58 by omaly             #+#    #+#              #
#    Updated: 2025/10/08 17:30:23 by omaly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Name
NAME = pipex
NAME_LIBFT = libft.a

# Compilation and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Commands
RM = rm -rf

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft

# Source files
SRC_FILES = $(SRC_DIR)/pipex.c

# Object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: $(NAME)

$(NAME): $(OBJ_FILES) $(NAME_LIBFT)
	$(CC) $(CFLAGS) $(OBJ_FILES) -L$(LIBFT_DIR) -lft -o $(NAME)

$(NAME_LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) bonus -C $(LIBFT_DIR)

# Create object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c|$(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_FILES) $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY = NAME all clean fclean
