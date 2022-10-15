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

// set_oppening
void	ft_set_oppening(t_data *game, t_config *config);

// set_values
void	ft_set_values(t_data *game, t_config *config);

// set_file
void	ft_set_map_file(int argc, char *addr, t_data *game);

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

// set_sprites
void	ft_set_sprites(t_data *game);

// set_mlx
void	ft_set_mlx(t_data *game);

// set_objects_image
void	set_objects_image(t_data *game);

// set_commands
int		ft_set_commands(int keysym, t_data *game);

// set_images
int		ft_set_images(t_data *game);

// set_images_tolls
void	ft_draw_floor(int y, int x, t_data *game);
void	ft_draw_wall(int y, int x, t_data *game);
void	ft_draw_colect(int y, int x, t_data *game);
void	ft_draw_exit(int y, int x, t_data *game);
void	ft_draw_player(int y, int x, t_data *game);

// utils
char	*get_next_line(int fd, int stop);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// utils_2
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

// set_shutdown
void	ft_set_shutdown(int close_window, t_data *game, char *error_msg);
void	ft_finish_game(int close_window, t_data *game);
void	free_structures(t_data *game);

// set_shutdown_tools
void	ft_free_grid(t_map *map);
int		close_window(t_data *game);
void	free_images(t_sprites *sprites);

#endif