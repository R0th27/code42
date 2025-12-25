/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:18:27 by htoe              #+#    #+#             */
/*   Updated: 2025/12/24 02:50:59 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

#include <stdio.h>

int	main(void)
{
	char	*str;
	char	*str2;

	str2 = NULL;
	str = "123456789";
	printf("%d\n", ft_strlen(str));
	printf("%d\n", ft_strlen(str2));
	return (0);
}
