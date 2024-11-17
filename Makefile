# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgrasser <cgrasser@student.42perpignan.fr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 08:17:14 by cgrasser          #+#    #+#              #
#    Updated: 2024/11/17 13:12:08 by cgrasser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

SRC = src/ft_printf.c \
	  src/handle_char.c \
	  src/handle_string.c \
	  src/handle_pointer.c \
	  src/handle_integer.c \
	  src/handle_unsigned_int.c \
	  src/handle_hexadecimal.c \
	  src/handle_flags_one.c \
	  src/ft_flags.c

OBJ_DIR = obj
OBJS = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -c $< -o $@

bonus: all

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft

