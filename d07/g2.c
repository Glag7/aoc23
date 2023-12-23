/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:08:39 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/23 01:41:20 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

#define SIZE 1000

typedef	struct hand
{
	size_t	power;
	char	*cards;
	size_t	bid;
} hand;

char	ft_cmp(void *a, void *b)
{
	if (((hand *)a)->power > ((hand *)b)->power)
		return (1);
	return (0);
}

size_t	ft_power(char *cards)
{
	char c = *cards;
	char	seen[5] = {0};
	int	seened = 0;
	int	i = 0;
	int	j;
	int	tmp;
	int	max = 0;
	int	max2 = 1;
	int	jokers = 0;

	while (i < 5)
	{
		if (cards[i] == 'J')
			jokers++;
		i++;
	}
	i = 0;
	while (i < 5)
	{
		tmp = 0;
		c = cards[i];
		j = 0;
		if (ft_in(c, seen) != -1)
		{
			i++;
			continue;
		}
		seen[seened] = c;
		seened++;
		while (j < 5)
		{
			tmp += (c == cards[j]) || (cards[j] == 'J');
			j++;
		}
		if (tmp > max)
		{
			if (max - jokers * (max > 1))
				max2 = max - jokers * (max > 1);
			max = tmp;
		}
		else if (tmp - jokers > max2)
			max2 = tmp - jokers;
		i++;
	}
	if (max > 3 || max < 2)
		return (ft_powi(max, 3));
	if (max < max2)
		ft_swapint(&max, &max2);
	return (ft_powi(max, 2) * max2);
}

int	main(void)
{
	int	fd = open("in", O_RDONLY);
	char	*line;
	size_t	sum = 0;
	hand	*hands[SIZE];
	int	i = 0;


	while (i < SIZE)
	{
		hands[i] = malloc(sizeof(hand));
		hands[i]->cards = malloc(6);
		i++;
	}
	i = 0;
	line = ft_gnl(fd, 8162);
	while (line && *line)
	{
		ft_strlcpy(hands[i]->cards, line, 6);
		hands[i]->bid = ft_atoi(line + 6);
		hands[i]->power = (ft_atoibase(line, "J23456789TQKA"));
		hands[i]->power += ft_power(hands[i]->cards) * 1000000;
		i++;
		free(line);
		line = ft_gnl(fd, 8192);
	}
	ft_sortptr(hands, SIZE, 1, &ft_cmp);
	i = 0;
	while (i < SIZE)
	{
		printf("hand is %s: with bet : %.4zu and power level %.9zu. winning %.6zu\n", hands[i]->cards, hands[i]->bid, hands[i]->power, (i + 1) * hands[i]->bid);
		sum += (i + 1) * hands[i]->bid;
		i++;
	}
	free(line);
	printf("sum is %zu\n", sum);
}
