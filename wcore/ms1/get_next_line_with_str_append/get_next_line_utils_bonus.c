/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:54:42 by htoe              #+#    #+#             */
/*   Updated: 2025/11/26 17:29:08 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (unsigned char)c)
			return (1);
		str++;
	}
	if (*str == (unsigned char)c)
		return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	total;
	size_t	s1i;
	size_t	s2i;
	char	*nstr;

	total = ft_strlen(s1) + ft_strlen(s2);
	nstr = (char *)malloc(sizeof(char) * (total + 1));
	if (!nstr)
		return (NULL);
	s1i = 0;
	while (s1[s1i])
	{
		nstr[s1i] = s1[s1i];
		s1i++;
	}
	s2i = 0;
	while (s2[s2i])
		nstr[s1i++] = s2[s2i++];
	nstr[s1i] = '\0';
	free(s1);
	return (nstr);
}
