/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 00:35:58 by htoe              #+#    #+#             */
/*   Updated: 2026/01/11 01:00:41 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int		start;
	int		i;

	if (ac < 2)
		return (write(1, "\n", 1), 1);
	i = 0;
	while (av[1][i] && (av[1][i] == ' ' || (av[1][i] >= 9 && av[1][i] <= 13)))
		i++;
	start = i;
	while (av[1][i] && av[1][i] != ' ' && (av[1][i] < 9 || av[1][i] > 13))
		i++;
	while (av[1][i] && (av[1][i] == ' ' || (av[1][i] >= 9 && av[1][i] <= 13)))
		i++;
	while (av[1][i])
	{
		while (av[1][i] && (av[1][i] == ' ' || (av[1][i] >= 9 && av[1][i] <= 13)))
			i++;
		while (av[1][i] && av[1][i] != ' ' && (av[1][i] < 9 || av[1][i] > 13))
			write(1, &av[1][i++], 1);
		write(1, " ", 1);
	}
	while (av[1][start] && (av[1][start] != ' ' && (av[1][start] < 9 || av[1][start] > 13)))
		write(1, &av[1][start++], 1);
	return (write(1, "\n", 1), 0);
}
