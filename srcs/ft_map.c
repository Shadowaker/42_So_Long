/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:42:56 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/04 17:12:51 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

t_map	*map_init()
{
	int		fd;
	char	**mat;
	t_map	*map;

	fd = open("./map.ber", O_RDONLY);
	mat = read_map(fd);
	map = (t_map *) malloc(sizeof(t_map));
	map->matrix = mat;
	map->col = ft_strlen(mat[0]);
	map->line = ft_matlen(mat);

	return (map);
}

static t_dic	filter(void *mlx, void *mlx_win, int *arr, char cont)
{
	t_dic	win_img;

	if (cont == '1')
		win_img = draw_image(mlx, mlx_win, arr, "sprites/wall.xpm");
	else if (cont == 'P')
		win_img = draw_image(mlx, mlx_win, arr, "sprites/Player.xpm");
	else if (cont == 'C')
		win_img = draw_image(mlx, mlx_win, arr, "sprites/Coin.xpm");
	else
		win_img = draw_image(mlx, mlx_win, arr, "sprites/background2.xpm");
	return (win_img);
}

void	draw_map(t_mlx *game)
{
	int				*arr;
	size_t			i = 0;
	size_t			j;
	t_dic			win_img;

	while (game->map->line > i)
	{
		j = 0;
		while (game->map->col >= j)
		{
			arr = (int *) malloc(sizeof(int) * 2);
			arr[0] = i;
			arr[1] = j;
			win_img = filter(game->mlx, game->mlx_win, arr, game->map->matrix[i][j]);
			j++;
			free(arr);
		}
		i++;
	}
}
