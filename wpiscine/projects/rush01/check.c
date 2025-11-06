/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:57:02 by htoe              #+#    #+#             */
/*   Updated: 2025/11/06 23:44:53 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_match(int *clue, int *row_clue, int *col_clue, int flag)
{
	if (flag == 1)
	{
		if (clue[0] == row_clue[0] && clue[1] == row_clue[1])
			return (1);
	}
	if (flag == 2)
	{
		if (clue[2] == col_clue[0] && clue[3] == col_clue[1])
			return (1);
	}
	else
	{
		if (clue[0] == row_clue[0] && clue[1] == row_clue[1]
			&& clue[2] == col_clue[0] && clue[3] == col_clue[1])
			return (1);
	}
	return (0);
}

int	ft_compare(int sample, int *highest)
{
	if (sample <= *highest)
		return (0);
	*highest = sample;
	return (1);
}

int	*ft_visible_col(int **board, int btype, int col, int *flag)
{
	static int	col_c[2];
	int			visibility;
	int			variable;
	int			highest;

	variable = 0;
	visibility = 1;
	highest = board[variable][col];
	while (variable < btype)
	{
		visibility += ft_compare(board[variable][col], &highest);
		variable++;
	}
	col_c[0] = visibility;
	visibility = 1;
	highest = board[--variable][col];
	while (variable >= 0)
	{
		visibility += ft_compare(board[variable][col], &highest);
		variable--;
	}
	col_c[1] = visibility;
	*flag += 2;
	return (col_c);
}

int	*ft_visible_row(int **board, int btype, int row, int *flag)
{
	static int	row_c[2];
	int			visibility;
	int			variable;
	int			highest;

	variable = 0;
	visibility = 1;
	highest = board[row][variable];
	while (variable < btype)
	{
		visibility += ft_compare(board[row][variable], &highest);
		variable++;
	}
	row_c[0] = visibility;
	visibility = 1;
	highest = board[row][--variable];
	while (variable >= 0)
	{
		visibility += ft_compare(board[row][variable], &highest);
		variable--;
	}
	row_c[1] = visibility;
	*flag += 1;
	return (row_c);
}
