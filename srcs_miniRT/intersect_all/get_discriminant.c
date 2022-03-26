/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_discriminant.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:06:55 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/11 17:33:40 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	ft_swap_num(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_get_discriminant(t_coefficients k, double *t1, double *t2)
{
	double	d;

	d = pow(k.b, 2) - 4 * k.a * k.c;
	if (d < 0)
		return (0);
	else if (d == 0)
	{
		*t1 = -k.b / (2 * k.a);
		*t2 = *t1;
	}
	else
	{
		*t1 = (-k.b + sqrt(d)) / (2 * k.a);
		*t2 = (-k.b - sqrt(d)) / (2 * k.a);
	}
	if (*t1 > *t2)
		ft_swap_num(t1, t2);
	return (1);
}
