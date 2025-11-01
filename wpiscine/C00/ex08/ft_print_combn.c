/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:18:10 by htoe              #+#    #+#             */
/*   Updated: 2025/11/01 17:51:06 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	bt_combn(int n, int num, int pos, int *result)
{
	int	i;

	if (pos == n)
	{
		i = 0;
		while (i < n)
		{
			ft_putchar(result[i] + '0');
			i++;
		}
		if (!(result[0] == 10 - n))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		return ;
	}
	while (num <= 10 - (n - pos))
	{
		result[pos] = num;
		bt_combn(n, num + 1, pos + 1, result);
		num++;
	}
}

void	ft_print_combn(int n)
{
	int	result[10];

	if (n > 0 && n < 10)
		bt_combn(n, 0, 0, result);
	else
		return ;
}

/*
int	main(int argc, char **argv)
{
	int	num;

	if (argc == 2)
	{
		num = (int)(argv[1][0] - '0');
		ft_print_combn(num);
	}
	else
		ft_putchar('X');
}
*/
