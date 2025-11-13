/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:15:53 by htoe              #+#    #+#             */
/*   Updated: 2025/11/13 23:07:14 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*str;
	int			byte;
	static char	buffer[BUFFER_SIZE];

	byte = read(fd, buffer, BUFFER_SIZE);
	if (byte > 0)
		str = buffer;
	else
		str =
	printf("byte: %d\n", byte);
	str = buffer;
	return (str);
}

int	main(void)
{
	int		fd1;
	char	*str;
	int		i;

	fd1 = open("a.txt", O_RDONLY);
	i = 0;
	while (i < 5)
	{
		str = get_next_line(fd1);
		printf("str: %s\n", str);
		i++;
	}
	close(fd1);
	return (0);
}