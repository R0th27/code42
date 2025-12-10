/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:54:47 by htoe              #+#    #+#             */
/*   Updated: 2025/12/11 00:02:17 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

//main function
char	*get_next_line(int fd);
char	*left_over(char *cache);
char	*extract_line(char *cache);
char	*parse_line(int fd, char *cache);

//utilities
size_t	ft_strlen(char *str);
int		ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif