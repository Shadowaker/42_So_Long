/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:37:10 by dridolfo          #+#    #+#             */
/*   Updated: 2022/01/29 20:26:20 by dridolfo         ###   ########.fr       */
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

/* --------------- */

/* Cell struct */
typedef struct s_cell {
	char	content;
	char	img;
	char	value;
}				t_cell;

/* Map struct */
typedef struct s_map {
	char	*line;
	char	*col;
}				t_map;

/* Image base struct (pixel for pixel) */
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

/* Simple mlx base struct (Not used) */
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
	t_img	img;
}				t_mlx;


#endif
