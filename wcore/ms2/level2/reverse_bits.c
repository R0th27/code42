/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:55:17 by htoe              #+#    #+#             */
/*   Updated: 2025/12/25 11:19:45 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octect)
{
	unsigned char	rev;
	int				shift;

	rev = 0;
	shift = -1;
	while (++shift < 8)
	{
		rev = (rev << 1) | (octect & 1);
		octect >>= 1;
	}
	return (rev)
}

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	printf("%d\n", reverse_bits((unsigned char)atoi(av[1])));
	return (0);
}
