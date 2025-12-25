/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:17:03 by htoe              #+#    #+#             */
/*   Updated: 2025/12/24 23:30:36 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	check;

	if (ac == 3)
	{
		i = -1;
		j = 0;
		check = 1;
		while (av[1][++i])
		{
			while(av[2][j] && av[1][i] != av[2][j])
				j++;
			if (!av[2][j])
				check = 0;
		}
		if (check == 1)
		{
			i = -1;
			while (av[1][++i])
				write(1, &av[1][i], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
