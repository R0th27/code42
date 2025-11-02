/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 05:48:15 by htoe              #+#    #+#             */
/*   Updated: 2025/11/03 05:51:09 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	divisor;

	if (nb <= 0 || nb == 1)
		return (0);
	divisor = 2;
	while (divisor * divisor <= nb)
	{
		if (nb % divisor == 0)
			return (0);
		divisor++;
	}
	return (1);
}
