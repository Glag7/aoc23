/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:08:39 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/22 23:46:03 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include <math.h>

#define N 4

int	main(void)
{
	int	fd = open("in", O_RDONLY);
	char	**tmp;
	ssize_t	times[N];
	ssize_t	distances[N];
	char	file[300];
	size_t	num;
	size_t	sum = 1;

	file[(read(fd, file, 300))] = 0;
	tmp = ft_split_set(file, "Time :Dstanc");
	for (int i = 0; i < N; i++)
		times[i] = ft_atoi(tmp[i]);
	for (int i = N; i < N * 2; i++)
		distances[i - N] = ft_atoi(tmp[i]);
	ft_freearr(tmp);
	for (int i = 0; i < N; i++)
	{
		num = (ssize_t)(floor(((double)times[i] + sqrtl((double)(ft_powi(times[i], 2) - 4 * distances[i])) - 0.00000000000001) / 2) \
		- floor(((double)times[i] - sqrtl((double)(ft_powi(times[i], 2) - 4 * distances[i]))) / 2));
		printf("%zd\n", num);
		sum *= num;
	}
	printf("sum is %zd", sum);
}
