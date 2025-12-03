/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:47:08 by htoe              #+#    #+#             */
/*   Updated: 2025/12/03 22:25:08 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		type;
	char	*input;
	t_list	*entries;

	fd = file_check(argc, argv);
	if (!fd)
		return (1);
	type = type_check(argc, argv, &input);
	if (!type)
	{
		close(fd);
		return (1);
	}
	entries = dict_parse(fd);
	if (type == 2)
		printf("still implementing for stdin\n");
	else
		printf("still implementing to solve\n");
	show_list(entries);
	free_list(entries);
	close(fd);
	return (0);
}
