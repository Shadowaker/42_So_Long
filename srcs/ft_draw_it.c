/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:39:46 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/05 19:54:44 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

void	my_mlx_pixel_put(t_dic *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*) dst = color;
}

t_dic	draw_image(void *mlx, void *mlx_win, int *arr, char *path)
{
	int		i;
	int		j;
	int		img_width;
	int		img_height;
	t_dic	win_img;

	i = arr[0];
	j = arr[1];
	win_img.img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	win_img.addr = mlx_get_data_addr(win_img.img, &win_img.bpp, &win_img.line_len, &win_img.endian);
	mlx_put_image_to_window(mlx, mlx_win, win_img.img, j * 32, i * 32);

	return (win_img);
}

t_dic	Load_Img(void *mlx, char *path)
{
	int		img_width;
	int		img_height;
	t_dic	win_img;

	win_img.img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	win_img.addr = mlx_get_data_addr(win_img.img, &win_img.bpp, &win_img.line_len, &win_img.endian);

	return (win_img);
}

t_cont	Load_Imgs(void *mlx)
{
	t_cont	imgs;

	imgs.player = Load_Img(mlx, "sprites/Player_32.xpm");
	imgs.coin = Load_Img(mlx, "sprites/Coin_32.xpm");
	// Enemy
	// Exit
	imgs.background = Load_Img(mlx, "sprites/Background_32.xpm");
}

