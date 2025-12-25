/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 23:23:49 by htoe              #+#    #+#             */
/*   Updated: 2025/12/25 23:54:56 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	i;
	unsigned int	hcf;

	if (a == 0 || b == 0)
		return (0);
	hcf = 0;
	i = 1;
	while (i <= a && i <= b)
	{
		if (a % i == 0 && b % i == 0)
			hcf = i;
		i++;
	}
	return ((a * b) / hcf);
}

#include <stdlib.h>

int	main(int ac, char **av)
{
	unsigned int	x;
	unsigned int	y;

	if (ac != 3)
		return (write(1, "\n", 1), 1);
	x = (unsigned)atoi(av[1]);
	y = (unsigned)atoi(av[2]);
	printf("lcm: %u\n", lcm(x, y));
	return (0);
}
