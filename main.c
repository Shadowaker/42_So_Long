/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:35:40 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/02 20:28:18 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/lib.h"

void move_up(t_mlx *game)
{
	int	*arr;
	int	i;
	int	j;

	arr = ft_coord(game->map->matrix);
	i = arr[0];
	j = arr[1];
	remap(game, i + 1, j, 'P');
	remap(game, i, j, '0');
	free(arr);
}

void move_left(t_mlx *game)
{
	int	*arr;

	printf("Here\n");
	arr = ft_coord(game->map->matrix);
	printf("%d - %d\n", arr[0], arr[1]);
	printf(".........................................................\n");
	ft_printmat(game->map->matrix);
	printf(".........................................................\n");
	remap(game, arr[0], arr[1] - 1, 'P');
	remap(game, arr[0], arr[1], '0');
	free(arr);
}

void move_down(t_mlx *game)
{
	int	*arr;
	size_t	i;
	int		j;

	arr = ft_coord(game->map->matrix);
	i = (size_t) arr[0];
	j = arr[1];
	remap(game, i + 1, j, 'P');
	remap(game, i, j, '0');
	free(arr);
}

void move_right(t_mlx *game)
{
	int	*arr;
	size_t	i;
	int		j;

	arr = ft_coord(game->map->matrix);
	i = (size_t) arr[0];
	j = arr[1];
	remap(game, i + 1, j, 'P');
	remap(game, i, j, '0');
	free(arr);
}

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
		move_up(game);
	else if (keycode == 0)
		move_left(game);
	else if (keycode == 1)
		move_down(game);
	else if (keycode == 2)
		move_right(game);
	else
		return (0);
	draw_map(game);
	return (0);
}

int Game_Loop(t_mlx *game)
{
	mlx_hook(game->mlx_win, 2, 0, key_filter, game);
	return (0);
}

int main(void)
{
	t_mlx	game;

	game.mlx = mlx_init();
	game.map = map_init();
	draw_map(&game);
	mlx_loop_hook(game.mlx, Game_Loop, &game);
	mlx_loop(game.mlx);
}
