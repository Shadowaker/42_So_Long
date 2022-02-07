/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:42:56 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/07 20:33:43 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

t_map	*map_init(char *path)
{
	int		fd;
	char	**mat;
	t_map	*map;

	fd = open(path, O_RDONLY);
	mat = read_map(fd);
	map = (t_map *) malloc(sizeof(t_map));
	map->matrix = mat;
	map->col = ft_strlen(mat[0]);
	map->line = ft_matlen(mat);
	return (map);
}

static void	filter_1(t_mlx *game, t_cont *imgs, int *arr, char cont)
{
	if (cont == 'P')
		draw_image(game, imgs->player, arr);
	else if (cont == 'C')
		draw_image(game, imgs->coin, arr);
	else if (cont == 'E')
		draw_image(game, imgs->exit, arr);
	else if (cont == '0')
		draw_image(game, imgs->background, arr);
	else if (cont == 'N')
		draw_image(game, imgs->exit, arr);
}

static void	filter_2(t_mlx *game, t_cont *imgs, int *arr, char cont)
{
	if (cont == '1')
		draw_image(game, imgs->wall, arr);
	else
		draw_image(game, imgs->background, arr);
}

void	draw_map(t_mlx *game, t_cont *imgs)
{
	int				*arr;
	size_t			i;
	size_t			j;

	i = 0;
	while (game->map->line > i)
	{
		j = 0;
		while (game->map->col >= j)
		{
			arr = (int *) malloc(sizeof(int) * 2);
			arr[0] = i;
			arr[1] = j;
			filter_1(game, imgs, arr, game->map->matrix[i][j]);
			j++;
			free(arr);
		}
		i++;
	}
}

void	draw_base(t_mlx *game, t_cont *imgs)
{
	int				*arr;
	size_t			i;
	size_t			j;

	i = 0;
	while (game->map->line > i)
	{
		j = 0;
		while (game->map->col >= j)
		{
			arr = (int *) malloc(sizeof(int) * 2);
			arr[0] = i;
			arr[1] = j;
			filter_2(game, imgs, arr, game->map->matrix[i][j]);
			j++;
			free(arr);
		}
		i++;
	}
}
