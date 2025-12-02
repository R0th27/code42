/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 01:52:55 by htoe              #+#    #+#             */
/*   Updated: 2025/12/03 01:53:04 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	show_list(t_list *head)
{
	int	i;

	i = 0;
	while (head)
	{
		printf("Node %d : %s\n", i, head -> key);
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
		free(head);
		head = temp;
	}
}
