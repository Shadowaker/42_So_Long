/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:51:26 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/10 17:38:35 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

int	move_it(t_mlx *game, int*npos, int ei)
{
	game->map->matrix[npos[0]][npos[1]] = 'N';
	game->map->matrix[game->enemies[ei][0]][game->enemies[ei][1]] = '0';
	game->enemies[ei][0] = npos[0];
	game->enemies[ei][1] = npos[1];
	return (1);
}

int	*arr(int i, int j)
{
	int	*arr;

	arr = (int *) malloc(sizeof(int) * 2);
	arr[0] = i;
	arr[1] = j;
	return (arr);
}

void	move_enemy(t_mlx *game, int enemy_ind)
{
	random_move(game, enemy_ind);
}

size_t	cens_enm(t_mlx *game)
{
	int		i;
	int		j;
	size_t	con;

	i = 0;
	con = 0;
	while (game->map->matrix[i] != 0)
	{
		j = 0;
		while (game->map->matrix[i][j] != '\0')
		{
			if (game->map->matrix[i][j] == 'N')
				con++;
			j++;
		}
		i++;
	}
	return (con);
}

int	**form_enm(t_mlx *game)
{
	int		i;
	int		j;
	size_t	con;
	int		**enemies;

	con = cens_enm(game);
	enemies = (int **) malloc((sizeof(int *) * con) + 1);
	i = 0;
	con = 0;
	while (game->map->matrix[i] != 0)
	{
		j = 0;
		while (game->map->matrix[i][j] != '\0')
		{
			if (game->map->matrix[i][j] == 'N')
			{
				enemies[con] = ft_arr(i, j);
				con++;
			}
			j++;
		}
		i++;
	}
	enemies[con] = 0;
	return (enemies);
}
