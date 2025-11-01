/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:49:10 by htoe              #+#    #+#             */
/*   Updated: 2025/11/01 19:02:24 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size);

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	if (size == 0)
		return ;
	i = 0;
	while (i < (size / 2))
	{
		ft_swap(&tab[i], &tab[size - i - 1]);
		i++;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	int	list[10];
	int	i;

	list[0] = 1;
	list[1] = 2;
	list[2] = 3;
	list[3] = 4;
	list[4] = 5;
	list[5] = 6;
	list[6] = 7;
	list[7] = 8;
	list[8] = 9;
	list[9] = 0;
	i = 0;
	while (i < 10)
		printf("%d", list[i++]);
	ft_rev_int_tab(list, 10);
	i = 0;
	while (i < 10)
		printf("%d", list[i++]);
}
*/
