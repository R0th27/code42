/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 01:10:04 by htoe              #+#    #+#             */
/*   Updated: 2026/01/10 01:50:33 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOD_FILL_H
#define FLOOD_FILL_H

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	flood_fill(char **tab, t_point size, t_point begin);

#endif