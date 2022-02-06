/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:05:54 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/06 20:52:59 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

char	*ft_strcpy(char *s)
{
	char	*res;
	int		i;

	res = malloc(ft_strlen(s) + 1);
	i = 0;
	while(s[i] != '\0')
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
