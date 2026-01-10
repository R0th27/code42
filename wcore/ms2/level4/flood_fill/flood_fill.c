/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 01:12:16 by htoe              #+#    #+#             */
/*   Updated: 2026/01/10 03:54:35 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void	fill(char **tab, char target, t_point size, int row, int col)
{
	if (row >= size.y || col >= size.x || col < 0 || row < 0)
		return ;
	if (tab[row][col] != target)
		return ;
	tab[row][col] = 'F';
	fill (tab, target, size, row + 1, col);
	fill (tab, target, size, row - 1, col);
	fill (tab, target, size, row, col + 1);
	fill (tab, target, size, row, col - 1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target;

	if (begin.y >= size.y || begin.x >= size.x)
		return ;
	target = tab[begin.y][begin.x];
	fill(tab, target, size, begin.y, begin.x);
}
