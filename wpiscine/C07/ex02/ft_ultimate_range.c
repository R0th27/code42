/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:19:20 by htoe              #+#    #+#             */
/*   Updated: 2025/11/12 22:04:27 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	diff;
	long long	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	diff = (long long)max - (long long)min;
	*range = (int *)malloc(sizeof(int) * diff);
	if (!*range)
		return (-1);
	i = 0;
	while (i < diff)
		(*range)[i++] = min++;
	return (i);
}
