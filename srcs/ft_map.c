/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:42:56 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/05 21:22:51 by dridolfo         ###   ########.fr       */
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

static void	filter(t_mlx *game, t_cont *imgs, int *arr, char cont)
{
	if (cont == '1')
		draw_image(game, imgs->wall, arr);
	else if (cont == 'P')
		draw_image(game, imgs->player, arr);
	else if (cont == 'C')
		draw_image(game, imgs->coin, arr);
	else
		draw_image(game, imgs->background, arr);
}

void	draw_map(t_mlx *game, t_cont *imgs)
{
	int				*arr;
	size_t			i = 0;
	size_t			j;

	while (game->map->line > i)
	{
		j = 0;
		while (game->map->col >= j)
		{
			arr = (int *) malloc(sizeof(int) * 2);
			arr[0] = i;
			arr[1] = j;
			filter(game, imgs, arr, game->map->matrix[i][j]);
			j++;
			free(arr);
		}
		i++;
	}
}
