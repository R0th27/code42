/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 22:35:33 by htoe              #+#    #+#             */
/*   Updated: 2025/12/25 22:45:26 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	diff;
	int	*result;
	int	i;
	int	len;

	len = end > start ? end - start + 1 : start - end + 1;
	diff = end == start ? 0 : (end > start ? -1 : 1);
	result = (int *)malloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
		result[i] = end + (i * diff);
	return (result);
}


#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int start;
	int	end;
	int	i;
	int	total;
	int	*result;

	if (ac != 3)
		return (write(1, "\n", 1), 1);
	start = atoi(av[1]);
	end = atoi(av[2]);
	total = start > end ? start - end + 1 : end - start + 1;
	result = ft_rrange(start, end);
	i = -1;
	while (++i < total)
		printf("result[%d] %d\n", i, result[i]);
	return (write(1, "\n", 1), 0);
}
