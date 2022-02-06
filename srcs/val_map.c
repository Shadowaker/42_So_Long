/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:56:50 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/06 21:17:47 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

int	map_checker(char *path)
{
	int		i;
	int		j;
	int		fd;
	char	**mat;

	i = ft_strlen(path);
	if (i == 0)
		return (0);
	if (path[i - 1] != 'r' || path[i - 2] != 'e' || path[i - 3] != 'b' ||
		 path[i - 4] != '.')
		 return (0);

	fd = open("./map.ber", O_RDONLY);
	mat = read_map(fd);
	if (check_borders(mat) == 0 || check_pos(mat) == 0)
		return (0);

}

static int	check_borders(char **mat)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mat[i][j] != '\0')
	{
		if (mat[i][j] != '1')
			return (0);
		j++;
	}
	while (mat[i] != 0)
	{
		if (mat[i][0] != '1' && mat[i][j - 1] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (mat[i][j] != '\0')
	{
		if (mat[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

static int	check_pos(char **mat)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mat[i] != 0 && j == 0)
	{
		if (ft_strstr(mat[i], 'P') == 1)
			j++;
		i++;
	}
	i = 0;
	while (mat[i] != 0 && j == 1)
	{
		if (ft_strstr(mat[i], 'P') == 1)
			j++;
		i++;
	}
}
