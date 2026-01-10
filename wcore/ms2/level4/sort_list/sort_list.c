/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:23:51 by htoe              #+#    #+#             */
/*   Updated: 2026/01/11 01:32:20 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*current;
	int		temp;

	if (!lst || !lst -> next)
		return (lst);
	current = lst;
	while (current && current -> next)
	{
		if (!(*cmp)(current -> x, current -> next -> x))
		{
			temp = current -> x;
			current -> x = current -> next -> x;
			current -> next -> x = temp;
			current = lst;
		}
		else
			current = current -> next;
	}
	return (lst);
}
