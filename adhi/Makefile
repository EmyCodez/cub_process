# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 15:31:19 by esimpson          #+#    #+#              #
#    Updated: 2024/10/24 13:26:16 by esimpson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 

LIBFT = ./library/libft/libft.a
GNL = ./library/get_next_line/get_next_line.a
PRINTF = ./library/libftprintf/libftprintf.a

SRC_PATH = ./src
PARSE_PATH = ./src/parsing
EXEC_PATH = ./src/execution

SRC_FILES = $(SRC_PATH)/main.c \
			$(PARSE_PATH)/parse.c $(PARSE_PATH)/extension_check.c $(PARSE_PATH)/struct_init.c \
            $(PARSE_PATH)/texture_validator.c $(PARSE_PATH)/texture_validator2.c $(PARSE_PATH)/dfs.c \
			$(PARSE_PATH)/color_validator.c $(PARSE_PATH)/map_validator.c $(PARSE_PATH)/map_checks.c \
			
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT) $(GNL) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME) $(LIBFT) $(GNL) $(PRINTF)

$(LIBFT):
	@make -C ./library/libft

$(GNL):
	@make -C ./library/get_next_line

$(PRINTF):
	@make -C ./library/libftprintf

clean:
	@make -C ./library/libft clean
	@make -C ./library/get_next_line clean
	@make -C ./library/libftprintf clean
	@rm -f $(OBJ_FILES)

fclean: clean
	@make -C ./library/libft fclean
	@make -C ./library/get_next_line fclean
	@make -C ./library/libftprintf fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re