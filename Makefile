# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 22:11:38 by lbiasuz           #+#    #+#              #
#    Updated: 2022/12/25 04:05:08 by gsmereka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CFLAGS		=	-Wall -Wextra -Werror

MLX_FLAGS	=	-lmlx -lXext -lX11

OBJ_DIR		=	./obj

SRC_DIR		=	src

UTILS_DIR	=	utils

HEADER		=	./header/so_long.h

SRC			=	so_long.c set_commands.c set_images.c set_sprites.c \
				set_map_file.c set_mlx.c \
				set_map_tools.c  set_shutdown.c set_map.c \
				set_oppening.c set_path_check.c set_path_check_tools.c set_images_tools.c \
				set_shutdown_tools.c set_objects_image.c set_values.c set_steps_to_char.c\
				set_enemies_move.c set_enemies.c set_animations.c

UTILS		=	utils.c utils_2.c get_next_line.c

OBJ_SRC		=	$(addprefix $(OBJ_DIR)/, $(addprefix $(SRC_DIR)/, $(SRC:.c=.o)))

OBJ_UTILS	=	$(addprefix $(OBJ_DIR)/, $(addprefix $(UTILS_DIR)/, $(UTILS:.c=.o)))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/$(SRC_DIR) $(OBJ_DIR)/$(UTILS_DIR)
	cc $(CFLAGS) -c $< -o $@ $(MLX_FLAGS)

$(NAME): $(HEADER) $(OBJ_SRC) $(OBJ_UTILS)
	cc $(CFLAGS) -o $(NAME) $(OBJ_SRC) $(OBJ_UTILS) $(MLX_FLAGS)

clean:
	rm -rf $(OBJ_SRC) $(OBJ_UTILS) $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re
