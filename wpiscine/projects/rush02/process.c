/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 06:18:59 by htoe              #+#    #+#             */
/*   Updated: 2025/12/05 09:44:11 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	search_tens(char tens, char units, t_list *entries)
{
	char	unit;

	if (tens == '0')
		return (1);
	else if (tens == '1')
		unit = units;
	else
		unit = '0';
	while (entries)
	{
		if (tens == entries -> key[0])
		{
			if (unit == entries -> key[1])
			{
				ft_putstr(entries -> value);
				if (tens == '1')
					ft_putstr(" ");
				else if (units != '0')
					ft_putstr("-");
				return (1);
			}
		}
		entries = entries -> next;
	}
	return (0);
}

char	*search_suffix(int suffix, t_list *entries)
{
	char	*sample;
	int		i;

	if (suffix == 0)
		return (NULL);
	sample = suffix_initializer(suffix);
	while (entries)
	{
		if (sample[0] == entries -> key [0])
		{
			i = 0;
			while (entries -> key[i] && sample[i] && sample[i] == entries -> key[i])
				i++;
			if (!entries -> key[i] && !sample[i])
			{
				free(sample);
				return (entries -> value);
			}
		}
		entries = entries -> next;
	}
	free(sample);
	return (NULL);
}

int	search_placement(char number, int suffix, t_list *entries)
{
	char	*suffix_text;

	suffix_text = search_suffix(suffix, entries);
	if (number == '0' && suffix == 2)
		return (1);
	while (entries)
	{
		if (number == entries -> key[0])
		{
			if (number == '0' && suffix == 0)
				ft_putstr(entries -> value);
			else if (number != '0')
				ft_putstr(entries -> value);
			if (suffix != 0)
			{
				ft_putstr(" ");
				ft_putstr(suffix_text);
				if (suffix != 2)
					ft_putstr(",");
				ft_putstr(" ");
			}
			else
				ft_putstr("\n");
			return (1);
		}
		entries = entries -> next;
	}
	return (0);
}

int	search_and_query(char *input, t_list *entries, int len)
{
	int		i;
	int		result;

	i = 0;
	result = 1;
	while (input[i] && result)
	{
		if ((len - i) % 3 == 0)
			result = search_placement(input[i], len - i, entries);
		if ((len - i) % 3 == 1)
			result = search_tens(input[i], input[i + 1], entries);
		if ((len - i) % 3 == 2)
			result = search_placement(input[i], 2, entries);
		i++;
	}
	return (result);
}

int	process(char *input, t_list *entries, int type)
{
	int	result;
	int	len;

	len = 0;
	while (input[len])
		len++;
	len--;
	if (type == 2)
		printf("still implementing for stdin\n");
	else
		result = search_and_query(input, entries, len);
	if (!result)
		ft_putstr("Error\n");
	return (result);
}
