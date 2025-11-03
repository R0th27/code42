/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 05:54:25 by htoe              #+#    #+#             */
/*   Updated: 2025/11/03 07:36:50 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_check_safe(int row, int *board)
{
	int	testrow;

	testrow = 0;
	while (testrow < row)
	{
		if (testrow != row)
		{
			if (board[testrow] == board[row]
				|| board[testrow] == board[row] - (row - testrow)
				|| board[testrow] == board[row] + (row - testrow))
				return (0);
		}
		testrow++;
	}
	return (1);
}

static void	ft_print_board(int *board)
{
	int		row;
	char	c;

	row = 0;
	while (row < 10)
	{
		c = board[row++] + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

static void	ft_solve(int *board, int row, int *solutions)
{
	int	col;

	if (row == 10)
	{
		ft_print_board(board);
		solutions[0]++;
		return ;
	}
	col = 0;
	while (col < 10)
	{
		board[row] = col;
		if (ft_check_safe(row, board))
			ft_solve(board, row + 1, solutions);
		col++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	solutions;
	int	row;
	int	board[10];

	solutions = 0;
	row = 0;
	ft_solve(board, row, &solutions);
	return (solutions);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("solutions: %d\n", ft_ten_queens_puzzle());
	return (0);
}
*/