/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 01:26:12 by htoe              #+#    #+#             */
/*   Updated: 2025/12/26 01:50:01 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - '0');
	if (!str[i] && result <= 238609294 && result > 0)
		return (result);
	return (0);
}

void	ft_putnbr(int num)
{
	char	c;

	if (num >= 10)
		ft_putnbr(num / 10);
	c = (num % 10) + '0';
	write(1, &c, 1);
}

void	ft_putchar(char *str, int len)
{
		write(1, str, len);
}

int	main(int ac, char **av)
{
	int	num;
	int	i;
	int	len;

	if (ac != 2 || av[1][0] < '1' || av[1][0] > '9')
		return (write(1, "\n", 1), 1);
	num = ft_atoi(av[1]);
	if (num == 0)
		return (write(1, "\n", 1), 1);
	len = -1;
	while (av[1][++len])
	i = 0;
	while (++i < 10)
	{
		ft_putnbr(i);
		ft_putchar(" x ", 3);
		ft_putchar(av[1], len);
		ft_putchar(" = ", 3);
		ft_putnbr(i * num);
		ft_putchar("\n", 1);
	}
	return (0);	
}
