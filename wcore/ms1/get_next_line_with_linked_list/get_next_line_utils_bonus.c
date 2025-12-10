/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:28:52 by htoe              #+#    #+#             */
/*   Updated: 2025/12/10 22:41:10 by htoe             ###   ########.fr       */
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

t_node	*ft_lstlast(t_node *head)
{
	if (!head)
		return (head);
	while (head -> next)
		head = head -> next;
	return (head);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

void	free_list(t_node **list)
{
	t_node	*current;
	t_node	*temp;

	if (!*list)
		return ;
	current = *list;
	while (current)
	{
		temp = current -> next;
		free(current -> line);
		free(current);
		current = temp;
	}
	*list = NULL;
}

size_t	line_length(t_node *list)
{
	size_t	len;
	char	*nl;

	len = 0;
	while (list -> next)
	{
		len += list -> len;
		list = list -> next;
	}
	nl = ft_strchr(list -> line, '\n');
	if (nl)
		len += nl - list -> line + 1;
	else
		len += list -> len;
	return (len);
}
