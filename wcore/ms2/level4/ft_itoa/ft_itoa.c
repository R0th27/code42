/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 07:04:46 by htoe              #+#    #+#             */
/*   Updated: 2026/01/10 07:52:05 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	fill_num(char *num, int *arr, int index, int flag)
{
	int	i;

	num[index + flag] = '\0';
	i = 0;
	if (flag)
		num[i++] = '-';
	while (index > 0)
		num[i++] = arr[--index] + '0';
}

char	*ft_itoa(int nbr)
{
	char	*num;
	int		arr[10];
	int		i;
	long	nb;

	nb = nbr;
	if (nbr < 0)
		nb *= -1;
	i = 0;
	if (nb == 0)
		arr[i++] = 0;
	while (nb)
	{
		arr[i++] = nb % 10;
		nb /= 10;
	}
	if (nbr >= 0)
		num = (char *)malloc(sizeof(char) * (i + 1));
	else
		num = (char *)malloc(sizeof(char) * (i + 2));
	if (!num)
		return (NULL);
	fill_num(num, arr, i, nbr < 0);
	return (num);
}

int	main(int ac, char **av)
{
	int		nb;
	char	*nbr;

	if (ac != 2 || !av[1][0])
		return (printf("\n"), 1);
	nb = atoi(av[1]);
	nbr = ft_itoa(nb);
	printf("%s\n", nbr);
	free(nbr);
	return (0);
}
