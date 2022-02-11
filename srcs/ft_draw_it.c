/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:39:46 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/11 12:40:25 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

void	draw_image(t_mlx *game, t_dic img, int *arr)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		img.img, arr[1] * W, arr[0] * H);
}

void	draw_image2(t_mlx *game, t_dic img, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		img.img, j * W, i * H);
}

void	draw_string(t_mlx *game, int *arr, char *s, int offset)
{
	mlx_string_put(game->mlx, game->mlx_win, arr[1] * W,
		(arr[0] * H) + offset, TEXT_COLOR, s);
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

	imgs.player = load_img(mlx, "sprites/64px/Player/Player.xpm");
	imgs.player1 = load_img(mlx, "sprites/64px/Player/Player_1.xpm");
	imgs.player2 = load_img(mlx, "sprites/64px/Player/Player_2.xpm");
	imgs.coin = load_img(mlx, "sprites/64px/Coin/Coin.xpm");
	imgs.coin1 = load_img(mlx, "sprites/64px/Coin/Coin_1.xpm");
	imgs.coin2 = load_img(mlx, "sprites/64px/Coin/Coin_2.xpm");
	imgs.wall = load_img(mlx, "sprites/64px/Wall/Wall.xpm");
	imgs.enemy = load_img(mlx, "sprites/64px/Enemy/Enemy.xpm");
	imgs.enemy1 = load_img(mlx, "sprites/64px/Enemy/Enemy_1.xpm");
	imgs.enemy2 = load_img(mlx, "sprites/64px/Enemy/Enemy_2.xpm");
	imgs.exit = load_img(mlx, "sprites/64px/Exit/Exit.xpm");
	imgs.background = load_img(mlx, "sprites/64px/Background/Background.xpm");
	imgs.background2 = load_img(mlx, "sprites/64px/Background/Background2.xpm");
	return (imgs);
}
