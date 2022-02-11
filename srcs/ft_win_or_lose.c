/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_or_lose.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:11:32 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/11 13:11:03 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

void	draw_go_string(t_mlx *game, char *s)
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
			if (i == (game->map->line / 2) && j == (game->map->col / 2) - 1)
				draw_string(game, arr, s, 0);
			j++;
			free(arr);
		}
		i++;
	}
}

void	draw_go(t_mlx *game, t_cont *imgs)
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
			draw_image(game, imgs->background2, arr);
			j++;
			free(arr);
		}
		i++;
	}
}
