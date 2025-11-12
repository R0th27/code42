/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:26:52 by htoe              #+#    #+#             */
/*   Updated: 2025/11/12 22:03:04 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_total(int size, char **strs, char *sep)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j++])
			len++;
		i++;
	}
	i = 0;
	while (sep[i++])
		len++;
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		count;
	char	*result;

	count = ft_total(size, strs, sep);
	result = (char *)malloc(sizeof(char) * (count + 1));
	i = 0;
	count = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			result[count++] = strs[i][j++];
		if (i < size - 1)
		{
			j = 0;
			while (sep[j])
				result[count++] = sep[j++];
		}
		i++;
	}
	result[count] = '\0';
	return (result);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*sep;
	char	**strs;
	char	*result;
	int		i;
	int		j;
	
	if (argc < 2)
	{
		printf("Error\n");
		return (1);
	}
	i = 1;
	j = 0;
	strs = (char **)malloc(sizeof(char *) * (argc - 2));
	while (i < argc - 1)
		strs[j++] = argv[i++];
	sep = argv[i];
	result = ft_strjoin(i - 1, strs, sep);
	printf("result: %s\n", result);
	free(result);
	free(strs);
	return (0);
}
*/