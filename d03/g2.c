/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:08:39 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/21 00:07:57 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

int	main(void)
{
	int	fd = open("in", O_RDONLY);
	char	blow_up_stack[1000000];
	char	**lines;
	int	len;
	ssize_t	sum = 0;
	int	i = 0;
	int	j;
	int	k;
	int	tmp;

	blow_up_stack[read(fd, blow_up_stack, 1000000)] = 0;
	lines = ft_split(blow_up_stack, '\n');
	len = ft_strlen(lines[0]);
	while (lines[i])
	{
		printf("LINE %d:\n", i+1);
		j = 0;
norme :
		while (lines[i][j] && lines[i][j] != '*')
			j++;
		tmp = (j - 1 >= 0 && ft_in(lines[i][j - 1], "0123456789") != -1) +
			(j + 1 < len && ft_in(lines[i][j + 1], "0123456789") != -1) +
			(i + 1 < len && j + 1 < len && ft_in(lines[i + 1][j + 1], "0123456789") != -1) +
			( !(i + 1 < len && j + 1 < len && ft_in(lines[i + 1][j + 1], "0123456789") != -1) && (i + 1 < len && ft_in(lines[i + 1][j], "0123456789") != -1)) +
			((i + 1 < len && j - 1 >= 0 && ft_in(lines[i + 1][j - 1], "0123456789") != -1) && !(i + 1 < len && ft_in(lines[i + 1][j], "0123456789") != -1)) +
			(i - 1 >= 0 && j + 1 < len && ft_in(lines[i - 1][j + 1], "0123456789") != -1) +
			( !(i - 1 >= 0 && j + 1 < len && ft_in(lines[i - 1][j + 1], "0123456789") != -1) && (i - 1 >= 0 && ft_in(lines[i - 1][j], "0123456789") != -1)) +
			((i - 1 >= 0 && j - 1 >= 0 && ft_in(lines[i - 1][j - 1], "0123456789") != -1) && !(i - 1 >= 0 && ft_in(lines[i - 1][j], "0123456789") != -1));
		printf("CHOK %d\n", tmp);
		if (tmp == 2)
		{
			printf("CHOKBAR\n");
			tmp = 1;
			k = 0;
				while ((j - k - 1 >= 0 && ft_in(lines[i][j - k - 1], "0123456789") != -1))
					k++;
			if (ft_atoi(&lines[i][j - k]))
			{
				printf("num %d\n", ft_atoi(&lines[i][j - k]));
				tmp *= ft_atoi(&lines[i][j - k]);
			}
			if (j + 1 < len && ft_in(lines[i][j + 1], "0123456789") != -1)
			{
				printf("num %d\n", ft_atoi(&lines[i][j + 1]));
				tmp *= ft_atoi(&lines[i][j + 1]);
			}
			if (i - 1 >= 0)
			{
				k = -(j + 1 < len);
					while ((j - k - 1 >= 0 && ft_in(lines[i - 1][j - k - 1], "0123456789") != -1))
						k++;
				if (ft_atoi(&lines[i - 1][j - k]))
				{
					printf("num %d\n", ft_atoi(&lines[i - 1][j - k]));
					tmp *= ft_atoi(&lines[i - 1][j - k]);
				}
				if (k < 0)
				{
					k = (ft_in(lines[i - 1][j], "0123456789") == -1);
					if ((j - k >= 0 && ft_in(lines[i - 1][j - k], "0123456789") != -1))
					{
						while ((j - k - 1 >= 0 && ft_in(lines[i - 1][j - k - 1], "0123456789") != -1))
							k++;
					}
					if (ft_atoi(&lines[i - 1][j - k]))
					{
						printf("num %d\n", ft_atoi(&lines[i - 1][j - k]));
						tmp *= ft_atoi(&lines[i - 1][j - k]);
					}
				}
			}
			if (i + 1 < len)
			{
				k = -(j + 1 < len);
					while ((j - k - 1>= 0 && ft_in(lines[i + 1][j - k - 1], "0123456789") != -1))
						k++;
				if (ft_atoi(&lines[i + 1][j - k]))
				{
					printf("num %d\n", ft_atoi(&lines[i + 1][j - k]));
					tmp *= ft_atoi(&lines[i + 1][j - k]);
				}
				if (k < 0)
				{
					k = (ft_in(lines[i + 1][j],"0123456789") == -1);
					if ((j - k >= 0 && ft_in(lines[i + 1][j - k], "0123456789") != -1))
					{
						while ((j - k - 1 >= 0 && ft_in(lines[i + 1][j - k - 1], "0123456789") != -1))
							k++;
					}
					if (ft_atoi(&lines[i + 1][j - k]))
					{
						printf("num %d\n", ft_atoi(&lines[i + 1][j - k]));
						tmp *= ft_atoi(&lines[i + 1][j - k]);
					}
				}
			}
			printf("TMP %d\n", tmp);
			sum += tmp;
		}
		j++;
		if (lines[i][j])
			goto norme;
		i++;
	}
	printf("sum is %zd\n", sum);
	ft_freearr(lines);
}
