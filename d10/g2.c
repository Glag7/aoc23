/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:08:39 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/23 08:41:25 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

int	main(void)
{
	int	fd = open("in", O_RDONLY);
	char	blowupstack[100000];
	char	**tmp;
	char	**tmp2;
	int	good;
	int	io = 0;
	int	jo = 0;
	int	i = 0;
	int	j = -1;
	int	k = 0;
	int	n;
	int	n2;
	size_t	count = 0;
	int	walls;

	blowupstack[read(fd, blowupstack, 100000)] = 0;
	tmp = ft_split(blowupstack, '\n');
	tmp2 = ft_split(blowupstack, '\n');
	while (tmp[i] && j == -1)
	{
		j = ft_in('S', tmp[i]);
		i++;
	}
	io = i - 1;
	jo = j;
	while (tmp[i][j] != 'S')
	{
		tmp2[i][j] = 'X';
		switch (tmp[i][j])
		{
			case '|':
				n = i;
				i += (i - io);
				io = n;
				break;
			case '-':
				n = j;
				j += (j - jo);
				jo = n;
				break;
			case 'L':
				n = (i != io);
				n2 = (j != jo);
				io = i;
				jo = j;
				i -= n2;
				j += n;
				break;
			case 'J':
				n = (i != io);
				n2 = (j != jo);
				io = i;
				jo = j;
				i -= n2;
				j -= n;
				break;
			case '7':
				n = (i != io);
				n2 = (j != jo);
				io = i;
				jo = j;
				i += n2;
				j -= n;
				break;
			case 'F':
				n = (i != io);
				n2 = (j != jo);
				io = i;
				jo = j;
				i += n2;
				j += n;
				break;
		}
	}
	tmp[i][j] = '|';
	tmp2[i][j] = 'X';
	i = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			walls = 0;
			good = 0;
			k = 0;
			n = 0;
			if (tmp2[i][j] == 'X')
			{
				j++;
				continue;
			}
			while (i - k >= 0)
			{
				if ((tmp[i - k][j] == '-' && tmp2[i - k][j] == 'X') ||
				   (tmp[i - k][j] == 'L' && tmp2[i - k][j] == 'X') ||
				   (tmp[i - k][j] == 'F' && tmp2[i - k][j] == 'X'))
					n++;
				if (walls == 0 && tmp2[i - k][j] == 'X')
					walls = 1;
				k++;
			}
			if (n % 2)
				good = 1;
			k = 0;
			n = 0;
			while (tmp[i + k])
			{
				if ((tmp[i + k][j] == '-' && tmp2[i + k][j] == 'X') ||
				(tmp[i + k][j] == 'F' && tmp2[i + k][j] == 'X') ||
				(tmp[i + k][j] == 'L' && tmp2[i + k][j] == 'X'))
					n++;
				if (walls == 1 && tmp2[i + k][j] == 'X')
					walls = 2;
				k++;
			}
			if (n % 2)
				good = 1;
			k = 0;
			n = 0;
			while (j - k >= 0)
			{
				if (walls == 2 && tmp2[i][j - k] == 'X')
					walls = 3;
				k++;
			}
			if (n % 2)
				good = 1;
			k = 0;
			n = 0;
			while (tmp[i][j + k])
			{
				if (walls == 3 && tmp2[i][j + k] == 'X')
					walls = 4;
				k++;
			}
			if (n % 2)
				good = 1;
			if (good && walls == 4)
			{
				tmp2[i][j] = '*';
				count++;
				j++;
			}
			else
			{
				tmp2[i][j] = '.';
				j++;
			}
		}
		printf("%s  |  %s\n", tmp[i], tmp2[i]);
		i++;
	}
	ft_freearr(tmp);
	ft_freearr(tmp2);
	printf("cave is %zu (more or less)\n", count);
}
