# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 22:11:38 by lbiasuz           #+#    #+#              #
#    Updated: 2022/10/21 02:25:04 by gsmereka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

NAME_B	=	so_long_bonus

CFLAGS	=	-Wall -Wextra -Werror

SRC		=	./src/so_long.c ./src/set_commands.c ./src/set_images.c ./src/set_sprites.c \
			./src/set_objects.c ./src/set_map_file.c ./utils/get_next_line.c ./src/set_mlx.c \
			./utils/utils.c ./utils/utils_2.c ./src/set_map.c ./src/set_map_tools.c  ./src/set_shutdown.c \
			./src/set_oppening.c ./src/set_path_check.c ./src/set_path_check_tools.c ./src/set_images_tools.c \
			./src/set_shutdown_tools.c ./src/set_objects_image.c ./src/set_values.c

SRC_B	=	./src_bonus/so_long_bonus.c ./src_bonus/set_commands_bonus.c ./src_bonus/set_images_bonus.c ./src_bonus/set_sprites_bonus.c \
			./src_bonus/set_objects_bonus.c ./src_bonus/set_map_file_bonus.c ./utils_bonus/get_next_line_bonus.c ./src_bonus/set_mlx_bonus.c \
			./utils_bonus/utils_bonus.c ./utils_bonus/utils_2_bonus.c ./src_bonus/set_map_bonus.c ./src_bonus/set_map_tools_bonus.c  ./src_bonus/set_shutdown_bonus.c \
			./src_bonus/set_oppening_bonus.c ./src_bonus/set_path_check_bonus.c ./src_bonus/set_path_check_tools_bonus.c ./src_bonus/set_images_tools_bonus.c \
			./src_bonus/set_shutdown_tools_bonus.c ./src_bonus/set_objects_image_bonus.c ./src_bonus/set_values_bonus.c ./src_bonus/set_steps_to_char_bonus.c\
			./src_bonus/set_enemies_move_bonus.c ./src_bonus/set_enemies_bonus.c ./src_bonus/set_animations_bonus.c

HEADER		=	./header/so_long.h

HEADER_B	=	./header_bonus/so_long_bonus.h

OBJ		=	$(SRC:.c=.o)

OBJ_B	=	$(SRC_B:.c=.o)

all: $(NAME)

bonus: $(NAME_B)

.c.o: $(HEADER)
	cc $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJ)
	cc $(CFLAGS) -o $(NAME) $(OBJ) -lmlx -lXext -lX11

$(NAME_B): $(OBJ_B)
	cc $(CFLAGS) -o $(NAME_B) $(OBJ_B) -lmlx -lXext -lX11

clean:
	rm -f $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re: fclean all

.PHONY: bonus all clean fclean re
