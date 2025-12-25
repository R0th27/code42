/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:03:06 by htoe              #+#    #+#             */
/*   Updated: 2025/12/25 21:30:40 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		begin_list = begin_list -> next;
		size++;
	}
	return (size);
}

#include <stdlib.h>
#include <unistd.h>

void add_list(t_list **head, char *str)
{
	t_list	*node;
	t_list	*last;

	node = (t_list *)malloc(sizeof(t_list));
	node -> data = (void *)str;
	node -> next = NULL;
	last = *head;
	if (!(*head))
		*head = node;
	else
	{
		while (last -> next)
			last = last -> next;
		last -> next = node;
	}
}

void	view_list(t_list *head)
{
	int	i;

	i = 0;
	while (head)
	{
		printf("Node[%d]: %s\n", i, (char *)head -> data);
		head = head -> next;
		i++;
	}
}

void	free_list(t_list **head)
{
	t_list	*temp;
	t_list	*current;

	current = *head;
	while (current)
	{
		temp = current -> next;
		free (current);
		current = temp;
	}
	*head = NULL;
}

int	main(int ac, char **av)
{
	t_list	*head;
	int		i;

	if (ac == 1)
		return (write(1, "\n", 1), 1);
	head = NULL;
	i = 0;
	while (++i < ac)
		add_list(&head, av[i]);
	view_list(head);
	printf("%d\n", ft_list_size(head));
	free_list(&head);
	return (write(1, "\n", 1), 0);
}
