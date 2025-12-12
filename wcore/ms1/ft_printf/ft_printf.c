/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 06:05:29 by htoe              #+#    #+#             */
/*   Updated: 2025/12/12 06:56:55 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count(int flag)
{
	static int	count = 0;

	if (flag == 0)
		count++;
	else
		count = 0;
	return (count);
}

void	flag_check(va_list args, char c)
{
	if (c == '%')
		ft_printf_putchar('%');
	else if (c == 'c')
		ft_printf_putchar(va_arg(args, int));
	else if (c == 's')
		ft_printf_putstr(va_arg(args, char *));
	else if (c == 'p')
		ft_printf_pointer(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		ft_printf_putnbr(va_arg(args, int), 1);
	else if (c == 'u')
		ft_printf_putnbr(va_arg(args, int), 0);
	else if (c == 'x')
		ft_printf_puthex(va_arg(args, int), 0);
	else if (c == 'X')
		ft_printf_puthex(va_arg(args, int), 1);
	return ;
}

int	ft_printf(const char *str, ...)
{
	int		byte;
	va_list	args;

	if (!str)
		return (0);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			flag_check(args, (char)*(++str));
		else
			ft_printf_putchar(*str);
		str++;
	}
	byte = ft_count(0) - 1;
	ft_count(1);
	va_end(args);
	return (byte);
}
