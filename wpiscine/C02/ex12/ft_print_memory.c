/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 03:04:44 by htoe              #+#    #+#             */
/*   Updated: 2025/11/02 21:54:28 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char *c, int size)
{
	int	i;

	i = 0;
	while (i < size)
		write(1, &c[i++], 1);
}

static void	ft_print_hex(unsigned long long num, int flag)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (num < 16 && flag == 1)
		ft_putchar("0", 1);
	if (num > 15)
		ft_print_hex((num / 16), 0);
	ft_putchar(&hex[num % 16], 1);
}

static void	ft_print_addr(unsigned long long ptr)
{
	unsigned long long	tmp;
	int					i;

	tmp = ptr;
	i = 0;
	while (i < 15)
	{
		if (tmp < 16)
			ft_putchar("0", 1);
		tmp /= 16;
		i++;
	}
	ft_print_hex(ptr, 0);
}

static void	ft_print_data(char *str, int padding)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < padding)
			ft_print_hex(str[i], 1);
		else
			ft_putchar("  ", 2);
		i++;
		if (i % 2 == 0)
			ft_putchar(" ", 1);
	}
	i = 0;
	while (i < padding)
	{
		if (str[i] < ' ' || str[i] > '~')
			ft_putchar(".", 1);
		else
			ft_putchar(&str[i], 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				padding;

	i = 0;
	while (i * 16 < size)
	{
		if ((i + 1) * 16 < size)
			padding = 16;
		else
			padding = size % 16;
		ft_print_addr((unsigned long long)addr + (i * 16));
		ft_putchar(": ", 2);
		ft_print_data((char *)addr + (i * 16), padding);
		ft_putchar("\n", 1);
		i++;
	}
	return (addr);
}

/*
int	main(void)
{
	char	str[] = "Bonjour les aminches\t\n\tc\a est fou\ttout\tce qu on peut 
					faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";

	ft_print_memory(str, sizeof(str));
	//ft_putchar("\n", 1);
	return (0);
}
*/
