/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:37:10 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/07 20:44:06 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <mlx.h>
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
#  define SEED "La pizza e' davvero tanto buona, dovrei ordinarne per cena."
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
	t_dic	coin;
	t_dic	wall;
	t_dic	enemy;
	t_dic	exit;
	t_dic	background;
}				t_cont;

/* Simple mlx base struct */
typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
	t_map			*map;
	t_cont			*imgs;
	int				coins;
	unsigned int	rf;
	unsigned int	steps;
}				t_mlx;

/* Enemy Struct */
typedef struct s_enm
{
	int	x;
	int	y;
}			t_enm;

/* Enemy Container */
typedef struct s_enml
{
	t_enm	*list;
}			t_enml;

/* Functions headers */

t_map	*map_init(char *path);
char	**read_map(int fd);
size_t	ft_matlen(char **mat);
void	remap(t_mlx *game, size_t i, int j, char c);
char	*ft_replace(char *s, int i, char c);
int		*ft_coord(char **mat);
void	ft_printmat(char **mat);
int		map_checker(char *path);
void	draw_base(t_mlx *game, t_cont *imgs);

char	**ft_split(char *s, char c);
int		ft_strstr(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(char *str);
char	*ft_strmerge(char *buff, char *tmp_buff);
char	*ft_strcpy(char *s);
int		error_handler(int cond);

void	my_mlx_pixel_put(t_dic *data, int x, int y, int color);
void	draw_image(t_mlx *game, t_dic img, int *arr);
void	draw_map(t_mlx *game, t_cont *imgs);
t_cont	load_imgs(void *mlx);

void	move_right(t_mlx *game);
void	move_left(t_mlx *game);
void	move_up(t_mlx *game);
void	move_down(t_mlx *game);
int		end_game(t_mlx *game);

void	Random_Move(t_mlx *game, t_enm *enemy, int i, int j);

#endif
