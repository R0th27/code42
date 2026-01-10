/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:21:31 by htoe              #+#    #+#             */
/*   Updated: 2025/12/26 16:30:12 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	num;

	if (ac != 2 || av[1][0] < '0' || av[1][0] > '9')
		return (printf("\n"), 1);
	num = atoi(av[1]);
	if (num < 0)
		return (printf("\n"), 1);
	if (num == 0 || num == 1 || num == 2 || num == 3)
		return (printf("%d\n", num), 0);
	printf("num: %d\n", num);
	return (printf("\n"), 0);
}
