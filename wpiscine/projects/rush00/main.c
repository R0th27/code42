/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 07:44:35 by htoe              #+#    #+#             */
/*   Updated: 2025/11/03 08:37:00 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);
void	ft_putchar(char c, int count);

int	main(void)
{
	rush(5, 5);
	ft_putchar('\n', 1);
	rush(1, 1);
	ft_putchar('\n', 1);
	rush(2, 1);
	ft_putchar('\n', 1);
	rush(1, 2);
	ft_putchar('\n', 1);
	rush(3, 2);
	ft_putchar('\n', 1);
	rush(2, 3);
	ft_putchar('\n', 1);
	return (0);
}
