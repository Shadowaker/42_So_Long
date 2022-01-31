/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:41:23 by dridolfo          #+#    #+#             */
/*   Updated: 2022/01/31 20:51:21 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lib.h"

char	**read_map(int fd)
{
	int		f;
	char	**res;
	char	*buff;
	char	*tmp;

	f = 1;
	while (f > 0)
	{
		tmp = (char *) malloc(2);
		f = read(fd, tmp, 1);
		if (f != -1)
			break ;
		tmp[f] = '\0';
		buff = ft_merge(buff, tmp);
		free(tmp);
	}
}

char	*ft_merge()
{}
