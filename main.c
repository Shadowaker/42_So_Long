/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:35:40 by dridolfo          #+#    #+#             */
/*   Updated: 2022/01/31 20:52:42 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/lib.h"

void	my_mlx_pixel_put(t_dic *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*) dst = color;
}

t_map	map_render(void)
{
	int	f;

	f = open("");

}

t_dic	draw_image(void *mlx, void *mlx_win, int con, char *path)
{
	int		i;
	int		img_width;
	int		img_height;
	t_dic	win_img;

	i = con;
	win_img.img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	win_img.addr = mlx_get_data_addr(win_img.img, &win_img.bpp, &win_img.line_len, &win_img.endian);
	mlx_put_image_to_window(mlx, mlx_win, win_img.img, 0, 0);

	return (win_img);
}

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		con = 0;
	t_dic	win_img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 900, 800, "Escape");
	while (con < 10)
	{
		win_img = draw_image(mlx, mlx_win, con, "sprites/wall.xpm");
		con++;
	}
	mlx_loop(mlx);
}
