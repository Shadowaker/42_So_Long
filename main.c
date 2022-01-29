/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:35:40 by dridolfo          #+#    #+#             */
/*   Updated: 2022/01/29 20:08:23 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/lib.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*) dst = color;
}

t_data	draw_cross(void *mlx, void *mlx_win, t_data img, int focus)
{
	int		i;

	i = 0;
	while (i < 100)
	{
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
									&img.endian);
		my_mlx_pixel_put(&img, 960 + focus, 540 + i + focus, 0x00FF0000);
		my_mlx_pixel_put(&img, 960 + i + focus, 540 + focus, 0x00FF0000);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		i++;
	}
	while (i > 0)
	{
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
									&img.endian);
		my_mlx_pixel_put(&img, 960 + focus, 540 - i + focus, 0x00FF0000);
		my_mlx_pixel_put(&img, 960 - i + focus, 540 + focus, 0x00FF0000);
		i--;
	}
	return (img);
}

int	main(void)
{
	int		j;
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	j = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Escape");
	while (j <  4)
	{
		img.img = mlx_new_image(mlx, 1920, 1080);
		img = draw_cross(mlx, mlx_win, img, (j * 100) + j);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		j++;
	}
	mlx_loop(mlx);
	return (0);
}
