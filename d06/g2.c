/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:08:39 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/22 23:48:27 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include <math.h>

#define N 1

int	main(void)
{
	ssize_t	times[1] = {52947594};
	ssize_t	distances[1] = {426137412791216};
	char	file[300];
	size_t	num;
	size_t	sum = 1;

	for (int i = 0; i < N; i++)
	{
		num = (ssize_t)(floor(((double)times[i] + sqrtl((double)(ft_powi(times[i], 2) - 4 * distances[i])) - 0.00000000000001) / 2) \
		- floor(((double)times[i] - sqrtl((double)(ft_powi(times[i], 2) - 4 * distances[i]))) / 2));
		printf("%zd\n", num);
		sum *= num;
	}
	printf("sum is %zd", sum);
}
