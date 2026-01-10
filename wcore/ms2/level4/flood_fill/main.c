/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 01:15:03 by htoe              #+#    #+#             */
/*   Updated: 2026/01/10 03:54:20 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void	print_tab(char **zone, t_point size)
{
	for (int row = 0; row < size.y; row++)
	{
		for (int col = 0; col < size.x; col++)
		{
			printf("%c",zone[row][col]);
			if (col + 1 != size.x)
				printf(" ");			
		}
		printf("\n");
	}

}

char	**make_area(char **zone, t_point size)
{
	char	**area;
	area = (char **)malloc(sizeof(char *) * size.y);
	if (!area)
		return (NULL);
	for (int i = 0; i < size.y; i++)
	{
		area[i] = (char *)malloc(sizeof(char) * size.x);
		if (!area[i])
		{
			for (i = i; i >= 0; --i)
				free(area[i]);
			free(area);
			return (NULL);
		}
	}
	int i = 0;
	for (int row = 0; row < size.y; row++)
	{
		int j = 0;
		for (int col = 0; col < (2 * size.x); col += 2)
			area[i][j++] = zone[row][col];
		i++;
	}
	return (area);
}

void	free_area(char **area, t_point size)
{
	for (int row = 0; row < size.y; row++)
		free(area[row]);
	free(area);
	area = NULL;
}

int main(void)
{
	char	**area;
	t_point size = {8, 5};
	t_point begin = {2, 2};
	char *zone[] = {
		"1 1 1 0 1 1 1 1",
		"0 0 0 0 1 0 0 1",
		"1 0 0 0 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	};

	area = make_area(zone, size);
	printf("Before\n");
	print_tab(area, size);
	flood_fill(area, size, begin);
	printf("After\n");
	print_tab(area, size);
	free_area(area, size);
	return (0);
}
