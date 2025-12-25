/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 21:38:48 by htoe              #+#    #+#             */
/*   Updated: 2025/12/24 21:58:37 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	start;
	int	end;

	if (ac == 2)
	{
		end = 0;
		while (av[1][end])
			end++;
		if (end--)
		{
			while (end > 0 && (av[1][end] == ' ' || (av[1][end] >= 9 && av[1][end] <= 13)))
				end--;
			start = end;
			while (start >= 0 && av[1][start] != ' ' && (av[1][start] < 9 || av[1][start] > 13))
				start--;
			while (++start <= end)
				write(1, &av[1][start], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
