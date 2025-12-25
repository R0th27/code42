/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 00:03:47 by htoe              #+#    #+#             */
/*   Updated: 2025/12/26 00:13:06 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	x;
	int	y;
	int	i;
	int	hcf;

	if (ac != 3)
		return (printf("\n"), 1);
	x = atoi(av[1]);
	y = atoi(av[2]);
	if (x <= 0 || y <= 0)
		return (printf("0\n"), 0);
	hcf = 0;
	i = 1;
	while (i <= x || i <= y)
	{
		if (x % i == 0 && y % i == 0)
			hcf = i;
		i++;
	}
	return (printf("%d\n", hcf), 0);
}
