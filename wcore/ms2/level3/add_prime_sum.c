/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 11:49:05 by htoe              #+#    #+#             */
/*   Updated: 2025/12/25 12:24:01 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_atoi(char *str)
{
	int	num;
	int	i;

	if (!str)
		return (0);
	i = -1;
	num = 0;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		num = (num * 10) + (str[i] - '0');
	}
	return (num);
}

static int	is_prime(int num)
{
	int	i;

	i = 2;
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int num)
{
	if (num >= 10)
		ft_putnbr(num / 10);
	ft_putchar((num % 10) + '0');
}

#include <stdio.h>

int	main(int ac, char **av)
{
	int	num;
	int	i;
	int	result;

	if (ac != 2 || ft_atoi(av[1]) < 2)
		return (write(1, "0\n", 2), 1);	
	num = ft_atoi(av[1]);
	result = 0;
	i = 1;
	while (++i <= num)
	{
		if (is_prime(i))
			result += i;
	}
	ft_putnbr(result);
	write(1, "\n", 1);
	return (0);
}
