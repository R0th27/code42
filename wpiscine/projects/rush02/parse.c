/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:30:17 by htoe              #+#    #+#             */
/*   Updated: 2025/12/03 01:52:41 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	fetch_line(int fd, char **line)
{
	char	c[1];
	int		byte;
	int		i;
	int		max;

	byte = read(fd, c, 1);
	if (!byte)
	{
		*line = NULL;
		return (0);
	}
	max = 32;
	*line = (char *)malloc(sizeof(char) * max);
	if (!*line)
		return (0);
	i = 0;
	while (byte > 0 && c[0] != '\n')
	{
		if (i + 1 >= max)
			*line = ft_realloc(*line, &max, max * 2);
		(*line)[i++] = c[0];
		byte = read(fd, c, 1);
	}
	(*line)[i] = '\0';
	return (1);
}

t_list	*add_node(char *line)
{
	t_list	*node;

	if (!line)
		return (NULL);
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node -> key = ft_strdup(line);
	node -> next = NULL;
	return (node);
}

t_list	*dict_parse(int fd)
{
	t_list	*head;
	t_list	*node;
	t_list	*current;
	char	*line;
	int		result;

	line = NULL;
	result = fetch_line(fd, &line);
	if (!result)
		return (NULL);
	head = add_node(line);
	current = head;
	while (result)
	{
		free(line);
		result = fetch_line(fd, &line);
		node = add_node(line);
		current -> next = node;
		current = node;
	}
	return (head);
}
