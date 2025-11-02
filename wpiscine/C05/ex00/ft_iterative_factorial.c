/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 05:00:38 by htoe              #+#    #+#             */
/*   Updated: 2025/11/03 05:34:44 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	if (nb > 12 || nb < 0)
		return (0);
	i = 0;
	result = 1;
	while ((nb - i) > 0)
		result *= (nb - i++);
	return (result);
}
