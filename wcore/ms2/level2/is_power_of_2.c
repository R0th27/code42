/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:00:28 by htoe              #+#    #+#             */
/*   Updated: 2025/12/24 22:07:45 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_power_of_2(unsigned int n)
{
	while (n % 2 == 0 && n > 2)
		n /= 2;
	if (n != 2)
		return (0);
	return (1);
}

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	unsigned int	x;

	if (ac == 2)
	{
		x = (unsigned int)atoi(av[1]);
		printf("%d\n", is_power_of_2(x));
	}
	return (0);
}
