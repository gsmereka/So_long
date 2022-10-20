/* ************************************************************************** */
/*										                        */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:52:03 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/11 13:52:21 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <time.h>
# include <stdlib.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include "./objects_bonus.h"
// set_oppening
void	set_oppening(t_data *game, t_config *config);
// set_values
void	set_values(t_data *game, t_config *config);
// set_file
void	set_map_file(int argc, char *addr, t_data *game);
// set_map
void	set_map(t_data *game);
// set_map_tools
int		check_walls(t_data *game);
int		check_composition(t_data *game);
int		check_path(t_data *game);
// set_path_check
int		set_path_check(t_data *game, t_check *valid_path);
// set_path_check_tools
void	find_player(t_check *valid_path, t_data *game);
void	copy_grid(t_check *valid_path, t_data *game);
void	set_check_variables(t_check *valid_path, t_data *game);
void	free_check_grid(t_check *valid_path);
// set_objects
void	set_objects(t_data *game);
// set_sprites
void	set_sprites(t_data *game);
// set_mlx
void	set_mlx(t_data *game);
// set_objects_image
void	set_objects_image(t_data *game);
// set_commands
int		set_commands(int keysym, t_data *game);
// set_enemies
void	set_enemies(t_data *game);
// set_enemies_move
void	set_enemies_move(t_data *game, int time);
// set_steps_to_char
void	set_steps_to_char(t_data *game);
// set_animations
int		set_animations(t_data *game);
// set_images
int		set_images(t_data *game);
// set_images_tolls
void	draw_sprite(int y, int x, t_sprites *sprite, t_window *win);
void	draw_player(int y, int x, t_data *game);
void	draw(int i, int j, t_data *game, char object);
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
void	set_shutdown(int close_window, t_data *game, char *error_msg);
void	finish_game(int close_window, t_data *game);
void	free_structures(int close_window, t_data *game);
// set_shutdown_tools
int		close_window(t_data *game);
void	free_images(t_sprites *sprites);
void	destroy_images(t_sprites *sprite, t_data *game);

#endif