/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:30:17 by htoe              #+#    #+#             */
/*   Updated: 2025/12/05 06:07:04 by htoe             ###   ########.fr       */
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

int	extract_index(char *line, int **index)
{
	int	i;
	int	len;

	*index = (int *)malloc(sizeof(int) * 3);
	if (!*index)
		return (0);
	len = 0;
	while (line[len])
		len++;
	i = 0;
	while (line[i] && line[i] != ' ' && line[i] != ':')
		i++;
	(*index)[0] = i;
	while (line[i] && line[i] == ' ' && line[i] != ':')
		i++;
	while (line[i] && line[i] != ' ')
		i++;
	(*index)[1] = ++i;
	(*index)[2] = len - i;
	if ((*index)[0] >= len || (*index)[1] == len + 1 || (*index)[2] < 1)
	{
		free(*index);
		return (0);
	}
	return (1);
}

int	parse_line(char **key, char **value, char *line)
{
	int	*index;
	int	format;
	int	i;

	index = NULL;
	format = extract_index(line, &index);
	if (!format)
		return (0);
	*key = (char *)malloc(sizeof(char) * (index[0] + 1));
	*value = (char *)malloc(sizeof(char) * (index[2] + 1));
	i = -1;
	while (++i < index[0])
		(*key)[i] = line[i];
	(*key)[i] = '\0';
	i = 0;
	while (i < index[2] && line[index[1]])
		(*value)[i++] = line[index[1]++];
	(*value)[i] = '\0';
	if (index)
		free(index);
	return (1);
}

t_list	*add_node(char *line)
{
	t_list	*node;
	char	*key;
	char	*value;
	int		parse;

	if (!line)
		return (NULL);
	key = NULL;
	value = NULL;
	parse = parse_line(&key, &value, line);
	if (!parse)
		return (NULL);
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node -> key = key;
	node -> value = value;
	node -> next = NULL;
	return (node);
}

int	dict_parse(int fd, t_list **head)
{
	t_list	*node;
	t_list	*current;
	char	*line;
	int		result;

	line = NULL;
	result = fetch_line(fd, &line);
	node = add_node(line);
	*head = node;
	current = *head;
	while (result)
	{
		free(line);
		if (!node || !*head)
		{
			ft_putstr("Dict Error\n");
			return (0);
		}
		result = fetch_line(fd, &line);
		node = add_node(line);
		current -> next = node;
		current = node;
	}
	return (1);
}
