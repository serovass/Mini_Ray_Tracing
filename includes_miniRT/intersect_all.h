/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_all.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:07:31 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/12 19:17:23 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_ALL_H
# define INTERSECT_ALL_H

typedef struct s_coefficients	t_coefficients;

struct s_coefficients
{
	double	a;
	double	b;
	double	c;
};

int	ft_intersect_all(t_object *obj, t_ray *ray);
int	ft_get_discriminant(t_coefficients k, double *t1, double *t2);
int	ft_intersect_cylinder(t_ray *ray, t_cylinder *cylinder, double *t);
int	ft_intersect_sphere(t_ray *ray, t_sphere *sphere, double *t);
int	ft_intersect_plane(t_ray *ray, t_plane *plane, double *t);

#endif
