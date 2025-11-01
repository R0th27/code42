/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:31:51 by htoe              #+#    #+#             */
/*   Updated: 2025/11/01 17:47:15 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	bt_comb2(int num, int pos, int *result)
{
	if (pos == 2)
	{
		ft_putchar((result[0] / 10) + '0');
		ft_putchar((result[0] % 10) + '0');
		ft_putchar(' ');
		ft_putchar((result[1] / 10) + '0');
		ft_putchar((result[1] % 10) + '0');
		if (result[0] != 98)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		return ;
	}
	while (num <= (98 + pos))
	{
		result[pos] = num;
		bt_comb2(num + 1, pos + 1, result);
		num++;
	}
}

void	ft_print_comb2(void)
{
	int	num;
	int	pos;
	int	result[2];

	num = 0;
	pos = 0;
	bt_comb2(num, pos, result);
}
/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/