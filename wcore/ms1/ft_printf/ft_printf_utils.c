/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 06:06:43 by htoe              #+#    #+#             */
/*   Updated: 2025/12/12 06:56:52 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putchar(char c)
{
	write(1, &c, 1);
	ft_count(0);
}

void	ft_printf_putstr(char *str)
{
	if (!str)
	{
		ft_printf_putstr("(null)");
		return ;
	}
	while (*str)
	{
		ft_printf_putchar(*str);
		str++;
	}
}

void	ft_printf_pointer(void *ptr)
{
	int					temp[16];
	int					i;
	unsigned long long	nbr;
	char				*hex;

	if (!ptr)
	{
		ft_printf_putstr("(nil)");
		return ;
	}
	nbr = (unsigned long long)ptr;
	i = 0;
	while (nbr > 0)
	{
		temp[i++] = nbr % 16;
		nbr /= 16;
	}
	ft_printf_putstr("0x");
	hex = "0123456789abcdef";
	while (--i >= 0)
		ft_printf_putchar(hex[temp[i]]);
}

void	ft_printf_putnbr(int nbr, int flag)
{
	long	nb;
	int		temp[10];
	int		i;

	if (nbr == 0)
	{
		ft_printf_putchar('0');
		return ;
	}
	nb = nbr;
	if (flag == 0)
		nb = (unsigned int)nbr;
	if (nb < 0)
	{
		ft_printf_putchar('-');
		nb *= -1;
	}
	i = 0;
	while (nb > 0)
	{
		temp[i++] = nb % 10;
		nb /= 10;
	}
	while (--i >= 0)
		ft_printf_putchar(temp[i] + '0');
}

void	ft_printf_puthex(unsigned int nbr, int flag)
{
	char	*l_hex;
	char	*c_hex;
	char	*hex;
	int		temp[8];
	int		i;

	if (nbr == 0)
	{
		ft_printf_putchar('0');
		return ;
	}
	l_hex = "0123456789abcdef";
	c_hex = "0123456789ABCDEF";
	hex = l_hex;
	if (flag == 1)
		hex = c_hex;
	i = 0;
	while (nbr > 0)
	{
		temp[i++] = nbr % 16;
		nbr /= 16;
	}
	while (--i >= 0)
		ft_printf_putchar(hex[temp[i]]);
}
