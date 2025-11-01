/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 00:59:19 by htoe              #+#    #+#             */
/*   Updated: 2025/11/01 16:25:26 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	bt_num(int num, int pos, int *result)
{
	int	i;

	if (pos == 3)
	{
		i = 0;
		while (i < 3)
		{
			ft_putchar(result[i] + '0');
			i++;
		}
		if (result[0] != 7)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		return ;
	}
	while (num <= (7 + pos))
	{
		result[pos] = num;
		bt_num(num + 1, pos + 1, result);
		num++;
	}
}

void	ft_print_comb(void)
{
	int	num;
	int	pos;
	int	result[3];

	num = 0;
	pos = 0;
	bt_num(num, pos, result);
}

/*
int	main(void)
{
	ft_print_comb();
	return (0);
}
*/
