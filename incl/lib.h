/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:37:10 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/02 20:13:15 by dridolfo         ###   ########.fr       */
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

# ifndef Width
#  define Width 1920
# endif

# ifndef Height
#  define Height 600
# endif

/* --------------- */

/* Cell struct */
typedef struct s_cell {
	char	content;
	char	img;
	char	value;
}				t_cell;

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

/* Simple mlx base struct */
typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map;
}				t_mlx;

t_map	*map_init();
char	**ft_split(char *s, char c);
size_t	ft_strlen(char *str);
char	*ft_strmerge(char *buff, char *tmp_buff);
char	**read_map(int fd);
size_t	ft_matlen(char **mat);
void	my_mlx_pixel_put(t_dic *data, int x, int y, int color);
t_dic	draw_image(void *mlx, void *mlx_win, int *arr, char *path);
void	draw_map(t_mlx *game);
void	remap(t_mlx *game, size_t i, int j, char c);
char	*ft_replace(char *s, int i, char c);
int		*ft_coord(char **mat);
char	*ft_strcpy(char *s);
void	ft_printmat(char **mat);

#endif
