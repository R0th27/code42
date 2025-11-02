/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 01:31:42 by htoe              #+#    #+#             */
/*   Updated: 2025/11/03 02:57:22 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_check_base(char *base)
{
	int	i;
	int	j;

	if (!base || !base[0])
		return (0);
	if (!base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

static int	ft_skip_space(char *str, int *sign)
{
	int	pos;

	pos = 0;
	while (str[pos] == ' ' || (str[pos] >= 9 && str[pos] <= 13))
		pos++;
	*sign = 1;
	while (str[pos] == '+' || str[pos] == '-')
	{
		if (str[pos++] == '-')
			*sign *= -1;
	}
	return (pos);
}

static int	ft_check_num(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len;
	int	pos;
	int	sign;
	int	result;
	int	num;

	len = ft_check_base(base);
	if (!len)
		return (0);
	pos = ft_skip_space(str, &sign);
	num = ft_check_num(str[pos], base);
	result = 0;
	while (num != -1)
	{
		result = result * len + num;
		pos++;
		num = ft_check_num(str[pos], base);
	}
	return (sign * result);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str = "         ---10101001";
	char	*base = "01";

	printf("result: %d\n", ft_atoi_base(str, base));
	return (0);
}
*/
