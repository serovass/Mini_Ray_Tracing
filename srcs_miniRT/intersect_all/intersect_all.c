/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:07:14 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/11 17:35:21 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	ft_intersect_obj(t_ray *ray, t_object *object, double *t_obj);

int	ft_intersect_all(t_object *obj, t_ray *ray)
{
	t_object	*tmp;
	double		t_obj;

	ray->closest_obj = NULL;
	tmp = obj;
	while (tmp != NULL)
	{
		if (tmp->obl_id != 1 && ft_intersect_obj(ray, tmp, &t_obj))
		{
			if (t_obj < ray->t_max && t_obj > ray->t_min)
			{
				ray->closest_obj = tmp;
				ray->t_max = t_obj;
			}
		}
		tmp = tmp->next;
	}
	if (ray->closest_obj != NULL)
		return (1);
	else
		return (0);
}

static int	ft_intersect_obj(t_ray *ray, t_object *object, double *t_obj)
{
	if (object->type == SPHERE)
		return (ft_intersect_sphere(ray, (t_sphere *)object->obj, t_obj));
	else if (object->type == PLANE)
		return (ft_intersect_plane(ray, (t_plane *)object->obj, t_obj));
	else if (object->type == CYLINDER)
		return (ft_intersect_cylinder(ray, (t_cylinder *)object->obj, t_obj));
	return (0);
}
