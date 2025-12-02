/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:54:50 by htoe              #+#    #+#             */
/*   Updated: 2025/11/27 21:18:08 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*str;
	int		fd1;
	int		i;

	if (argc != 2)
		printf("Provide a file\n");
	fd1 = open(argv[1], O_RDONLY);
	i = 0;
	while (i++ < 8)
	{
		str = get_next_line(fd1);
		printf("%d: %s\n", i, str);
		//if (str)
		//	free(str);
	}
	return (0);
}
