/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:15:53 by htoe              #+#    #+#             */
/*   Updated: 2025/11/26 01:40:24 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*left_over(char *cache)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	while (cache[i] && cache[i] != '\n')
		i++;
	if (!cache[i])
	{
		free(cache);
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(cache) - i + 1));
	if (!temp)
		return (NULL);
	j = 0;
	while (cache[++i])
		temp[j++] = cache[i];
	temp[j] = '\0';
	free(cache);
	return (temp);
}

char	*extract_line(char *cache)
{
	size_t	len;
	char	*str;

	len = 0;
	if (!cache[len])
		return (NULL);
	while (cache[len] && cache[len] != '\n')
		len++;
	if (cache[len] == '\n')
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	len = 0;
	while (cache[len] && cache[len] != '\n')
	{
		str[len] = cache[len];
		len++;
	}
	str[len] = cache[len];
	if (cache[len])
		str[++len] = '\0';
	return (str);
}

char	*store_line(int fd, char *cache)
{
	int		byte;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	cache = ft_strjoin(cache, "");
	byte = 1;
	while (!ft_strchr(cache, '\n') && byte > 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte] = '\0';
		cache = ft_strjoin(cache, buffer);
	}
	free(buffer);
	return (cache);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*cache;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cache = store_line(fd, cache);
	if (!cache)
		return (NULL);
	line = extract_line(cache);
	cache = left_over(cache);
	return (line);
}
