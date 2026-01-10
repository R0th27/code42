/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:01:43 by htoe              #+#    #+#             */
/*   Updated: 2026/01/11 01:24:05 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				temp;

	if (!size || !tab)
		return ;
	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int	main(void)
{
	int	num[15] = {9, 8, 7, 6, 4, 5, 2, 100, 1, 3, -1, -2, -100, 0, 1};
	int	size = 15;
	printf("Before\n");
	int	i = -1;
	while (++i < size)
		printf("[%d] ", num[i]);
	sort_int_tab(num, size);
	printf("\nAfter\n");
	i = -1;
	while (++i < size)
		printf("[%d] ", num[i]);
	return (printf("\n"), 0);
}
