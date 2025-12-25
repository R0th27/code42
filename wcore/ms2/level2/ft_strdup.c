/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 03:26:31 by htoe              #+#    #+#             */
/*   Updated: 2025/12/24 03:48:53 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	size_t	len;
	char	*nstr;

	if (!src)
		return (NULL);
	len = 0;
	while (src[len])
		len++;
	nstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nstr)
		return (NULL);
	nstr[len] = src[len];
	while (len-- > 0)
		nstr[len] = src[len];
	return (nstr);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	char	*str;
	int		i;

	if (ac == 1)
		return (0);
	i = 0;
	while (++i < ac)
	{
		str = ft_strdup(av[i]);
		printf("%s\n", str);
		if (str)
			free(str);
	}
	return (0);
}
