/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:48:10 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/12 18:26:34 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/data.h"

int	draw_object(t_img *img, t_rect *rect)
{
	int	i;
	int	j;

	i = rect->y;
	while (i < rect->y + rect->altura)
	{
		j = rect->x;
		while (j < rect->x + rect->largura)
			ft_pixel_put(img, j++, i, rect->cor);
		++i;
	}
	return (0);
}

void	pintar_fundo(t_data *game)
{
	int				i;
	int				j;
	int				save;
	int				color_div;
	unsigned char	blue;
	unsigned char	red;

	i = 0;
	save = 128;
	blue = save;
	red = save;
	color_div = (game->win->width / save) + 1;
	while (i < game->win->height)
	{
		j = 0;
		while (j < game->win->width)
		{
			ft_pixel_put(game->img, j++, i,
				*(int *)(unsigned char [4]){blue, 0, red});
			if (j % color_div == 0)
			{
				red--;
				blue--;
			}
		}
		red = save;
		blue = save;
		++i;
	}
}

void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + ((y * img->line_len) + (x * (img->bpp / 8)));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
