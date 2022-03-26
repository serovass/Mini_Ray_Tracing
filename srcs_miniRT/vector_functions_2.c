/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:17:05 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/12 19:19:16 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	ft_vector_multiplication(t_vector vector, double d)
{
	t_vector	new;

	new.x = vector.x * d;
	new.y = vector.y * d;
	new.z = vector.z * d;
	return (new);
}

t_vector	ft_vector_add(t_vector vector_1, t_vector vector_2)
{
	t_vector	new;

	new.x = vector_1.x + vector_2.x;
	new.y = vector_1.y + vector_2.y;
	new.z = vector_1.z + vector_2.z;
	return (new);
}

t_vector	ft_vectors_subtraction(t_vector vector_1, t_vector vector_2)
{
	t_vector	result;

	result = ft_new_vector(vector_1.x - vector_2.x, \
			vector_1.y - vector_2.y, vector_1.z - vector_2.z);
	return (result);
}

double	ft_vectors_dot_product(t_vector vector_1, t_vector vector_2)
{
	double	result;

	result = ((vector_1.x * vector_2.x) + (vector_1.y * vector_2.y) \
			+ (vector_1.z * vector_2.z));
	return (result);
}

t_vector	ft_vectors_cross_product(t_vector vector_1, t_vector vector_2)
{
	t_vector	vector;
	double		x;
	double		y;
	double		z;

	x = (vector_1.y * vector_2.z) - (vector_1.z * vector_2.y);
	y = (vector_1.z * vector_2.x) - (vector_1.x * vector_2.z);
	z = (vector_1.x * vector_2.y) - (vector_1.y * vector_2.x);
	vector = ft_new_vector(x, y, z);
	return (vector);
}
