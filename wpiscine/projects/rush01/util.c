/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:24:55 by htoe              #+#    #+#             */
/*   Updated: 2025/11/04 21:25:23 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *c, int size)
{
	int	i;

	i = 0;
	while (i < size)
		write(1, &c[i++], 1);
}


void	ft_print_board(int **board, int btype)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < btype)
	{
		j = 0;
		while (j < btype)
		{
			c = board[i][j++] + '0';
			ft_putchar(&c, 1);
			if (j < btype)
				ft_putchar(" ", 1);
		}
		ft_putchar("\n", 1);
		i++;
	}
}
