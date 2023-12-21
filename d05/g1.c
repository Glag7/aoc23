/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:08:39 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/21 15:44:37 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

#define SEEDS 20

typedef struct conv
{
	ssize_t start;
	ssize_t end;
	ssize_t add;
} conv;

int	main(void)
{
	int	fd = open("in", O_RDONLY);
	char	*line = ft_gnl(fd, 8192);
	char	**tmp = ft_split(line + 7, ' ');////
	ssize_t	seeds[SEEDS];
	char	changed[SEEDS] = {0};
	conv	nums;
	int	i = 0;
	ssize_t	min = (ssize_t)1 << 60;

	while (i < SEEDS)
	{
		seeds[i] = ft_atoi(tmp[i]);
		i++;
	}
	free(line);
	ft_freearr(tmp);
	line = ft_gnl(fd, 8192);
	while (line && *line)
	{
		if (ft_in(*line, "0123456789") == -1)
		{
			i = 0;
			while (i < SEEDS)
			{
				changed[i] = 0;
				i++;
			}
			printf("stupid useless line\n");
			for (i = 0; i < SEEDS; i++)
				printf("%zd\n", seeds[i]);
			free(line);
			line = ft_gnl(fd, 8192);
			continue;
		}
		tmp = ft_split(line, ' ');
		nums.start = ft_atoi(tmp[1]);
		nums.end = nums.start + ft_atoi(tmp[2]);
		nums.add = ft_atoi(tmp[0]) - nums.start;
		ft_freearr(tmp);
		i = 0;
		while (i < SEEDS)
		{
			if (changed[i] == 0 && seeds[i] >= nums.start && seeds[i] <= nums.end)
			{
				printf("seed %zd is between %zd and %zd. adding %zd.", \
					    seeds[i], nums.start, nums.end, nums.add);
				seeds[i] += nums.add;
				printf(" now equals to %zd\n", seeds[i]);
				changed[i] = 1;
			}
			else
				printf("seed %zd is NOT between %zd and %zd. adding %zd (jk).\n", \
					    seeds[i], nums.start, nums.end, nums.add);
;
			i++;
		}
		free(line);
		line = ft_gnl(fd, 8192);
	}
	free(line);
	printf("locations :\n");
	for (i = 0; i < SEEDS; i++)
	{
		if (seeds[i] < min)
			min = seeds[i];
		printf("%zd\n", seeds[i]);
	}
	printf("closest is %zd\n", min);
}
