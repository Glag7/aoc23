/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:08:39 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/23 09:50:52 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

#define GA 443

typedef struct gal {
	int i;
	int j;
} gal;

int	abs(int n)
{
	if (abs > 0)
		return (n);
	return (-n);
}

int	main(void)
{
	int	fd = open("in", O_RDONLY);
	char	blowupstack[100000];
	char	**tmp;
	gal	galax[GA];
	gal	galax2[GA];
	size_t	sum = 0;
	int	i = 0;
	int	j;
	int	index = 0;

	blowupstack[read(fd, blowupstack, 100000)] = 0;
	tmp = ft_split(blowupstack, '\n');
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] == '#')
			{
				galax[index] = (gal){i, j};
				galax2[index] = (gal){i, j};
				index++;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] == '#')
				break;
			j++;
		}
		if (tmp[i][j] != '#')
		{
			for (int u = 0; u < GA; u++)
			{
				if (galax2[u].i > i)
					galax[u].i += 999999;

			}
		}
		i++;
	}
	j = 0;
	i = 0;
	while (tmp[i][j])
	{
		i = 0;
		while (tmp[i])
		{
			if (tmp[i][j] == '#')
				break;
			i++;
		}
		if (!tmp[i])
		{
			printf("oh %d\n", j);
			for (int u = 0; u < GA; u++)
			{
				if (galax2[u].j > j)
					galax[u].j += 999999;

			}
		}
		i = 0;
		j++;
	}
	i = 0;
	while (i < GA)
	{
		printf("galaxy %d : (%d, %d)\n", i + 1, galax[i].i + 1, galax[i].j + 1);
		j = i + 1;
		while (j < GA)
		{
			sum += (size_t)abs(galax[i].i - galax[j].i) + (size_t)abs(galax[i].j - galax[j].j);
			j++;
		}
		i++;
	}
	ft_freearr(tmp);
	printf("sum is %zu", sum);
}
