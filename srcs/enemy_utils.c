/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:44:51 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/09 19:55:15 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

static int	ft_random(int x, int y)
{
	static int	i = 0;
	int			n;

	if (i > 250)
		i = 0;
	if (i > (int) ft_strlen(SEED))
	{
		i = x - y;
		if (i < 0)
			n = i * -1;
		else
			n = i;
	}
	else
		n = (int) SEED[i];
	while (n > 3)
	{
		if (n > 9)
			n /= 10;
		else
			n /= 3;
	}
	i += 3;
	return (n);
}

static int	move_cond(t_mlx *game, int i, int j)
{
	if (game->map->matrix[i][j] == '0')
		return (1);
	return (0);
}

static int	move_y(t_mlx *game, int enemy_ind, int m, int *npos)
{
	int	con;

	con = 0;
	if (m == 2)
	{
		npos = arr(game->enemies[enemy_ind][0],
				game->enemies[enemy_ind][1] + 1);
		if (move_cond(game, npos[0], npos[1]) == 1)
			con = move_it(game, npos, enemy_ind);
	}
	else
	{
		npos = arr(game->enemies[enemy_ind][0],
				game->enemies[enemy_ind][1] + 1);
		if (move_cond(game, npos[0], npos[1]) == 1)
			con = move_it(game, npos, enemy_ind);
	}
	return (con);
}

static int	move_x(t_mlx *game, int enemy_ind, int m, int *npos)
{
	int	con;

	con = 0;
	if (m == 0)
	{
		npos = arr(game->enemies[enemy_ind][0] + 1,
				game->enemies[enemy_ind][1]);
		if (move_cond(game, npos[0], npos[1]) == 1)
			con = move_it(game, npos, enemy_ind);
	}
	else
	{
		npos = arr(game->enemies[enemy_ind][0] - 1,
				game->enemies[enemy_ind][1]);
		if (move_cond(game, npos[0], npos[1]) == 1)
			con = move_it(game, npos, enemy_ind);
	}
	return (con);
}

void	random_move(t_mlx *game, int enemy_ind)
{
	int	m;
	int	n;
	int	con;
	int	*npos;

	con = 0;
	m = ft_random(game->enemies[enemy_ind][0], game->enemies[enemy_ind][1]);
	n = 0;
	npos = NULL;
	while (con == 0 && n < 4)
	{
		if (m == 0 || m == 1)
			con = move_x(game, enemy_ind, m, npos);
		else
			con = move_y(game, enemy_ind, m, npos);
		if (con == 0 && n == 0)
			m = n;
		else
			m++;
		n++;
		free(npos);
	}
}
