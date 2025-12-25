/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 11:28:06 by htoe              #+#    #+#             */
/*   Updated: 2025/12/25 11:39:53 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	char	flag[128] = {0};
	int		i;

	if (ac == 3)
	{
		i = -1;
		while (av[1][++i])
			flag[(int)av[1][i]] = 1;
		i = -1;
		while (av[2][++i])
			flag[(int)av[2][i]] = 1;
		i = -1;
		while (av[1][++i])
		{
			if (flag[(int)av[1][i]] == 1)
			{
				write(1, &av[1][i], 1);
				flag[(int)av[1][i]] = 0;
			}
		}
		i = -1;
		while (av[2][++i])
		{
			if (flag[(int)av[2][i]] == 1)
			{
				write(1, &av[2][i], 1);
				flag[(int)av[2][i]] = 0;
			}
		}
	}
	return (write(1, "\n", 1), 0);
}
