/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:11:16 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/11 18:26:34 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	ft_get_num(char *str, double *num)
{
	size_t	i;
	double	j;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9' && i < 5)
	{
		*num = *num * 10 + (str[i] - '0');
		i++;
	}
	if (i != 0 && str[i] == '.')
	{
		j = 10;
		i++;
		while (str[i] >= '0' && str[i] <= '9' && j < 1000)
		{
			*num = *num + ((str[i] - '0') / j);
			i++;
			j *= 10;
		}
	}
	if (i == 0 || str[i] != '\0')
		return (0);
	return (1);
}

int	ft_parse_number(char *str, double *num)
{
	size_t	i;
	int		minus;

	*num = 0;
	minus = 1;
	i = 0;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	if (!ft_get_num(&str[i], num))
		return (0);
	*num *= minus;
	return (1);
}
