/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:12:51 by htoe              #+#    #+#             */
/*   Updated: 2025/12/02 02:07:20 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	input_check(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	type_check(int argc, char **argv, char **input)
{
	if (argc == 2 && argv[1][0] == '-')
		return (2);
	else if (argc == 2)
		*input = argv[1];
	else if (argc == 3 && argv[2][0] == '-')
		return (2);
	else
		*input = argv[2];
	if (!input_check(*input))
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}

int	file_check(int argc, char **argv)
{
	int		fd;
	char	*file;

	if (argc < 2 || argc > 3)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (argc == 2)
		file = "numbers.dict";
	else
		file = argv[1];
	fd = open(file, O_RDONLY);
	if (fd < 3)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	return (fd);
}
