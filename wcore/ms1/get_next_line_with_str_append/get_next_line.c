/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:54:46 by htoe              #+#    #+#             */
/*   Updated: 2025/11/27 09:15:13 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*left_over(char *cache)
{
	char	*left;
	size_t	len;
	size_t	i;

	len = 0;
	while (cache[len] && cache[len] != '\n')
		len++;
	if (!cache[len])
	{
		free(cache);
		return (NULL);
	}
	left = (char *)malloc(sizeof(char) * (ft_strlen(cache) - len + 1));
	if (!left)
		return (NULL);
	i = 0;
	while (cache[++len])
		left[i++] = cache[len];
	left[i] = '\0';
	free(cache);
	return (left);
}

char	*extract_line(char *cache)
{
	size_t	len;
	char	*line;

	len = 0;
	if (!cache[len])
		return (NULL);
	while (cache[len] && cache[len] != '\n')
		len++;
	if (cache[len] == '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	len = 0;
	while (cache[len] && cache[len] != '\n')
	{
		line[len] = cache[len];
		len++;
	}
	if (cache[len] == '\n')
		line[len++] = '\n';
	line[len] = '\0';
	return (line);
}

char	*parse_line(int fd, char *cache)
{
	char	*buffer;
	int		byte;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	byte = 1;
	while (!ft_strchr(cache, '\n') && byte > 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(cache);
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
	static char		*cache;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!cache)
	{
		cache = (char *)malloc(sizeof(char) * 1);
		cache[0] = '\0';
	}
	cache = parse_line(fd, cache);
	if (!cache)
		return (NULL);
	line = extract_line(cache);
	cache = left_over(cache);
	return (line);
}
