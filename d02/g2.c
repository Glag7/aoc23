/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:01:17 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/20 19:02:48 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd = open("in", O_RDONLY);
	size_t	sum = 0;
	char	*line;
	char	**games;
	char	*tmp;
	int	i = 1;
	int	j = 0;
	int	blue = 99, red = 99, green = 99;

	line = ft_gnl(fd, 1024);
	while (line && *line)
	{
		red = 0;
		green = 0;
		blue = 0;
		printf("game %d\n", i);
		printf("%s", line);
		j = 0;
		games = ft_split_set(line + 8, ",;");
		while (games[j])
		{
			tmp = games[j];
			games[j] = ft_strtrim(games[j], " ,:luednr");
			printf("set %s\n", games[j]);
			if ((games[j][2] == 'b' || games[j][3] == 'b'))
			{
				if (ft_atoi(games[j]) > blue)
					blue = ft_atoi(games[j]);
			}
			else if ((games[j][2] == 'g' || games[j][3] == 'g'))
			{
				if (ft_atoi(games[j]) > green)
					green = ft_atoi(games[j]);
			}
			else if (ft_atoi(games[j]) > red)
				red = ft_atoi(games[j]);
			j++;
			ft_freearr(games);
		}
		sum += red * green * blue;
		ft_freearr(games);
		i++;
		free(line);
		line = ft_gnl(fd, 1024);
	}
	printf("sum is %zu", sum);
}

