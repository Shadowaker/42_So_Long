/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:35:40 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/05 19:36:12 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/lib.h"

int	end_game(t_mlx *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
	return (0);
}

int	key_filter(int	keycode, t_mlx *game)
{
	if (keycode == 53)
		end_game(game);
	else if (keycode == 13)
		move_up(game);
	else if (keycode == 0)
		move_left(game);
	else if (keycode == 1)
		move_down(game);
	else if (keycode == 2)
		move_right(game);
	else
		return (0);
	return (0);
}

int Game_Loop(t_mlx *game)
{
	if (game->rf == 1)
	{
		game->rf = 0;
		draw_map(game);
	}
	return (0);
}

int main(void)
{
	t_mlx	game;

	game.mlx = mlx_init();
	game.coins = 0;
	game.rf = 1;
	game.map = map_init();
	game.mlx_win = mlx_new_window(game.mlx, game.map->col * 32, game.map->line * 32, "Escape");
	mlx_loop_hook(game.mlx, Game_Loop, &game);
	mlx_key_hook(game.mlx_win, key_filter, &game);
	mlx_loop(game.mlx);
}
