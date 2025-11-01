/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:02:03 by htoe              #+#    #+#             */
/*   Updated: 2025/11/01 17:17:09 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int	num;

	num = nb;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num > 9)
		ft_putnbr(num / 10);
	ft_putchar((num % 10) + '0');
}
/*
int	main(void)
{
	ft_putnbr(9);
	ft_putnbr(0);
	ft_putnbr(-1);
	ft_putnbr(42);
	ft_putchar('\n');
	ft_putnbr(2147483647);
	ft_putchar('\n');
	ft_putnbr(-2147483648);
	ft_putchar('\n');
}
*/