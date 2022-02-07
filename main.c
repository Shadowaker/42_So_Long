/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:35:40 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/07 20:45:27 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/lib.h"

int	end_game(t_mlx *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
	return (0);
}

int	key_filter(int keycode, t_mlx *game)
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

int	game_loop(t_mlx *game)
{
	if (game->rf == 1)
	{
		game->rf = 0;
		printf("Steps: %d\n", game->steps);
		draw_map(game, game->imgs);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	game;
	t_cont	imgs;

	if (argc < 2)
		return (error_handler(0));
	if (map_checker(argv[1]) == 0)
		return (error_handler(1));
	game.mlx = mlx_init();
	game.coins = 0;
	game.rf = 1;
	game.steps = 0;
	game.map = map_init(argv[1]);
	game.mlx_win = mlx_new_window(game.mlx, game.map->col * W,
			game.map->line * H, "Escape!");
	imgs = load_imgs(game.mlx);
	game.imgs = &imgs;
	draw_base(&game, &imgs);
	mlx_hook(game.mlx_win, 17, 0, end_game, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_key_hook(game.mlx_win, key_filter, &game);
	mlx_loop(game.mlx);
}
