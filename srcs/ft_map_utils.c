/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:41:23 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/10 17:39:05 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

size_t	ft_matlen(char **mat)
{
	size_t	i;

	i = 0;
	while (mat[i] != 0)
		i++;
	return (i);
}

int	*ft_coord(char **mat)
{
	int	i;
	int	j;
	int	*res;

	res = malloc(sizeof(int) * 2);
	if (!res)
		return (NULL);
	i = 0;
	while (mat[i] != 0)
	{
		j = 0;
		while (mat[i][j] != '\0')
		{
			if (mat[i][j] == 'P')
			{
				res[0] = i;
				res[1] = j;
				return (res);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*ft_replace(char *s, int i, char c)
{
	char	*res;
	int		j;

	j = 0;
	while (s[j] != '\0')
		j++;
	res = (char *) malloc(j);
	j = 0;
	while (s[j] != '\0')
	{
		if (j == i)
			res[j] = c;
		else
			res[j] = s[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_strmerge(char *buff, char *tmp_buff)
{
	size_t	i;
	size_t	j;
	char	*s;

	if (!buff)
	{
		buff = (char *) malloc(1);
		buff[0] = '\0';
	}
	if (!buff || !tmp_buff)
		return (NULL);
	s = malloc((ft_strlen(buff) + ft_strlen(tmp_buff)) + 1);
	if (!s)
		return (NULL);
	i = -1;
	j = 0;
	if (buff)
		while (buff[++i] != '\0')
			s[i] = buff[i];
	while (tmp_buff[j] != '\0')
		s[i++] = tmp_buff[j++];
	s[i] = '\0';
	free(buff);
	return (s);
}

char	**read_map(int fd)
{
	int		f;
	char	**res;
	char	*buff;
	char	*tmp;

	f = 1;
	tmp = (char *) malloc(2);
	buff = (char *) malloc(2);
	while (f != 0)
	{
		f = read(fd, tmp, 1);
		if (f == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[f] = '\0';
		buff = ft_strmerge(buff, tmp);
	}
	free(tmp);
	res = ft_split(buff, '\n');
	return (res);
}
