/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 05:08:20 by htoe              #+#    #+#             */
/*   Updated: 2026/01/10 06:54:26 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t	count_words(char *str)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (str[i])
	{
		while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) && str[i])
			i++;
		if (str[i])
			words++;
		while (str[i] != ' ' && (str[i] < 9 || str[i] > 13) && str[i])
			i++;
	}
	return (words);
}

void	free_arr(char **arr, size_t i)
{
	if (!arr)
		return ;
	while (--i > 0)
		free(arr[i]);
	free(arr[0]);
	free(arr);
}

int	split_words(char **arr, char *str, size_t word_count)
{
	size_t	words;
	size_t	start;
	size_t	end;
	size_t	i;

	words = 0;
	start = 0;
	while (words < word_count)
	{
		while ((str[start] == ' ' || (str[start] >= 9 && str[start] <= 13)) && str[start])
			start++;
		end = start;		
		while (str[end] != ' ' && (str[end] < 9 || str[end] > 13) && str[end])
			end++;
		arr[words] = (char *)malloc(sizeof(char) * (end - start + 1));
		if (!arr[words])
			return (free_arr(arr, words), 0);
		i = 0;
		while (start < end)
			arr[words][i++] = str[start++];
		arr[words][i] = '\0';
		words++;
	}
	return (1);
}

char	**ft_split(char *str)
{
	char	**arr;
	size_t	word_count;

	word_count = count_words(str);
	arr = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!arr)
		return (NULL);
	arr[word_count] = NULL;
	if (!split_words(arr, str, word_count))
		return (NULL);
	return (arr);
}

void	print(char **arr)
{
	int	i;
	
	i = -1;
	while (arr[++i])
		printf("str[%d]: %s\n", i, arr[i]);
}

int	main(int ac, char **av)
{
	char	**split;
	
	if (ac != 2 || !av[1][0])
		return (printf("\n"), 1);
	split = ft_split(av[1]);
	print(split);
	free_arr(split, count_words(av[1]));
	return (0);
}