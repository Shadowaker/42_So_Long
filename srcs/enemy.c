/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:51:26 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/07 20:16:53 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

int	move_i(t_mlx *game, int i, int j)
{
	if (game->map->matrix[i + 1][j] == '1')
	{
		game->map->matrix[i - 1][j] = 'N';
		game->map->matrix[i][j] = '0';
	}
	else if (game->map->matrix[i - 1][j] == '1')
	{
		game->map->matrix[i + 1][j] = 'N';
		game->map->matrix[i][j] = '0';
	}
	else
		return (0);
	return (1);
}

int	move_j(t_mlx *game, int i, int j)
{
	if (game->map->matrix[i][j + 1] == '1')
	{
		game->map->matrix[i][j - 1] = 'N';
		game->map->matrix[i][j] = '0';
	}
	else if (game->map->matrix[i][j - 1] == '1')
	{
		game->map->matrix[i][j + 1] = 'N';
		game->map->matrix[i][j] = '0';
	}
	else
		return (0);
	return (1);
}

int	move_enemy(t_mlx *game, t_enm *enemy)
{
	int	i;
	int	j;

	i = enemy->x;
	j = enemy->y;
	if (move_i(game, i, j) == 1)
		return (1);
	else if (move_j(game, i, j) == 1)
		return (1);
	else
		random_move(game, enemy, i, j);
	return (1);
}
