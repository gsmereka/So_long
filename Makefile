# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 22:11:38 by lbiasuz           #+#    #+#              #
#    Updated: 2022/12/25 03:56:03 by gsmereka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CFLAGS		=	-Wall -Wextra -Werror

MLX_FLAGS	=	-lmlx -lXext -lX11

OBJ_DIR		=	./obj

SRC_DIR		=	src_bonus

UTILS_DIR	=	utils_bonus

HEADER		=	./header_bonus/so_long_bonus.h

SRC			=	so_long_bonus.c set_commands_bonus.c set_images_bonus.c set_sprites_bonus.c \
				set_map_file_bonus.c set_mlx_bonus.c \
				set_map_tools_bonus.c  set_shutdown_bonus.c set_map_bonus.c \
				set_oppening_bonus.c set_path_check_bonus.c set_path_check_tools_bonus.c set_images_tools_bonus.c \
				set_shutdown_tools_bonus.c set_objects_image_bonus.c set_values_bonus.c set_steps_to_char_bonus.c\
				set_enemies_move_bonus.c set_enemies_bonus.c set_animations_bonus.c

UTILS		=	utils_bonus.c utils_2_bonus.c get_next_line_bonus.c

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
