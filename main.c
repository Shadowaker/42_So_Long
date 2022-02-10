/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:35:40 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/10 21:47:32 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/lib.h"

int	game_loop(t_mlx *game)
{
	if (game->isinmenu == 1)
	{
		if (game->rf == 1)
		{
			game->rf = 0;
			draw_map(game, game->imgs);
			draw_points(game);
		}
	}
	return (0);
}

int	key_loop(int keycode, t_mlx *game)
{
	if (game->isinmenu == 0)
	{
		if (keycode == 49)
		{
			game->isinmenu = 1;
			draw_base(game, game->imgs);
		}
		else if (keycode == 53)
			end_game(game);
	}
	else
		key_filter(keycode, game);
	return (0);
}

void	menu_start(t_mlx *game)
{
	draw_menu(game, game->imgs);
	draw_menu_string(game);
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
	if (!game.mlx)
		return (error_handler(99));
	game_init(&game, argv[1]);
	game.mlx_win = mlx_new_window(game.mlx, game.map->col * W,
			(game.map->line + 1) * H, "Go Back Home");
	if (!game.mlx_win)
		return (error_handler(99));
	imgs = load_imgs(game.mlx);
	game.imgs = &imgs;
	menu_start(&game);
	mlx_hook(game.mlx_win, 17, 0, end_game, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_key_hook(game.mlx_win, key_loop, &game);
	mlx_loop(game.mlx);
}
