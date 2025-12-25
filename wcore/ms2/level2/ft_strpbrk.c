/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 03:50:46 by htoe              #+#    #+#             */
/*   Updated: 2025/12/24 04:11:52 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (NULL);
	while (*s1 != '\0')
	{
		i = 0;
		while (s2[i])
		{
			if (*s1 == s2[i++])
				return ((char *)s1);
		}
		s1++;
	}
	return (NULL);
}

#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	char	*diy;
	char	*ori;

	if (ac != 3)
		return (1);
	diy = ft_strpbrk(av[1], av[2]);
	ori = strpbrk(av[1], av[2]);
	printf("diy : %s\n", diy ? diy : "(null)");
	printf("ori : %s\n", ori ? ori : "(null)");
	return (0);
}
