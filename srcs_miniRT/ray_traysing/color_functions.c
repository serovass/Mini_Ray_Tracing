/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:14:52 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/11 19:12:00 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_create_trgb(int t, t_rgb color)
{
	if (color.r > 255)
		color.r = 255;
	if (color.g > 255)
		color.g = 255;
	if (color.b > 255)
		color.b = 255;
	return (t << 24 | (int)color.r << 16 \
	| (int)color.g << 8 | (int)color.b);
}

t_rgb	ft_color_coefficient(t_rgb color, double k)
{
	color.r *= k;
	color.g *= k;
	color.b *= k;
	return (color);
}

t_rgb	ft_3color_mix(t_rgb c1, t_rgb c2, t_rgb c3)
{
	double	r;
	double	g;
	double	b;
	t_rgb	color;

	r = c1.r + c2.r + c3.r;
	g = c1.g + c2.g + c3.g;
	b = c1.b + c2.b + c3.b;
	color.r = (c1.r * c1.r + c2.r * c2.r + c3.r * c3.r) / r;
	color.g = (c1.g * c1.g + c2.g * c2.g + c3.g * c3.g) / g;
	color.b = (c1.b * c1.b + c2.b * c2.b + c3.b * c3.b) / b;
	return (color);
}
