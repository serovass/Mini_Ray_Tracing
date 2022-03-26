/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_functions_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:16:51 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/12 16:49:58 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	ft_new_vector(double x, double y, double z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

double	ft_get_vector_leangth(t_vector vector)
{
	return (sqrt(vector.x * vector.x + \
				vector.y * vector.y + vector.z * vector.z));
}

void	ft_vector_normalization(t_vector *vector)
{
	double	len;

	len = sqrt(vector->x * vector->x + \
			vector->y * vector->y + vector->z * vector->z);
	vector->x = vector->x / len;
	vector->y = vector->y / len;
	vector->z = vector->z / len;
}
