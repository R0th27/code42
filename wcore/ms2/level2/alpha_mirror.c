/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 00:51:05 by htoe              #+#    #+#             */
/*   Updated: 2025/12/24 01:04:22 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	char	c;
	int		up;
	int		low;
	int		i;

	up = 'A' + 'Z';
	low = 'a' + 'z';
	if (ac == 2)
	{
		i = -1;
		while (av[1][++i])
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				c = low - av[1][i];
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				c = up - av[1][i];
			else
				c = av[1][i];
			write(1, &c, 1);	
		}
	}
	write(1, "\n", 1);
	return (0);
}
