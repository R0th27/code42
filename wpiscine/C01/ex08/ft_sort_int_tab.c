/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:02:51 by htoe              #+#    #+#             */
/*   Updated: 2025/11/01 19:17:02 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size);

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	
	if (size == 0)
		return;
	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

/*
#include <stdio.h>

int	main(void)
{
	int	list[5];
	int	i;

	list[0] = 5;
	list[1] = 1;
	list[2] = 2;
	list[3] = 6;
	list[4] = 0;
	i = 0;
	while (i < 5)
		printf("%d", list[i++]);
	printf("\n");
	ft_sort_int_tab(list, 5);
	i = 0;
	while (i < 5)
		printf("%d", list[i++]);
	printf("\n");
}
*/