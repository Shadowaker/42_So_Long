/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_or_lose.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:11:32 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/10 22:09:32 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

void	draw_win(t_mlx *game, t_cont *imgs)
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
			if (j == 0 || j == game->map->col)
				filter_2(game, imgs, arr, '1');
			else
				filter_2(game, imgs, arr, '0');
			if (i == (game->map->line / 2) && j == (game->map->col / 2))
				draw_string(game, arr, "You win!", 32);
			j++;
			free(arr);
		}
		i++;
	}
}

void	draw_lose(t_mlx *game, t_cont *imgs)
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
			if (j == 0 || j == game->map->col)
				filter_2(game, imgs, arr, '1');
			else
				filter_2(game, imgs, arr, '0');
			if (i == (game->map->line / 2) && j == (game->map->col / 2))
				draw_string(game, arr, "You lose..", 32);
			j++;
			free(arr);
		}
		i++;
	}
}
