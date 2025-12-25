/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 00:14:16 by htoe              #+#    #+#             */
/*   Updated: 2025/12/26 00:37:44 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_atoi(char *str)
{
	int	result;
	int	i;

	if (!str || (*str < '0' || *str > '9'))
		return (-1);
	if (*str == '0')
		return (0);
	i = 0;
	result = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9' && result <= 2147483647)
		result = (result * 10) + (str[i++] - '0');
	if (str[i])
		return (-1);
	return (result);
}

static void	print_hex(int num)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (num >= 16)
		print_hex(num / 16);
	write(1, &hex[num % 16], 1);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	int	num;

	if (ac != 2)
		return (write(1, "\n", 1), 1);
	num = ft_atoi(av[1]);
	if (num < 0)
		return (write(1, "\n", 1), 1);
	print_hex(num);
	return (write(1, "\n", 1), 0);
}
