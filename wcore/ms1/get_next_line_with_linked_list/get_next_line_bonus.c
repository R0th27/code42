/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:28:54 by htoe              #+#    #+#             */
/*   Updated: 2025/12/10 23:47:00 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	add_node(char *line, t_node **head)
{
	t_node	*last;
	t_node	*node;
	size_t	i;

	if (!line[0])
		return ;
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return ;
	node -> len = ft_strlen(line);
	node -> line = (char *)malloc(sizeof(char) * (node -> len + 1));
	if (!node -> line)
		return ;
	i = -1;
	while (++i < node -> len + 1)
		node -> line[i] = line[i];
	node -> next = NULL;
	last = ft_lstlast(*head);
	if (!last)
		*head = node;
	else
		last -> next = node;
}

void	parse_file(int fd, t_node **list)
{
	char	*buffer;
	int		byte;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return ;
	buffer[0] = '\0';
	byte = 1;
	while (byte && !ft_strchr(buffer, '\n'))
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte < 0)
			return (free(buffer));
		buffer[byte] = '\0';
		add_node(buffer, list);
	}
	free(buffer);
}

char	*extract_line(t_node *list)
{
	size_t		len;
	size_t		i;
	size_t		j;
	char		*line;

	len = line_length(list);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (list)
	{
		j = 0;
		while (list -> line[j] && i < len)
			line[i++] = list -> line[j++];
		list = list -> next;
	}
	line[i] = '\0';
	return (line);
}

char	*update_cache(char *cache, t_node *list)
{
	char	*left;
	char	*nl;
	size_t	i;
	size_t	index;

	list = ft_lstlast(list);
	nl = ft_strchr(list -> line, '\n');
	if (!nl)
		return (free(cache), NULL);
	index = nl - list -> line + 1;
	if (index == list -> len)
		return (free(cache), NULL);
	left = (char *)malloc(sizeof(char) * (list -> len - index + 1));
	if (!left)
		return (NULL);
	i = 0;
	while (index < list -> len + 1)
		left[i++] = list -> line[index++];
	free(cache);
	return (left);
}

char	*get_next_line(int fd)
{
	static char		*cache[1024];
	char			*line;
	t_node			*list;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	list = NULL;
	if (cache[fd])
		add_node(cache[fd], &list);
	if (!ft_strchr(cache[fd], '\n'))
		parse_file(fd, &list);
	if (!list)
		return (NULL);
	line = extract_line(list);
	cache[fd] = update_cache(cache[fd], list);
	free_list(&list);
	return (line);
}
