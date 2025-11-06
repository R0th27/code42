/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:37:56 by htoe              #+#    #+#             */
/*   Updated: 2025/11/06 23:30:07 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_visible_row(int **board, int btype, int row, int *flag);
int	*ft_visible_col(int **board, int btype, int col, int *flag);
int	ft_match(int *clue, int *row_clue, int *col_clue, int flag);

int	ft_clue_check(int **board, int btype, int *clues, int pos)
{
	int	coordinate[2];
	static int	clue[4];
	int	*row_clue;
	int	*col_clue;
	int	flag;

	coordinate[0] = pos / btype;
	coordinate[1] = pos % btype;
	clue[0] = clues[coordinate[0] + (btype * 2)];
	clue[1] = clues[coordinate[0] + (btype * 2) + btype];
	clue[2] = clues[coordinate[1]];
	clue[3] = clues[coordinate[1] + btype];
	flag = 0;
	if (coordinate[1] == btype - 1)
		row_clue = ft_visible_row(board, btype, coordinate[0], &flag);
	if (coordinate[0] == btype - 1)
		col_clue = ft_visible_col(board, btype, coordinate[1], &flag);
	if (ft_match(clue, row_clue, col_clue, flag))
		return (1);
	return (0);
}

int	ft_pos_check(int **board, int btype, int row, int col)
{
	int	constant;

	constant = 0;
	while (constant < btype)
	{
		if (board[row][constant] == board[row][col] && col != constant)
			return (0);
		if (board[constant][col] == board[row][col] && row != constant)
			return (0);
		constant++;
	}
	return (1);
}

int	ft_solve_puzzle(int ***board, int btype, int *clues, int pos)
{
	int	row;
	int	col;
	int	fill;
	int	flag;

	if (pos == btype * btype)
		return (1);
	row = pos / btype;
	col = pos % btype;
	fill = 1;
	while (fill <= btype)
	{
		(*board)[row][col] = fill;
		flag = ft_pos_check(*board, btype, row, col);
		if ((pos % btype == btype - 1 || pos / btype == btype - 1) && flag == 1)
				flag = ft_clue_check(*board, btype, clues, pos);
		if (flag == 1)
		{
			if (ft_solve_puzzle(board, btype, clues, pos + 1))
					return (1);
		}
		(*board)[row][col] = 0;
		fill++;
	}
	return (0);
}
