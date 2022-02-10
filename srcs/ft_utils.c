/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:05:54 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/10 20:35:47 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

char	*ft_strcpy(char *s)
{
	char	*res;
	int		i;

	res = malloc(ft_strlen(s) + 1);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	ft_printmat(char **mat)
{
	int	con;

	con = 0;
	while (mat[con] != 0)
	{
		printf("$%s$\n", mat[con]);
		con++;
	}
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = (unsigned int) len;
	if (ft_strlen(s) <= len)
		sub = (char *) malloc(ft_strlen(s) + 1);
	else
		sub = (char *)malloc(j + 1);
	if (!sub)
		return (NULL);
	if (!((unsigned int) ft_strlen(s) < start))
	{
		while (s[start] != '\0' && i < j)
		{
			sub[i] = s[start];
			i++;
			start++;
		}
	}
	sub[i] = '\0';
	return (sub);
}

int	*ft_arr(int a, int b)
{
	int	*arr;

	arr = (int *) malloc(sizeof(int) * 2);
	arr[0] = a;
	arr[1] = b;
	return (arr);
}

int	error_handler(int cond)
{
	if (cond == 0)
		printf("\33[91mError: Not enough arguments.\033[0m\n");
	else if (cond == 1)
		printf("\33[91mError: Map error!\033[0m\n");
	else if (cond == 2)
		printf("\33[91mMemory error, try to free some ram!\033[0m\n");
	else if (cond == 99)
		printf("\33[91mLibrary error.\033[0m\n");
	return (0);
}
