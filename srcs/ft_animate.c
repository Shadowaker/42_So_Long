/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:49:49 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/08 21:32:13 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

void	load_player(t_mlx *game, t_player *player)
{
	player->state = 0;
	player->img1 = load_img(game->mlx, "sprites/64px/Player/Player_0.xpm");
	player->img2 = load_img(game->mlx, "sprites/64px/Player/Player_1.xpm");
	player->img3 = load_img(game->mlx, "sprites/64px/Player/Player_2.xpm");
	player->img4 = load_img(game->mlx, "sprites/64px/Player/Player_1.xpm");
}

void	load_enemy(t_mlx *game, t_enemy *enemy)
{
	enemy->state = 0;
	enemy->img1 = load_img(game->mlx, "sprites/64px/Enemy/Enemy_0.xpm");
	enemy->img2 = load_img(game->mlx, "sprites/64px/Enemy/Enemy_1.xpm");
	enemy->img3 = load_img(game->mlx, "sprites/64px/Enemy/Enemy_2.xpm");
	enemy->img4 = load_img(game->mlx, "sprites/64px/Enemy/Enemy_1.xpm");
}

void	load_coin(t_mlx *game, t_coin *coin)
{
	coin->state = 0;
	coin->img1 = load_img(game->mlx, "sprites/64px/Coin/Coin_0.xpm");
	coin->img2 = load_img(game->mlx, "sprites/64px/Coin/Coin_1.xpm");
}

void	load_anims(t_mlx *game)
{
	t_player	player;
	t_enemy		enemy;
	t_coin		coin;

	load_player(game, &player);
	load_enemy(game, &enemy);
	load_coin(game, &coin);
	game->player = &player;
	game->enemy = &enemy;
	game->coin = &coin;
}

void	animate_it(t_mlx *game)
{
	int				*arr;
	size_t			i;
	size_t			j;

	i = 0;
	printf("LOLOL\n");
	while (game->map->line > i)
	{
		j = 0;
		printf("Hello12321\n");
		while (game->map->col >= j)
		{
			arr = (int *) malloc(sizeof(int) * 2);
			arr[0] = i;
			arr[1] = j;
			printf("Filter\n");
			filter_3(game, arr, game->map->matrix[i][j]);
			printf("After filter\n");
			j++;
			free(arr);
		}
		i++;
	}
	printf("END ANIMA\n");
}
