/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:01:17 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/20 18:51:01 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd = open("in", O_RDONLY);
	int	sum = 0;
	char	*line;
	char	**games;
	char	*tmp;
	int	i = 1;
	int	j = 0;
	const int	blue = 14, red = 12, green = 13;

	line = ft_gnl(fd, 1024);
	while (line && *line)
	{
		printf("game %d\n", i);
		printf("%s", line);
		j = 0;
		games = ft_split_set(line + 7, ",;");
		while (games[j])
		{
			tmp = games[j];
			games[j] = ft_strtrim(games[j], " ,:luednr");
			printf("set %s\n", games[j]);
			if ((games[j][2] == 'b' || games[j][3] == 'b'))
			{
				if (ft_atoi(games[j]) > blue)
					break;
			}
			else if ((games[j][2] == 'g' || games[j][3] == 'g'))
			{
				if (ft_atoi(games[j]) > green)
					break;
			}
			else if (ft_atoi(games[j]) > red)
				break;
			j++;
		}
		if (games[j] == NULL)
		{
			printf("GGEZ\n");
			sum += i;
		}
		ft_freearr(games);
		i++;
		free(line);
		line = ft_gnl(fd, 1024);
	}
	printf("sum is %d", sum);
}

