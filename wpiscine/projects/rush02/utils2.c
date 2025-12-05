/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 01:52:55 by htoe              #+#    #+#             */
/*   Updated: 2025/12/05 09:06:25 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*suffix_initializer(int suffix)
{
	char	*sample;
	int		i;

	sample = (char *)malloc(sizeof(char) * (suffix + 2));
	if (!sample)
		return (NULL);
	i = 0;
	sample[i++] = '1';
	while (i < suffix + 1)
		sample[i++] = '0';
	sample[i] = '\0';
	return (sample);
}

void	show_list(t_list *head)
{
	int	i;

	i = 0;
	while (head)
	{
		printf("Node: %d\n", i);
		printf("key: %s & value: %s\n", head -> key, head -> value);
		head = head -> next;
		i++;
	}
}

void	free_list(t_list *head)
{
	t_list	*temp;

	while (head)
	{
		temp = head -> next;
		free(head -> key);
		free(head -> value);
		free(head);
		head = temp;
	}
}
