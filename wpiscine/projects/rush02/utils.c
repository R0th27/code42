/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:11:14 by htoe              #+#    #+#             */
/*   Updated: 2025/12/03 01:53:25 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

char	*ft_strdup(char *str)
{
	int		len;
	char	*nstr;

	len = 0;
	while (str[len])
		len++;
	nstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nstr)
		return (NULL);
	len = 0;
	while (str[len])
	{
		nstr[len] = str[len];
		len++;
	}
	nstr[len] = '\0';
	return (nstr);
}

char	*ft_realloc(char *line, int *old, int new)
{
	int		i;
	char	*nstr;

	nstr = (char *)malloc(sizeof(char) * new);
	if (!nstr)
		return (NULL);
	i = 0;
	while (i < *old)
	{
		nstr[i] = line[i];
		i++;
	}
	free(line);
	*old *= 2;
	return (nstr);
}
