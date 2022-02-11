/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:59:33 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/11 12:40:52 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

void	ft_draw_player(t_mlx *game, t_cont *imgs, int *arr)
{
	static int	i = 0;

	if (i == 0)
	{
		draw_image(game, imgs->player, arr);
		i++;
	}
	else if (i == 1)
	{
		draw_image(game, imgs->player1, arr);
		i++;
	}
	else if (i == 2)
	{
		draw_image(game, imgs->player2, arr);
		i++;
	}
	else
	{
		draw_image(game, imgs->player1, arr);
		i = 0;
	}
}

void	ft_draw_enemy(t_mlx *game, t_cont *imgs, int *arr)
{
	static int	i = 0;

	if (i == 0)
	{
		draw_image(game, imgs->enemy, arr);
		i++;
	}
	else if (i == 1)
	{
		draw_image(game, imgs->enemy1, arr);
		i++;
	}
	else if (i == 2)
	{
		draw_image(game, imgs->enemy2, arr);
		i++;
	}
	else
	{
		draw_image(game, imgs->enemy1, arr);
		i = 0;
	}
}

void	ft_draw_coin(t_mlx *game, t_cont *imgs, int *arr)
{
	static int	i = 0;

	if (i == 0)
	{
		draw_image(game, imgs->coin, arr);
		i++;
	}
	else if (i == 1)
	{
		draw_image(game, imgs->coin1, arr);
		i++;
	}
	else if (i == 2)
	{
		draw_image(game, imgs->coin2, arr);
		i++;
	}
	else
	{
		draw_image(game, imgs->coin1, arr);
		i = 0;
	}
}
