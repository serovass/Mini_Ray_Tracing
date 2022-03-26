/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:15:20 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/12 15:52:37 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_vector	ft_get_sphere_n(t_vector v_p, t_sphere *sphere);
static t_vector	ft_get_plane_n(t_plane *plane);
static t_vector	ft_get_cylinder_n(t_vector v_p, t_cylinder *cylinder);

t_vector	ft_get_normal(t_vector v_p, t_object *obj)
{
	if (obj->type == SPHERE)
		return (ft_get_sphere_n(v_p, (t_sphere *)obj->obj));
	else if (obj->type == PLANE)
		return (ft_get_plane_n((t_plane *)obj->obj));
	else if (obj->type == CYLINDER)
		return (ft_get_cylinder_n(v_p, (t_cylinder *)obj->obj));
	return ((t_vector){0, 0, 0});
}

static t_vector	ft_get_sphere_n(t_vector v_p, t_sphere *sphere)
{
	t_vector	v_n;

	v_n = ft_vectors_subtraction(v_p, sphere->center);
	ft_vector_normalization(&v_n);
	return (v_n);
}

static t_vector	ft_get_plane_n(t_plane *plane)
{
	return (plane->orientation);
}

static t_vector	ft_get_cylinder_n(t_vector v_p, t_cylinder *cylinder)
{
	t_vector	tmp_1;
	t_vector	tmp_2;
	t_vector	v_n;

	tmp_1 = ft_vectors_subtraction(v_p, cylinder->center);
	tmp_2 = ft_vector_multiplication(cylinder->orientation, \
	ft_vectors_dot_product(cylinder->orientation, tmp_1));
	v_n = ft_vectors_subtraction(tmp_1, tmp_2);
	ft_vector_normalization(&v_n);
	return (v_n);
}
