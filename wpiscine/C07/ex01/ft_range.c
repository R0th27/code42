/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:42:43 by htoe              #+#    #+#             */
/*   Updated: 2025/11/12 22:04:15 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			*range;
	long long	diff;
	long long	i;

	if (min >= max)
		return (NULL);
	diff = (long long)max - (long long)min;
	range = (int *)malloc(sizeof(int) * diff);
	if (!range)
		return (NULL);
	i = 0;
	while (i < diff)
		range[i++] = min++;
	return (range);
}

/*
#include <stdio.h>

int	main(void)
{
	int	min1;
	int	min2;
	int	max;
	long long	i;
	long long	diff;
	int	*range1;
	int	*range2;

	min1 = 2147483640;
	min2 = -2147483648;
	max = 2147483647;
	range1 = ft_range(min1, max);
	range2 = ft_range(min2, max);
	i = 0;
	diff = max - min1;
	printf("range1\n");
	while (i < diff)
	{
		printf("number: %d at %lld\n", range1[i], i);
		i++;
	}
	i = 0;
	diff = max - min2;
	printf("range2\n");
	while (i < diff)
	{
		printf("number: %d at %lld\n", range2[i], i);
		i++;
	}
	return (0);
}
*/