/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:14:59 by htoe              #+#    #+#             */
/*   Updated: 2025/11/09 19:25:52 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*dest;

	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	len = 0;
	while (src[len])
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*str;

	if (argc != 2)
	{
		printf("Wrong input\n");
		return (1);
	}
	str = ft_strdup(argv[1]);
	printf("str: %s\n", str);
	free(str);
	return (0);
}
*/
