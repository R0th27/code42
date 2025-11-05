/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:26:20 by htoe              #+#    #+#             */
/*   Updated: 2025/11/05 20:40:07 by htoe             ###   ########.fr       */
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

void	ft_easy_clues2(int ***board, int index, int btype, int step)
{
	int	fill;
	int	constant;
	int	variable;
	int	flag;

	flag = 2 * (index / (btype * 2));
	constant = index % btype;
	variable = ((index / btype) - flag) * (btype - 1);
	fill = 1;
	while (fill <= btype)
	{
		if (index < btype * 2)
			(*board)[variable][constant] = fill;
		else
			(*board)[constant][variable] = fill;
		variable += step;
		fill++;
	}
}

void	ft_easy_clue1(int ***board, int btype, int *clues)
{
	int	index;
	int	step;
	int	constant;
	int	variable;
	int	flag;

	index = 0;
	while (index < btype * btype)
	{
		flag = 2 * (index / (btype * 2));
		constant = index % btype;
		variable = ((index / btype) - flag) * (btype - 1);
		step = (-2 * ((index / btype) - flag)) + 1;
		if (clues[index] == 1)
		{
			if (index < btype * 2)
				(*board)[variable][constant] = btype;
			else
				(*board)[constant][variable] = btype;
		}
		if (clues[index] == btype)
			ft_easy_clues2(board, index, btype, step);
		index++;
	}
}

void	ft_initialize_board(int ***board, int btype, int *clues)
{
	int	row;
	int	col;

	row = 0;
	while (row < btype)
	{
		col = 0;
		while (col < btype)
			(*board)[row][col++] = 0;
		row++;
	}
	ft_easy_clue1(board, btype, clues);
}

void	ft_free_board(int ***board, int btype)
{
	int	row;

	row = 0;
	while (row < btype)
		free((*board)[row++]);
	free((*board));
}
