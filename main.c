/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:35:40 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/01 19:38:19 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/lib.h"
void move_up(t_mlx *game)
{

};
void move_left(){};
void move_down(){};
void move_right(){};

int	end_game(t_mlx *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
	return (0);
}

int	key_filter(int	keycode, t_mlx *game)
{
	printf("%d\n", keycode);
	if (keycode == 53)
		end_game(game);
	else if (keycode == 13)
		move_up();
	else if (keycode == 0)
		move_left();
	else if (keycode == 1)
		move_down();
	else if (keycode == 2)
		move_right();
	return (0);
}

int main(void)
{
	t_mlx	game;

	game.mlx = mlx_init();
	draw_map(&game);
	mlx_hook(game.mlx_win, 2, 0, key_filter, &game);
	mlx_loop(game.mlx);
}
