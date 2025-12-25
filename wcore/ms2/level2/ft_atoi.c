/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 02:34:40 by htoe              #+#    #+#             */
/*   Updated: 2025/12/25 13:29:32 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 0;
	if (str[i] == '+' || str[i] == '-')
		sign = 44 - str[i++];
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - '0');
	return (num * sign);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac == 1)
		return (0);
	i = 0;
	while (++i < ac)
		printf("%d\n", ft_atoi(av[i]));
	return (0);
}
