/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:47:08 by htoe              #+#    #+#             */
/*   Updated: 2025/12/05 06:24:57 by htoe             ###   ########.fr       */
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
	entries = NULL;
	if (!dict_parse(fd, &entries))
		return (1);
	if (!process(input, entries, type))
		return (1);
	free_list(entries);
	close(fd);
	return (0);
}
