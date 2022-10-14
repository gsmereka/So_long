# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 22:11:38 by lbiasuz           #+#    #+#              #
#    Updated: 2022/10/13 12:34:09 by gsmereka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long.a

CFLAGS	=	-Wall -Wextra -Werror

SRC		=	./src/so_long.c ./src/set_commands.c ./src/set_images.c ./src/set_images_tools.c \
			./src/set_objects.c ./src/set_map_file.c ./utils/get_next_line.c ./src/set_mlx.c \
			./utils/utils.c ./utils/utils_2.c ./src/set_map.c ./src/set_map_tools.c  ./src/set_shutdown.c \
			./src/set_oppening.c ./src/set_path_check.c ./src/set_path_check_tools.c

HEADER	=	./header/data.h

OBJ		=	$(SRC:.c=.o)

all: $(NAME)

.c.o: $(HEADER)
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re
