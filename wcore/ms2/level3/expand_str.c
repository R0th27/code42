/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 12:41:33 by htoe              #+#    #+#             */
/*   Updated: 2025/12/25 12:46:33 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;
	int	flag;

	if (ac != 2 || !av[1][0])
		return (write(1, "\n", 1), 1);
	flag = 2;
	i = -1;
	while (av[1][++i])
	{
		if ((av[1][i] == ' ' || (av[1][i] >= 9 && av[1][i] <= 13)) && flag == 0)
			flag = 1;
		if (av[1][i] != ' ' && (av[1][i] < 9 || av[1][i] > 13))
		{
			if (flag == 1)
				write(1, "   ", 3);
			flag = 0;
			write(1, &av[1][i], 1);
		}
	}
	return (write(1, "\n", 1), 0);
}
