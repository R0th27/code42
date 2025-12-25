/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:23:48 by htoe              #+#    #+#             */
/*   Updated: 2025/12/23 18:32:19 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_count(char c)
{
	if (c >= 65 && c <= 90)
		return (c - 64);
	if (c >= 97 && c <= 122)
		return (c - 96);
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	max;

	if (ac == 2)
	{
		i = -1;
		while (av[1][++i])
		{
			max = ft_count(av[1][i]); 
			while (max-- > 0)
				write(1, &av[1][i], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
