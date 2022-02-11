/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:58:21 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/11 12:40:36 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "../mlx/mlxb/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* general define */

# ifndef W
#  define W 64
# endif

# ifndef H
#  define H 64
# endif

# ifndef SEED
#  define SEED "1234567890qwertyuiopasdfghjklzxcvbnm,bdfsdndvdh dgmn dggmnfrtvy"
# endif

# ifndef TEXT_COLOR
#  define TEXT_COLOR 0xFE6500
# endif

/* --------------- */

/* Map struct */
typedef struct s_map {
	char	**matrix;
	size_t	line;
	size_t	col;
}				t_map;

/* Image base struct (pixel for pixel) */
typedef struct s_dic {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_dic;

/* Images container */
typedef struct s_cont {
	t_dic	player;
	t_dic	player1;
	t_dic	player2;
	t_dic	coin;
	t_dic	coin1;
	t_dic	coin2;
	t_dic	wall;
	t_dic	enemy;
	t_dic	enemy1;
	t_dic	enemy2;
	t_dic	exit;
	t_dic	background;
	t_dic	background2;
}				t_cont;

/* Simple mlx base struct */
typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
	t_map			*map;
	t_cont			*imgs;
	char			*path;
	int				coins;
	unsigned int	rf;
	unsigned int	steps;
	int				**enemies;
	int				n_enemies;
	int				isinmenu;
}				t_mlx;

/* Functions headers */

t_map	*map_init(char *path);
char	**read_map(int fd);
size_t	ft_matlen(char **mat);
void	remap(t_mlx *game, size_t i, int j, char c);
char	*ft_replace(char *s, int i, char c);
int		*ft_coord(char **mat);
void	ft_printmat(char **mat);
int		map_checker(char *path);

int		end_game(t_mlx *game);
void	game_init(t_mlx *game, char *path);
int		key_filter(int keycode, t_mlx *game);
void	draw_menu(t_mlx *game, t_cont *imgs);
int		game_over(t_mlx *game, int cond);
void	draw_go(t_mlx *game, t_cont *imgs);
void	draw_go_string(t_mlx *game, char *s);
void	draw_menu_string(t_mlx *game, char *s, int off);

char	**ft_split(char *s, char c);
int		ft_strstr(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(char *str);
char	*ft_strmerge(char *buff, char *tmp_buff);
char	*ft_strcpy(char *s);
int		*ft_arr(int a, int b);
char	*ft_itoa(int n);
int		error_handler(int cond);

void	my_mlx_pixel_put(t_dic *data, int x, int y, int color);
void	draw_image(t_mlx *game, t_dic img, int *arr);
void	draw_image2(t_mlx *game, t_dic img, int i, int j);
void	draw_map(t_mlx *game, t_cont *imgs);
void	draw_base(t_mlx *game, t_cont *imgs);
void	draw_base_points(t_mlx *game, t_cont *imgs);
void	draw_points(t_mlx *game);
void	draw_string(t_mlx *game, int *arr, char *s, int offset);
void	filter_2(t_mlx *game, t_cont *imgs, int *arr, char cont);
t_dic	load_img(void *mlx, char *path);
t_cont	load_imgs(void *mlx);

void	ft_draw_player(t_mlx *game, t_cont *imgs, int *arr);
void	ft_draw_enemy(t_mlx *game, t_cont *imgs, int *arr);
void	ft_draw_coin(t_mlx *game, t_cont *imgs, int *arr);

void	move_right(t_mlx *game);
void	move_left(t_mlx *game);
void	move_up(t_mlx *game);
void	move_down(t_mlx *game);
int		end_game(t_mlx *game);

void	move_enemy(t_mlx *game, int enemy_ind);
int		move_it(t_mlx *game, int*npos, int ei);
int		*arr(int i, int j);
void	random_move(t_mlx *game, int enemy_ind);
int		**form_enm(t_mlx *game);
size_t	cens_enm(t_mlx *game);

#endif
