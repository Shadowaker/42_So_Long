/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:40:34 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/11 12:31:57 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../incl/lib.h>

int	end_game(t_mlx *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
	return (0);
}

void	game_init(t_mlx *game, char *path)
{
	game->path = path;
	game->coins = 0;
	game->rf = 1;
	game->steps = 0;
	game->map = map_init(path);
	game->enemies = form_enm(game);
	game->n_enemies = cens_enm(game);
	game->isinmenu = 0;
}

int	key_filter(int keycode, t_mlx *game)
{
	int	i;

	i = 0;
	if (game->n_enemies > 0)
	{
		while (i < game->n_enemies)
		{
			move_enemy(game, i);
			i++;
		}
	}
	if (keycode == 53)
		end_game(game);
	else if (keycode == 13 || keycode == 126)
		move_up(game);
	else if (keycode == 0 || keycode == 123)
		move_left(game);
	else if (keycode == 1 || keycode == 125)
		move_down(game);
	else if (keycode == 2 || keycode == 124)
		move_right(game);
	else
		return (0);
	return (0);
}

void	draw_menu(t_mlx *game, t_cont *imgs)
{
	int				*arr;
	size_t			i;
	size_t			j;

	i = 0;
	while (game->map->line > i)
	{
		j = 0;
		while (game->map->col >= j)
		{
			arr = (int *) malloc(sizeof(int) * 2);
			arr[0] = i;
			arr[1] = j;
			if (i == 0 || j == game->map->col - 1 || j == 0
				|| i == game->map->line - 1)
				filter_2(game, imgs, arr, '1');
			else
				filter_2(game, imgs, arr, '0');
			free(arr);
			j++;
		}
		i++;
	}
}

void	draw_menu_string(t_mlx *game, char *s, int off)
{
	int				*arr;
	size_t			i;
	size_t			j;

	i = game->map->line;
	j = 0;
	while (game->map->col >= j)
	{
		if (j == ((game->map->col / 2) - 2))
		{
			arr = (int *) malloc(sizeof(int) * 2);
			arr[0] = i;
			arr[1] = j;
			draw_string(game, arr, s, off);
			free(arr);
		}
		j++;
	}
}
