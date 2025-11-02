/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 01:33:43 by htoe              #+#    #+#             */
/*   Updated: 2025/11/03 02:18:14 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

void	ft_putnbr_base(int nbr, char *base)
{
	long int	num;
	int			len;
	int			buffer[32];
	int			i;

	len = ft_check_base(base);
	if (!len)
		return ;
	num = nbr;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num == 0)
		ft_putchar('0');
	i = 0;
	while (num > 0)
	{
		buffer[i++] = base[num % len];
		num /= len;
	}
	while (--i >= 0)
		ft_putchar(buffer[i]);
}

/*
int	main(void)
{
	char	*dec;
	char	*hex;
	char	*bi;
	char	*oct;
	char	*false1;
	char	*false2;
	char	*false3;

	dec = "0123456789";
	hex = "0123456789ABCDEF";
	bi = "01";
	oct = "poneyvif";
	false1 = "1";
	false2 = "12345+";
	false3 = "ponneyvif";
	ft_putnbr_base(123456, dec);
	ft_putnbr_base(123456, hex);
	ft_putnbr_base(123456, bi);
	ft_putnbr_base(123456, oct);
	ft_putnbr_base(123456, false1);
	ft_putnbr_base(123456, false2);
	ft_putnbr_base(123456, false3);
	return (0);
}
*/