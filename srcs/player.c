/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:13:16 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/11 12:22:23 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

int	mov_cond(t_mlx *game, int *npos)
{
	if (game->map->matrix[npos[0]][npos[1]] == '0')
	{
		draw_image(game, game->imgs->background, npos);
		game->map->matrix[npos[0]][npos[1]] = 'P';
		return (1);
	}
	else if (game->map->matrix[npos[0]][npos[1]] == '1')
		return (0);
	else if (game->map->matrix[npos[0]][npos[1]] == 'E')
		return (2);
	else if (game->map->matrix[npos[0]][npos[1]] == 'C')
	{
		draw_image(game, game->imgs->background, npos);
		game->map->matrix[npos[0]][npos[1]] = 'P';
		game->coins += 1;
		return (1);
	}
	else
		return (-1);
}

void	move_up(t_mlx *game)
{
	int	*arr;
	int	i;

	arr = ft_coord(game->map->matrix);
	if (!arr)
		return ;
	arr[0] -= 1;
	i = mov_cond(game, arr);
	if (i == 1)
	{
		game->map->matrix[arr[0] + 1][arr[1]] = '0';
		game->steps += 1;
		game->rf = 1;
	}
	free(arr);
	if (i < 0)
		game_over(game, 2);
	else if (i == 2)
		game_over(game, 1);
}

void	move_left(t_mlx *game)
{
	int	*arr;
	int	i;

	arr = ft_coord(game->map->matrix);
	if (!arr)
		return ;
	arr[1] -= 1;
	i = mov_cond(game, arr);
	if (i == 1)
	{
		game->map->matrix[arr[0]][arr[1] + 1] = '0';
		game->steps += 1;
		game->rf = 1;
	}
	free(arr);
	if (i < 0)
		game_over(game, 2);
	else if (i == 2)
		game_over(game, 1);
}

void	move_down(t_mlx *game)
{
	int	*arr;
	int	i;

	arr = ft_coord(game->map->matrix);
	if (!arr)
		return ;
	arr[0] += 1;
	i = mov_cond(game, arr);
	if (i == 1)
	{
		game->map->matrix[arr[0] - 1][arr[1]] = '0';
		game->steps += 1;
		game->rf = 1;
	}
	free(arr);
	if (i < 0)
		game_over(game, 2);
	else if (i == 2)
		game_over(game, 1);
}

void	move_right(t_mlx *game)
{
	int	*arr;
	int	i;

	arr = ft_coord(game->map->matrix);
	if (!arr)
		return ;
	arr[1] += 1;
	i = mov_cond(game, arr);
	if (i == 1)
	{
		game->map->matrix[arr[0]][arr[1] - 1] = '0';
		game->steps += 1;
		game->rf = 1;
	}
	free(arr);
	if (i < 0)
		game_over(game, 2);
	else if (i == 2)
		game_over(game, 1);
}
