/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:44:51 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/07 20:30:09 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

static int	ft_pseudo_random(int x, int y)
{
	int	i;
	int	j;

	if (x * 2 > ft_strlen(SEED))
		i = (int) SEED[x * 2];
	else
		i = (int) SEED[x];
	if (y * 2 > ft_strlen(SEED))
		j = (int) SEED[y * 2];
	else
		j = (int) SEED[y];
	if (i > j)
	{
		if (i - 5 > j)
			return (0);
		else
			return (1);
	}
	else
	{
		if (j - 5 > i)
			return (2);
		else
			return (3);
	}
}

static void	move_x(t_mlx *game, t_enm *enemy, int *pos)
{
	game->map->matrix[pos[1]][pos[0]] = 'N';
	game->map->matrix[pos[2]][pos[0]] = '0';
	enemy->x = pos[1];
	enemy->y = pos[0];
}

static void	move_y(t_mlx *game, t_enm *enemy, int *pos)
{
	game->map->matrix[pos[0]][pos[1]] = 'N';
	game->map->matrix[pos[0]][pos[2]] = '0';
	enemy->x = pos[0];
	enemy->y = pos[1];
}

void	may_the_force(int *arr, int i, int j, int k)
{
	arr[0] = i;
	arr[1] = j;
	arr[2] = k;
}

void	random_move(t_mlx *game, t_enm *enemy, int i, int j)
{
	int	m;
	int	*pos;

	m = ft_pseudo_random(i, j);
	pos = (int *) malloc(sizeof(int) * 3);
	if (!pos)
		return ;
	if (m == 0 || m == 1)
	{
		if (m == 0)
			may_the_force(pos, j, i - 1, i);
		else
			may_the_force(pos, j, i - 1, i);
		move_x(game, enemy, pos);
	}
	else
	{
		if (m == 2)
			may_the_force(pos, i, j - 1, j);
		else
			may_the_force(pos, i, j + 1, j);
		move_y(game, enemy, pos);
	}
	free(pos);
}
