/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:09:25 by htoe              #+#    #+#             */
/*   Updated: 2025/12/24 22:27:27 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	unsigned int	max;
	unsigned int	i;
	
	if (len == 0)
		return (0);
	i = 0;
	max = 0;
	while (i < len)
	{
		if (tab[i] > tab[max])
			max = i;
		i++;
	}
	return (tab[max]);
}

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	unsigned int	len;
	int				*tab;
	int				i;
	
	if (ac == 3)
	{
		len = (unsigned int)atoi(av[2]);
		tab = (int *)malloc(sizeof(int) * len);
		i = -1;
		while (av[1][++i])
			tab[i] = av[1][i] - '0';
		printf("max: %d\n", max(tab, len));
		free(tab);
	}
	return (0);
}
