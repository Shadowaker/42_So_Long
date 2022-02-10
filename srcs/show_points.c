/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:44:35 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/10 17:39:39 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

void	draw_base_points(t_mlx *game, t_cont *imgs)
{
	int	i;
	int	*arr;

	i = 0;
	while ((int) game->map->col > i + 1)
	{
		arr = (int *) malloc(sizeof(int) * 2);
		arr[0] = (int) game->map->line;
		arr[1] = i;
		printf("%d - %d\n", arr[0], arr[1]);
		draw_image(game, imgs->wall, arr);
		i++;
		free(arr);
	}
}

void	draw_points(t_mlx *game)
{
	int		*arr;
	char	*s;
	char	*s2;

	arr = (int *) malloc(sizeof(int) * 2);
	s = 0;
	s2 = 0;
	arr[0] = (int) game->map->line;
	arr[1] = (int) game->map->col - 1;
	s = ft_strmerge(s, "Steps: ");
	s = ft_strmerge(s, ft_itoa(game->steps));
	draw_image(game, game->imgs->background2, arr);
	arr[1] = (int) game->map->col - 2;
	draw_image(game, game->imgs->background2, arr);
	draw_string(game, arr, s, 0);
	free(s);
	arr[0] = (int) game->map->line;
	s2 = ft_strmerge(s2, "Coins: ");
	s2 = ft_strmerge(s2, ft_itoa(game->coins));
	draw_string(game, arr, s2, 32);
	free(s2);
	free(arr);
}
