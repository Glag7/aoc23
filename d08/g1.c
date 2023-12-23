/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:08:39 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/23 02:49:18 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

#define SIZE 790

typedef	struct dos {
	int l;
	int r;
} dos;

static inline	ft_hash(char *th)
{
	return (th[0] * th[1] * th[2] + th[0] - th[1]  + 3 * th[2]) % (SIZE * 300);
}

int	main(void)
{
	int	fd = open("in", O_RDONLY);
	t_str	instr = {ft_gnl(fd, 4096), ft_strlen(instr.s) -1};
	free(ft_gnl(fd, 4096));
	char	*line = ft_gnl(fd, 4096);
	char	**tmp;
	int	i = 0;
	int	num;
	dos	hashed[SIZE * 300];
	dos	curr;
	size_t	sum = 0;

	while (line && *line)
	{
		tmp = ft_split_set(line, " =(), ");
		num = ft_hash(tmp[0]);
		hashed[num] = (dos){ft_hash(tmp[1]), ft_hash(tmp[2])};
		printf("hashing %s to %.5d\n", tmp[0], num);
		ft_freearr(tmp);
		free(line);
		line = ft_gnl(fd, 4096);
		i++;
	}
	curr = hashed[ft_hash("AAA")];
	while (1)
	{
		//printf("sum is %d\n", sum);
		if (instr.s[sum % instr.len] == 'L')
		{
			//printf("going to %d\n", curr.l);
			if (curr.l == ft_hash("ZZZ"))
				break;
			curr = hashed[curr.l];
		}
		else
		{
			//printf("going to %d\n", curr.r);
			if (curr.r == ft_hash("ZZZ"))
				break;
			curr = hashed[curr.r];
		}
		sum++;
	}
	printf("sum is %d", sum + 1);
	free(line);
}
