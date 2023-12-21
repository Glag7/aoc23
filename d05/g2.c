/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:08:39 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/21 23:08:13 by glaguyon         ###   ########.fr       */
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
	char	**tmp = ft_split(line + 7, ' ');
	ssize_t	*buff = malloc(1000000000 * sizeof(size_t));
	ssize_t	seeds[SEEDS];
	char	*changed = calloc(1000000000, 1);
	conv	nums;
	int	i = 0;
	int	j = 0;
	int	seed = 0;
	ssize_t	min = (ssize_t)1 << 60;

	printf(line);
	while (i < SEEDS)
	{
		seeds[i] = ft_atoi(tmp[i]);
		i++;
	}
	free(line);
	ft_freearr(tmp);
seeded :
	j = 0;
	while (j < seeds[seed + 1])
	{
		buff[j] = seeds[seed] + j;
		j++;
	}
	printf("%d %d seeds\nmax %zd %zd\n", j, seeds[seed + 1], seeds[seed] + seeds[seed + 1], buff[j - 1]);
	line = ft_gnl(fd, 8192);
	while (line && *line)
	{
		if (ft_in(*line, "0123456789") == -1)
		{
			i = 0;
			ft_bzero(changed, j);
			printf("stupid useless line\n");
			//for (i = 0; i < SEEDS; i++)
			//	printf("%zd\n", seeds[i]);
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
		while (i < j)
		{
			if (changed[i] == 0 && buff[i] >= nums.start && buff[i] < nums.end)
			{
				//printf("seed %zd is between %zd and %zd. adding %zd.", \
					    buff[i], nums.start, nums.end, nums.add);
				buff[i] += nums.add;
				//printf(" now equals to %zd\n", buff[i]);
				changed[i] = 1;
			}
			else
				//printf("seed %zd is NOT between %zd and %zd. adding %zd (jk).\n", \
					    buff[i], nums.start, nums.end, nums.add);
			i++;
		}
		free(line);
		line = ft_gnl(fd, 8192);
	}
	free(line);
	printf("locations :\n");
	for (i = 0; i < j; i++)
	{
		if (buff[i] < min)
			min = buff[i];
		//printf("%zd\n", buff[i]);
	}
	printf("closest is %zd\n", min);
	seed += 2;
	if (seed < SEEDS)
	{
		close(fd);
		fd = open("in", O_RDONLY);
		goto seeded;
	}
}
