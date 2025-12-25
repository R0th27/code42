/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:29:11 by htoe              #+#    #+#             */
/*   Updated: 2025/12/25 11:20:02 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octect)
{
	int	bit;
	int	shift;

	shift = 8;
	while (--shift >= 0)
	{
		bit = (octect >> shift & 1) + '0';
		write(1, &bit, 1);
	}
	write(1, "\n", 1);
}

#include <stdlib.h>

int	main(int ac, char **av)
{
	//int	i;

	if (ac != 2)
		return (1);
	//i = -1;
	print_bits((unsigned char)atoi(av[1]));
	return (0);
}
