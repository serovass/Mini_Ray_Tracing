/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:07:46 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/11 17:58:47 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_coefficients	ft_get_cylinder_k(t_cylinder *cylinder, t_ray *ray);

static void		ft_check_t(double *t, t_cylinder *cylinder, t_ray *ray)
{
	t_vector q;
	t_vector p;

	p = ft_vector_add(cylinder->center, ft_vector_multiplication(cylinder->orientation, cylinder->height));
	q = ft_vector_add(ray->v_o, ft_vector_multiplication(ray->v_d, *t));

	if (ft_vectors_dot_product(cylinder->orientation, ft_vectors_subtraction(q, cylinder->center)) <= 0)
		*t = -1;
	if (ft_vectors_dot_product(cylinder->orientation, ft_vectors_subtraction(q, p)) >= 0)
		*t = -1;
}

int	ft_intersect_cylinder(t_ray *ray, t_cylinder *cylinder, double *t)
{
	double	t1;
	double	t2;

	t1 = 0;
	t2 = 0;
	if (!ft_get_discriminant(ft_get_cylinder_k(cylinder, ray), &t1, &t2))
		return (0);
	if (t1 > 0)
		ft_check_t(&t1, cylinder, ray);
	if (t2 > 0)
		ft_check_t(&t2, cylinder, ray);
	if (t1 < 0)
	{
		if (t2 < 0)
			return (0);
		*t = t2;
	}
	else
		*t = t1;
	return (1);
}

static t_coefficients	ft_get_cylinder_k(t_cylinder *cylinder, t_ray *ray)
{
	t_vector		v_cy;
	t_vector		right;
	t_coefficients	k;

	v_cy = ft_vectors_subtraction(ray->v_d, \
			ft_vector_multiplication(cylinder->orientation, \
				ft_vectors_dot_product(ray->v_d, cylinder->orientation)));
	k.a = ft_vectors_dot_product(v_cy, v_cy);
	right = ft_vectors_subtraction(\
			ft_vectors_subtraction(ray->v_o, cylinder->center), \
			ft_vector_multiplication(cylinder->orientation, \
				ft_vectors_dot_product(\
					ft_vectors_subtraction(ray->v_o, cylinder->center), \
					cylinder->orientation)));
	k.b = 2 * ft_vectors_dot_product(v_cy, right);
	k.c = ft_vectors_dot_product(right, right) - \
	((cylinder->diametr / 2) * (cylinder->diametr / 2));
	return (k);
}

int	ft_intersect_sphere(t_ray *ray, t_sphere *sphere, double *t)
{
	t_vector		v_sp;
	t_coefficients	k;
	double			t1;
	double			t2;

	t1 = 0;
	t2 = 0;
	v_sp = ft_vectors_subtraction(ray->v_o, sphere->center);
	k.a = ft_vectors_dot_product(ray->v_d, ray->v_d);
	k.b = 2.0 * ft_vectors_dot_product(ray->v_d, v_sp);
	k.c = ft_vectors_dot_product(v_sp, v_sp) - \
	((sphere->diameter / 2) * (sphere->diameter / 2));
	if (!ft_get_discriminant(k, &t1, &t2))
		return (0);
	if (t1 < 0)
	{
		if (t2 < 0)
			return (0);
		*t = t2;
	}
	else
		*t = t1;
	return (1);
}

int	ft_intersect_plane(t_ray *ray, t_plane *plane, double *t)
{
	double		tmp;
	t_vector	v_pl;

	tmp = ft_vectors_dot_product(plane->orientation, ray->v_d);
	if (fabs(tmp) > 1e-6)
	{
		v_pl = ft_vectors_subtraction(plane->center, ray->v_o);
		*t = ft_vectors_dot_product(v_pl, plane->orientation) / tmp;
		if (*t >= 0)
			return (1);
	}
	return (0);
}
