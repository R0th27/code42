/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 07:46:47 by htoe              #+#    #+#             */
/*   Updated: 2025/11/03 08:42:58 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c, int count);

static void	ft_row(int col, char corner1, char corner2, char mid)
{
	if (col > 0)
	{
		ft_putchar(corner1, 1);
		if (col - 2 > 0)
			ft_putchar(mid, col - 2);
		if (col - 1 > 0)
			ft_putchar(corner2, 1);
	}
	ft_putchar('\n', 1);
}

static void	ft_mid(int row, int col, char side)
{
	while (row > 0)
	{
		if (col > 0)
		{
			ft_putchar(side, 1);
			if (col - 2 > 0)
				ft_putchar(' ', col - 2);
			if (col - 1 > 0)
				ft_putchar(side, 1);
		}
		ft_putchar('\n', 1);
		row--;
	}
}

void	rush(int x, int y)
{
	int	row;

	row = 0;
	if (x <= 0 || y <= 0)
		return ;
	if (row < y)
	{
		ft_row(x, 'A', 'C', 'B');
		if (row + 2 < y)
		{
			row = y - 2;
			ft_mid(row, x, 'B');
		}
		if (row + 1 == y - 1)
			ft_row(x, 'C', 'A', 'B');
	}
}
