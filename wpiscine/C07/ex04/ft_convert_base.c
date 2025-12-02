/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:07:24 by htoe              #+#    #+#             */
/*   Updated: 2025/11/12 22:16:33 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_check_base(char *base)
{
	int	i;
	int	j;

	if (!base || !base[0])
		return (0);
	if (!base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

static int	ft_skip_space(char *str, int *sign)
{
	int	pos;

	pos = 0;
	while (str[pos] == ' ' || (str[pos] >= 9 && str[pos] <= 13))
		pos++;
	*sign = 1;
	while (str[pos] == '+' || str[pos] == '-')
	{
		if (str[pos++] == '-')
			*sign *= -1;
	}
	return (pos);
}

int	ft_check_num(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	
	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
}
