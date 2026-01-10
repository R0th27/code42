/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 21:48:12 by htoe              #+#    #+#             */
/*   Updated: 2026/01/10 22:09:01 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*temp;
	t_list	*current;

	if (!begin_list)
		return ;
	while (*begin_list && !cmp((*begin_list) -> data, data_ref))
	{
		temp = *begin_list;
		*begin_list = begin_list -> next;
		free(temp);
	}
	current = *begin_list;
	while (current && current -> next)
	{
		if (!cmp(current -> next -> data, data_ref))
		{
			temp = current -> next;
			current -> next = current -> next -> next;
			free(temp);
		}
		else
			current = current -> next;
	}
}
