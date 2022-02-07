/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:56:50 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/07 20:46:00 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

static int	check_borders(char **mat, int i, int j)
{
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
	i--;
	while (mat[i][j] != '\0')
	{
		if (mat[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

static int	check_pos(char **mat, char c)
{
	int	i;

	i = 0;
	while (mat[i] != 0)
	{
		if (ft_strstr(mat[i], c) == 1)
			return (1);
		i++;
	}
	return (0);
}

static int	check_pos_loop(char **mat)
{
	if (check_pos(mat, 'C') == 0)
		return (0);
	if (check_pos(mat, 'P') == 0)
		return (0);
	if (check_pos(mat, 'E') == 0)
		return (0);
	return (1);
}

int	map_checker(char *path)
{
	int		i;
	int		fd;
	char	**mat;

	i = ft_strlen(path);
	if (i == 0)
		return (0);
	if (path[i - 1] != 'r' || path[i - 2] != 'e' || path[i - 3] != 'b'
		|| path[i - 4] != '.')
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 1)
		return (0);
	mat = read_map(fd);
	if (check_borders(mat, 0, 0) == 0 || check_pos_loop(mat) == 0)
		return (0);
	return (1);
}
