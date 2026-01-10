/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:20:47 by htoe              #+#    #+#             */
/*   Updated: 2026/01/10 22:34:53 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	end;
	int	start;
	int	temp;

	if (ac != 2)
		return (write(1, "\n", 1), 1);
	end = 0;
	while (av[1][end])
		end++;
	while (--end >= 0)
	{
		if (av[1][end] != ' ' && (av[1][end] < 9 || av[1][end] > 13) && end >= 0)
		{
			start = end;
			while (av[1][start] != ' ' && (av[1][start] < 9 || av[1][start] > 13) && start >= 0)
				start--;
			temp = start;
			while (++start <= end)
				write(1, &av[1][start], 1);
			end = temp;
		}
		write(1, &av[1][end], 1);
	}
	return (write(1, "\n", 1), 0);
}
