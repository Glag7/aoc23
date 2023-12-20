/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:08:39 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/20 20:37:40 by glaguyon         ###   ########.fr       */
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
	int	sum = 0;
	int	i = 0;
	int	j;
	int	tmp;

	blow_up_stack[read(fd, blow_up_stack, 1000000)] = 0;
	lines = ft_split(blow_up_stack, '\n');
	len = ft_strlen(lines[0]);
	while (lines[i])
	{
		printf("LINE %d:\n", i+1);
		j = 0;
norme :
		printf("j = %d\n", j);
		while (lines[i][j] && ft_in(lines[i][j], "0123456789") == -1)
			j++;
		tmp = ft_atoi(lines[i] + j);
		while (lines[i][j] && ft_in(lines[i][j], "0123456789") != -1)
		{
			if ((i - 1 >= 0 && ft_in(lines[i - 1][j], ".0123456789") == -1) ||
				(i - 1 >= 0 && j - 1 >= 0 && ft_in(lines[i - 1][j - 1], ".0123456789") == -1) ||
				(i - 1 >= 0 && j + 1 < len && ft_in(lines[i - 1][j + 1], ".0123456789") == -1) ||
				(i + 1 < len && ft_in(lines[i + 1][j], ".0123456789") == -1) ||
				(i + 1 < len && j - 1 >= 0 && ft_in(lines[i + 1][j - 1], ".0123456789") == -1) ||
				(i + 1 < len && j + 1 < len && ft_in(lines[i + 1][j + 1], ".0123456789") == -1) ||
				(j - 1 >= 0 && ft_in(lines[i][j - 1], ".0123456789") == -1) ||
				(j + 1 < len && ft_in(lines[i][j + 1], ".0123456789") == -1))
			{
				printf("OK COOL %d\n", tmp);
				sum += tmp;
				tmp = 0;
				while (lines[i][j] && ft_in(lines[i][j], "0123456789") != -1)
					j++;
			}
			else
				j++;
		}
		printf("PAS COOL %d\n", tmp);
		if (lines[i][j])
			goto norme;
		i++;
	}
	printf("sum is %d\n", sum);
	ft_freearr(lines);
}
