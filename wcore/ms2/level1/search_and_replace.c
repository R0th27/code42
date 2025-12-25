/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:52:43 by htoe              #+#    #+#             */
/*   Updated: 2025/12/24 00:39:46 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check(char *search, char *replace)
{
	int	i;

	i = 0;
	while (search[i])
		i++;
	if (i != 1)
		return (0);
	i = 0;
	while (replace[i])
		i++;
	if (i != 1)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac == 4)
	{
		if (ft_check(av[2], av[3]))
		{
			i = -1;
			while (av[1][++i])
			{
				if (av[1][i] == av[2][0])
					write(1, &av[3][0], 1);
				else
					write(1, &av[1][i], 1);
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
