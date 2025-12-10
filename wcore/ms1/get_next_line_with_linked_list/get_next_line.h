/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:28:57 by htoe              #+#    #+#             */
/*   Updated: 2025/12/10 23:49:41 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_node
{
	char			*line;
	size_t			len;
	struct s_node	*next;
}	t_node;

//Main functions
char	*get_next_line(int fd);
void	add_node(char *line, t_node **head);
void	parse_file(int fd, t_node **list);
size_t	line_length(t_node *list);
char	*update_cache(char *cache, t_node *list);
char	*extract_line(t_node *list);

//utilities
size_t	ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
void	free_list(t_node **list);
t_node	*ft_lstlast(t_node *head);

#endif
