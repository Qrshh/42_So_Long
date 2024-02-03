# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 01:14:40 by abesneux          #+#    #+#              #
#    Updated: 2024/02/03 01:41:21 by abesneux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long
INCLUDES    = includes/
SRC_DIR     = src/
OBJ_DIR     = obj/

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g -g3
PRFLAGS     = -ldl -lglfw -pthread -lm
RM          = rm -rf

LIBFT_DIR    = $(INCLUDES)Libft/
LIBFT        = $(LIBFT_DIR)libft.a
LIBFT_CFLAGS = -fPIC

MLX_DIR = $(INCLUDES)MLX42/
MLX 	= $(MLX_DIR)build/libmlx42.a $(PRFLAGS)

MAP_DIR  = map/
MAP      = init_map utils_map

# PARSING_DIR = player/
# PARSING     = 

SRC_FILES  += main utils
SRC_FILES  += $(addprefix $(MAP_DIR), $(MAP))
# SRC_FILES  += $(addprefix $(PLAYER_DIR), $(PLAYER))

SRC         = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ         = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJ_CACHE   = .cache_exists

###

all: 			 $(MLX) $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) CFLAGS+=$(LIBFT_CFLAGS)

$(MLX):
	@make -C $(MLX_DIR)/build

$(NAME): 		$(OBJ)
					$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)
					@echo "\033[0;32m$(shell echo $(NAME) | tr '[:lower:]' '[:upper:]') : COMPILED\033[0m"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_CACHE)
					@echo "Compiling $<"
					@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(OBJ_CACHE):
					@mkdir -p $(OBJ_DIR)
					@mkdir -p $(OBJ_DIR)$(MAP_DIR)
# @mkdir -p $(OBJ_DIR)$(PLAYER_DIR)

clean:
					@make clean -C $(LIBFT_DIR)
					$(RM) $(OBJ_DIR)
					$(RM) $(OBJ_CACHE)
					@echo "so_long and libs object files cleaned!"

fclean: 		clean
					@make fclean -C $(LIBFT_DIR)
					$(RM) $(NAME)
					@echo "so_long and libs executable files cleaned!"

re: 			fclean all
					@echo "Cleaned and rebuilt everything for so_long!"

.PHONY:			all clean fclean re

.SILENT: