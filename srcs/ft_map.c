/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:42:56 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/02 20:14:36 by dridolfo         ###   ########.fr       */
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

void	remap(t_mlx *game, size_t i, int j, char c)
{
	char	*res;
	char	**matrix;
	size_t	con;
	size_t	max;

	max = ft_matlen(game->map->matrix);
	matrix = (char **) malloc(max);
	con = 0;
	printf("+%zu+\n", i);
	while (con < max)
	{
		printf("-%zu-\n", con);
		if (con == i)
		{
			printf("Yes.\n");
			res = ft_replace(game->map->matrix[con], j, c);
		}
		else
		{
			printf("No.\n");
			res = ft_strcpy(game->map->matrix[con]);
		}
		printf("\n&%s&\n", res);
		matrix[con] = res;
		free(game->map->matrix[con]);
		con++;
	}
	matrix[max] = 0;
	free(game->map->matrix);
	game->map->matrix = matrix;
}

void	draw_map(t_mlx *game)
{
	int				*arr;
	size_t			i = 0;
	size_t			j;
	t_dic			win_img;

	printf("Drawing\n");
	printf("-----------------------------------------------\n");
	ft_printmat(game->map->matrix);
	printf("-----------------------------------------------\n");
	game->mlx_win = mlx_new_window(game->mlx, game->map->col * 128, game->map->line * 128, "Escape");
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
			//printf("Colonna %zu\n", j);
		}
		//printf("Linea %zu\n", i);
		i++;
	}
	printf("Finito.\n");
}
