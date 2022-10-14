/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:00:57 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/11 16:32:15 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_rect
{
	int	x;
	int	y;
	int	largura;
	int	altura;
	int	cor;
	int	speed;
	int	moves;
}	t_rect;

typedef struct s_objects
{
	char	start;
	char	wall;
	char	empty;
	char	colect;
	char	exit;
	int		max_player;
	int		max_collectable;
	int		max_exit;
}t_objects;

typedef struct s_map
{
	int			col;
	int			lin;
	int			max_lines;
	int			max_cols;
	char		*addr;
	char		**grid;
	int			fd;
	t_objects	*objects;
}t_map;

typedef struct s_window
{
	void		*ptr_mlx;
	void		*ptr_win;
	int			width;
	int			height;
}t_window;

typedef struct s_sprites
{
	char	*addr;
	void	*img;
	int		x;
	int		y;
}t_sprites;

typedef struct s_data
{
	t_window	*win;
	t_img		*img;
	t_map		*map;
	t_sprites	*floor;
	t_rect		*player;
	t_rect		*wall;
	t_rect		*coin;
	t_rect		*exit;
}	t_data;

typedef struct s_config
{
	int		width;
	int		height;
	int		start;
	int		wall;
	int		empty;
	int		colect;
	int		exit;
	int		max_lines;
	int		max_cols;
	char	*map_addr;
}t_config;

typedef struct s_check
{
	int		player_x;
	int		player_y;
	int		max_lines;
	int		max_cols;
	int		lines;
	int		cols;
	int		coins;
	int		start;
	int		exit;
	char	**grid;
}t_check;
#endif