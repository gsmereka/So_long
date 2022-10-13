/* ************************************************************************** */
/*						                                        */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:52:03 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/11 13:52:21 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clang 8_new_image.c  -lX11 -lXext -lmlx && ./a.out
// make && make clean && clang so_long.a -lX11 -lXext
// -lmlx && clear && ./a.out && clear
// prototipo da função que cria imagens:
// void	*mlx_new_image(void *mlx_ptr,int width,int height);

#ifndef DATA_H
# define DATA_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include "./objects.h"
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define MLX_ERROR 1
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0x00FF00
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x000000
# define NAVY_BLUE 0x00005F
# define PURPLE 0x800080
# define GREEN_YELLOW 0xAFFF00

// set_oppening
void	ft_set_oppening(t_data *game, t_config *config);
void	ft_set_config(t_config *config);
void	ft_set_memory(t_data *game, t_config *config);
void	ft_set_variables(t_data *game, t_config *config);

// set_file
void	ft_set_file(int argc, char *addr, t_data *game);

// set_map
void	ft_set_map(t_data *game);

// set_map_tools
int		ft_check_walls(t_data *game);
int		ft_check_composition(t_data *game);
int		ft_check_path(t_data *game);

// set_path_check
int		ft_set_path_check(t_data *game, t_check *valid_path);

// set_path_check_tools
void	find_player(t_check *valid_path, t_data *game);
void	copy_grid(t_check *valid_path, t_data *game);
void	set_check_variables(t_check *valid_path, t_data *game);
void	free_grid(t_check *valid_path);

// set_objects
void	ft_set_objects(t_data *game);

// set_mlx
void	ft_set_mlx(t_data *game);

// set_commands
int		ft_set_commands(int keysym, t_data *game);

// set_images
int		ft_set_images(t_data *game);

// set_images_tolls
void	ft_pixel_put(t_img *img, int x, int y, int color);
int		draw_object(t_img *img, t_rect *rect);
void	pintar_fundo(t_data *game);

// utils
char	*get_next_line(int fd, int stop);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s);

// utils_2
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// set_shutdown
int		close_window(t_data *game);
void	ft_set_shutdown(int close_window, t_data *game, char *error_msg);
void	ft_finish_game(int close_window, t_data *game);
void	ft_free_map(t_map *map);

#endif