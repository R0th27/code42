/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:26:20 by htoe              #+#    #+#             */
/*   Updated: 2025/11/04 21:32:09 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putchar(char *c, int size);

int	**ft_create_board(int btype)
{
	int	**board;
	int	row;

	board = (int **)malloc(sizeof(int *) * btype);
	if (!board)
	{
		ft_putchar("Error\n", 6);
		return (NULL);
	}
	row = 0;
	while (row < btype)
	{
		board[row] = (int *)malloc(sizeof(int) * btype);
		if (!board[row])
		{
			while (row-- > 0)
				free(board[row]);
			free(board);
			ft_putchar("Error\n", 6);
			return (NULL);
		}
		row++;
	}
	return (board);
}

void	ft_initialize_board(int ***board, int btype, int *clues)
{
	int	row;
	int	col;
	int	i;

	row = 0;
	while (row < btype)
	{
		col = 0;
		while (col < btype)
			(*board)[row][col++] = 0;
		row++;
	}
	i = 0;
	while (i < btype * btype)
}

void	ft_free_board(int ***board, int btype)
{
	int	row;

	row = 0;
	while (row < btype)
		free((*board)[row++]);
	free((*board));
}
