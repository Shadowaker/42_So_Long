/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:37:10 by dridolfo          #+#    #+#             */
/*   Updated: 2022/01/31 17:32:39 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

/* general define */

# ifndef Width
#  define Width 1920
# endif

# ifndef Height
#  define Height 600
# endif

/* include gnl */

//# include "srcs/gnl/get_next_line.h"

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
	int		line;
	int		col;
}				t_map;

/* Image base struct (pixel for pixel) */
typedef struct s_dic {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_dic;

/* Simple mlx base struct (Not used, not trusted) */
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
	t_dic	img;
}				t_mlx;


#endif
