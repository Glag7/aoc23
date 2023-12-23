/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:08:39 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/23 05:23:13 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

int	main(void)
{
	int	fd = open("in", O_RDONLY);
	char	*line = ft_gnl(fd, 4096);
	ssize_t	nums[200];
	int	i;
	int	j;
	size_t	sum = 0;
	size_t	next;
	char	**tmp;

	while (line && *line)
	{
		i = 0;
		tmp = ft_split(line, ' ');
		while (tmp[i])
			i++;
		j = 0;
		while (j < i)
		{
			nums[i - j - 1] = ft_atoi(tmp[j]);
			j++;
		}
		j = 0;
		while (j < i)
		{
			printf("%d, ", nums[j]);
			j++;
		}
		i--;
		ft_freearr(tmp);
		next = nums[i];
		printf("\nnum = %zd\n", nums[i]);
		while (i > 1)
		{
			printf("num += %zd\n", nums[i] - nums[i -1]);
			next += nums[i] - nums[i - 1];
			j = 0;
			while (j < i)
			{
				nums[j] = nums[j + 1] - nums[j];
				j++;
			}
			i--;
		}
		printf("adding %d\n", next);
		sum += next;
		free(line);
		line = ft_gnl(fd, 4096);
	}
	printf("sum is %d\n", sum);
	free(line);
}
