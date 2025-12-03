/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 01:52:55 by htoe              #+#    #+#             */
/*   Updated: 2025/12/03 22:26:43 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

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
