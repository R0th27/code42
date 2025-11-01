/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 20:10:02 by htoe              #+#    #+#             */
/*   Updated: 2025/11/01 21:16:06 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	flag;
	int	i;

	ft_strlowcase(str);
	flag = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (flag)
				str[i] -= 32;
			flag = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			flag = 0;
		else
			flag = 1;
		i++;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char str1[] = "salUt, coMMent tu vas ? 42mots quarante-deux; cinquante+et+un";
	char str2[] = "HELLO WORLD";
	char str3[] = "123abc DEF ghi";
	char str4[] = "";

	printf("Before: %s\n", str1);
	printf("After : %s\n\n", ft_strcapitalize(str1));

	printf("Before: %s\n", str2);
	printf("After : %s\n\n", ft_strcapitalize(str2));

	printf("Before: %s\n", str3);
	printf("After : %s\n\n", ft_strcapitalize(str3));

	printf("Before: %s\n", str4);
	printf("After : %s\n", ft_strcapitalize(str4));

	return (0);
}
*/