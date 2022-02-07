/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:39:46 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/07 20:20:12 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

void	my_mlx_pixel_put(t_dic *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *) dst = color;
}

void	draw_image(t_mlx *game, t_dic img, int *arr)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		img.img, arr[1] * W, arr[0] * H);
}

t_dic	load_img(void *mlx, char *path)
{
	int		img_width;
	int		img_height;
	t_dic	win_img;

	win_img.img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	win_img.addr = mlx_get_data_addr(win_img.img, &win_img.bpp,
			&win_img.line_len, &win_img.endian);
	return (win_img);
}

t_cont	load_imgs(void *mlx)
{
	t_cont	imgs;

	imgs.player = load_img(mlx, "sprites/64px/Player/Player_0.xpm");
	imgs.coin = load_img(mlx, "sprites/64px/Coin/Coin_0.xpm");
	imgs.wall = load_img(mlx, "sprites/64px/Wall/Wall.xpm");
	imgs.enemy = load_img(mlx, "sprites/64px/Enemy/Enemy_0.xpm");
	imgs.exit = load_img(mlx, "sprites/64px/Exit/Exit.xpm");
	imgs.background = load_img(mlx, "sprites/64px/Background/Background.xpm");
	return (imgs);
}
