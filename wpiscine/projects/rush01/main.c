/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 01:17:11 by htoe              #+#    #+#             */
/*   Updated: 2025/11/05 20:43:56 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char *c, int size);
int		**ft_create_board(int btype);
void	ft_initialize_board(int ***board, int btype, int *clues);
void	ft_print_board(int **board, int btype);
void	ft_free_board(int ***board, int btype);
int		ft_solve_puzzle(int ***board, int btype, int *clues);

int	ft_len_check(char *str)
{
	int	btype;
	int	total;

	total = 0;
	btype = 0;
	while (str[btype])
	{
		if (str[btype++] != ' ')
			total++;
	}
	btype = 4;
	while (btype < 10)
	{
		if (btype * 4 == total)
			return (btype);
		btype++;
	}
	ft_putchar("Error\n", 6);
	return (0);
}

int	ft_input_check(char *argv, int *clues)
{
	int	btype;
	int	index;
	int	i;

	btype = ft_len_check(argv);
	if (!btype)
		return (0);
	index = 0;
	i = 0;
	while (argv[i])
	{
		if (argv[i] != ' ')
		{
			if (argv[i] >= '1' && argv[i] <= btype + '0')
				clues[index++] = argv[i] - '0';
			else
			{
				ft_putchar("Error\n", 6);
				return (0);
			}
		}
		i++;
	}
	return (btype);
}

int	main(int argc, char **argv)
{
	int	clues[36];
	int	btype;
	int	**board;
	//int	solve;

	if (argc != 2)
	{
		ft_putchar("Error\n", 6);
		return (1);
	}
	btype = ft_input_check(argv[1], clues);
	if (!btype)
		return (1);
	board = ft_create_board(btype);
	if (!board)
		return (1);
	ft_initialize_board(&board, btype, clues);
	solve = ft_solve_puzzle(&board, btype, clues);
	//if (solve)
	ft_print_board(board, btype);
	ft_free_board(&board, btype);
	return (0);
}
