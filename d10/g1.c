/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:08:39 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/23 06:24:08 by glaguyon         ###   ########.fr       */
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
	int	i = 0;
	int	j = -1;
	int	n;
	int	n2;
	int	io = 0;
	int	jo = 0;
	size_t	count = 0;

	blowupstack[read(fd, blowupstack, 100000)] = 0;
	tmp = ft_split(blowupstack, '\n');
	while (tmp[i] && j == -1)
	{
		j = ft_in('S', tmp[i]);
		i++;
	}
	io = i - 1;
	jo = j;
	count++;
	while (tmp[i][j] != 'S')
	{
		char	c = tmp[i][j];
		tmp[i][j] = 'X';
		printf("char %c\ncharback %c\n", tmp[i][j], tmp[io][jo]);
		for (int k = 0; k <= 4; k++)
			printf("%s\n", tmp[k]);
		printf("\n\n\n");
		tmp[i][j] = c;
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
		count++;
	}
	ft_freearr(tmp);
	printf("count is %zu, furthest is probably %zu\n", count, (count + 1) / 2);
}
