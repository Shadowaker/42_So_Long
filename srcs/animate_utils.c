/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:00:46 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/08 21:36:53 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

t_dic	animate_player(t_player *player)
{
	int	i;

	i = player->state;
	if (i == 0)
	{
		player->state++;
		return (player->img1);
	}
	else if (i == 1)
	{
		player->state++;
		return (player->img2);
	}
	else if (i == 2)
	{
		player->state++;
		return (player->img3);
	}
	else
	{
		player->state = 0;
		return (player->img4);
	}
}

t_dic	animate_enemy(t_enemy *enemy)
{
	int	i;

	i = enemy->state;
	if (i == 0)
	{
		enemy->state++;
		return (enemy->img1);
	}
	else if (i == 1)
	{
		enemy->state++;
		return (enemy->img2);
	}
	else if (i == 2)
	{
		enemy->state++;
		return (enemy->img3);
	}
	else
	{
		enemy->state = 0;
		return (enemy->img4);
	}
}

t_dic	animate_coin(t_coin *coin)
{
	printf("coin 1\n");
	if (coin->state == 0)
	{
		printf("STATE\n");
		coin->state++;
		printf("STATE2\n");
		return (coin->img1);
	}
	else
	{
		printf("RESET\n");
		coin->state = 0;
		return (coin->img2);
	}
}

void	filter_3(t_mlx *game, int *arr, char cont)
{
	printf("Hello\n");
	if (cont == 'P')
	{
		printf("P\n");
		draw_image(game, animate_player(game->player), arr);
	}
	else if (cont == 'C')
	{
		printf("C\n");
		draw_image(game, animate_coin(game->coin), arr);
		printf("after c\n");
	}
	else if (cont == 'E')
	{
		printf("E\n");
		draw_image(game, game->imgs->exit, arr);
	}
	else if (cont == '0')
	{
		printf("0\n");
		draw_image(game, game->imgs->background, arr);
	}
	else if (cont == 'N')
	{
		printf("N\n");
		draw_image(game, animate_enemy(game->enemy), arr);
	}
}
