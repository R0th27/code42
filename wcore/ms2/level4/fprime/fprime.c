/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 03:56:26 by htoe              #+#    #+#             */
/*   Updated: 2026/01/10 05:05:00 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	num;
	int	prime;

	if (ac != 2)
		return (printf("\n"), 1);
	num = atoi(av[1]);
	if (num < 0)
		return (printf("\n"), 1);
	if (num == 0 || num == 1)
		return (printf("%d\n", num), 0);
	prime = 2;
	while (prime <= num / prime)
	{
		while (num % prime == 0)
		{
			printf("%d*", prime);
			num /= prime;
		}
		prime++;
	}
	printf("%d", num);
	return (printf("\n"), 0);
}
