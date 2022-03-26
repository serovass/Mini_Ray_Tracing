/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:13:09 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/11 18:52:34 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	ft_parse_three_numbers(char *line, double *f, double *s, double *th)
{
	char	**split_line;

	split_line = ft_split(line, ',');
	if (ft_split_line_len(split_line) != 3)
	{
		ft_free_split_line(split_line);
		return (0);
	}
	if (!ft_parse_number(split_line[0], f) || \
			!ft_parse_number(split_line[1], s) || \
			!ft_parse_number(split_line[2], th))
	{
		ft_free_split_line(split_line);
		return (0);
	}
	ft_free_split_line(split_line);
	return (1);
}

int	ft_check_brightness(double *brightness)
{
	if (*brightness < 0.0 || *brightness > 1.0)
		return (0);
	return (1);
}

int	ft_check_view_field(double *view_field)
{
	if (*view_field < 0 || *view_field > 180)
		return (0);
	return (1);
}

int	ft_parse_rgb(char *line, t_rgb *rgb)
{
	if (!ft_parse_three_numbers(line, &rgb->r, &rgb->g, &rgb->b))
		return (0);
	if (rgb->r < 0 || rgb->r > 255 || rgb->g < 0 || \
			rgb->g > 255 || rgb->b < 0 || rgb->b > 255)
		return (0);
	return (1);
}

int	ft_parse_vector(char *line, t_vector *vector, int orientation)
{
	if (!ft_parse_three_numbers(line, &vector->x, &vector->y, &vector->z))
		return (0);
	if (orientation)
	{
		if (vector->x < -1 || vector->x > 1 || vector->y < -1 \
				|| vector->y > 1 || vector->z < -1 || vector->z > 1)
			return (0);
	}
	return (1);
}
