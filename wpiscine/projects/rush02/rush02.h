/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:07:21 by htoe              #+#    #+#             */
/*   Updated: 2025/12/05 09:53:42 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*key;
	char			*value;
	struct s_list	*next;
}	t_list;

//Utilities
void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_realloc(char *line, int *old, int new);
char	*ft_strdup(char *str);
char	*suffix_initializer(int suffix);

//checking
int		file_check(int argc, char **argv);
int		type_check(int argc, char **argv, char **input);
int		input_check(char *str);

//dict file
int		dict_parse(int fd, t_list **head);
int		fetch_line(int fd, char **line);

//linked-list
t_list	*add_node(char *line);
void	free_list(t_list *head);
void	show_list(t_list *head);

//search and queries
int		process(char *input, t_list *entries, int type);
int		search_and_query(char *input, t_list *entries, int len);
int		search_placement(char number, int suffix, t_list *entries);
char	*search_suffix(int suffix, t_list *entries);
int		search_tens(char tens, char units, t_list *entries);

#endif