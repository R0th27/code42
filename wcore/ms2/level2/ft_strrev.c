/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 04:15:11 by htoe              #+#    #+#             */
/*   Updated: 2025/12/24 04:27:26 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	temp;

	if (!str)
		return (NULL);
	len = 0;
	while (str[len])
		len++;
	if (!len)
		return (str);
	len--;
	i = -1;
	while (++i < len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len--] = temp;
	}
	return (str);
}

#include <stdio.h>

int		main(int ac, char **av)
{
	int	i;

	if (ac == 1)
		return (1);
	i = 0;
	while (++i < ac)
		printf("%s\n", ft_strrev(av[i]));
	return (0);
}
