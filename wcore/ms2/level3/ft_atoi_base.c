/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 12:48:11 by htoe              #+#    #+#             */
/*   Updated: 2025/12/25 14:01:41 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	is_valid(char c, int base, int *constant)
{
	if (c >= '0' && c <= '9')
		*constant = '0';
	else if (c >= 'a' && c <= 'f')
		*constant = 'a' - 10;
	else if (c >= 'A' && c <= 'F')
		*constant = 'A' - 10;
	else
		return (0);
	if (c - (*constant) < base)
		return (1);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int		i;
	int		sign;
	int		result;
	int		constant;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		sign = 44 - str[i++];
	result = 0;
	while (str[i] && is_valid(str[i], str_base, &constant))
		result = (result * str_base) + (str[i++] - constant);
	return (result * sign);
}

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	base;

	if (ac != 3)
		return (0);
	base = atoi(av[1]);
	printf("result: %d\n", ft_atoi_base(av[2], base));
	return (0);
}
