/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:03:59 by htoe              #+#    #+#             */
/*   Updated: 2025/12/24 02:51:03 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	if (!s2)
		return (0);
	i = -1;
	while (s2[++i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	dest1[10];
	char	dest2[10];
	char	dest3[10];
	char	*src1;
	char	*src2;
	char	*src3;

	src1 = NULL;
	src2 = "HelloA";
	src3 = "";
	printf("%s\n", ft_strcpy(dest1, src1));
	printf("%s\n", ft_strcpy(dest2, src2));
	printf("%s\n", ft_strcpy(dest3, src3));
	return (0);
}
