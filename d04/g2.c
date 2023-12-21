/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:08:39 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/21 13:07:19 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

#define FIVE 10
#define EIGHT 25

int	main(void)
{
	int	fd = open("in", O_RDONLY);
	char	*line = ft_gnl(fd, 116);
	char	**nums;
	int	i;
	int	cline = 0;
	size_t	sum = 0;
	int	tmp;
	int	winning[FIVE];
	int	mine[EIGHT];
	int	cards[202] = {0};
	

	while (line && *line)
	{
		nums = ft_split_set(line + 10, " |");
		printf("LINE %d\n", cline + 1);
		i = 0;
		while (nums[i])
		{
			printf("num %s\n", nums[i]);
			if (i < FIVE)
				winning[i] = ft_atoi(nums[i]);
			else
				mine[i - FIVE] = ft_atoi(nums[i]);
			i++;
		}
		i = 0;
		tmp = 0;
		while (i < EIGHT)
		{
			if (ft_chrarr_int(winning, mine[i], FIVE) != -1)
			{
				printf("winning with %d\n", mine[i]);
				tmp++;
			}
			i++;
		}
		i = 1;
		while (i < 202 && i <= tmp)
		{
			cards[cline + i] += (cards[cline] + 1);
			i++;
		}
		printf("won %d cards !!!\n", cards[cline] + 1);
		sum += cards[cline] + 1;
		ft_freearr(nums);
		free(line);
		line = ft_gnl(fd, 116);
		cline++;
	}
	free(line);
	printf("sum is %zu\n", sum);
}
