/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:59:50 by htoe              #+#    #+#             */
/*   Updated: 2025/12/24 02:51:07 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	if (!str)
		return;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	return;
}

int	main(void)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = NULL;
	str2 = "Hello World";
	str3 = "";
	ft_putstr(str1);
	ft_putstr("\n");
	ft_putstr(str2);
	ft_putstr("\n");
	ft_putstr(str3);
	ft_putstr("\n");
	return (0);
}
