/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:17:26 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/12 15:49:55 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_ray	ft_get_shadow_ray(t_vector v_p, t_vector v_l);
static void		ft_chek_shadow(t_color *color, \
		t_object *obj_list, t_object *closest_obj, t_ray l_ray);
static double	ft_get_diffuse_lighting(t_light *light, \
		t_vector v_n, t_vector v_l);
static double	ft_get_highlight(t_light *light, \
		t_vector v_n, t_vector v_l, t_vector v_v);

t_rgb	ft_compute_lighting(t_scene *scene, t_ray *ray, t_color color)
{
	t_vector	v_p;
	t_vector	v_n;
	t_vector	v_v;
	t_vector	v_l;

	v_p = ft_vector_add(ray->v_o, \
			ft_vector_multiplication(ray->v_d, ray->t_max));
	v_n = ft_get_normal(v_p, ray->closest_obj);
	v_v = ft_vector_multiplication(ray->v_d, -1);
	v_l = ft_vectors_subtraction(scene->light->light_point, v_p);
	ft_chek_shadow(&color, scene->obj, ray->closest_obj, \
			ft_get_shadow_ray(v_p, v_l));
	color.brightness += ft_get_diffuse_lighting(scene->light, v_n, v_l);
	color.brightness += ft_get_highlight(scene->light, v_n, v_l, v_v);
	color.l_rgb = ft_color_coefficient(scene->light->rgb, color.brightness);
	color.obj_rgb = ft_color_coefficient(ray->closest_obj->rgb, \
			color.brightness);
	return (ft_color_coefficient(ft_3color_mix(color.amb_rgb, \
					color.l_rgb, color.obj_rgb), color.shadow));
}

static t_ray	ft_get_shadow_ray(t_vector v_p, t_vector v_l)
{
	t_ray	l_ray;

	l_ray.v_o = v_p;
	l_ray.v_d = v_l;
	l_ray.t_max = HUGE_VAL;
	l_ray.t_min = 0;
	return (l_ray);
}

static void	ft_chek_shadow(t_color *color, t_object *obj_list, \
		t_object *closest_obj, t_ray l_ray)
{
	closest_obj->obl_id = 1;
	if (ft_intersect_all(obj_list, &l_ray) != 0)
		color->shadow = 0.5;
	closest_obj->obl_id = 0;
}

static double	ft_get_diffuse_lighting(t_light *light, \
		t_vector v_n, t_vector v_l)
{
	double	n_dot_l;

	n_dot_l = ft_vectors_dot_product(v_n, v_l);
	if (n_dot_l > 0)
		return (light->brightness * n_dot_l / \
				(ft_get_vector_leangth(v_n) * ft_get_vector_leangth(v_l)));
	return (0);
}

static double	ft_get_highlight(t_light *light, \
		t_vector v_n, t_vector v_l, t_vector v_v)
{
	t_vector	v_r;
	t_vector	tmp;
	double		r_dot_v;

	tmp = ft_vector_multiplication(v_n, 2 * ft_vectors_dot_product(v_n, v_l));
	v_r = ft_vectors_subtraction(tmp, v_l);
	r_dot_v = ft_vectors_dot_product(v_r, v_v);
	if (r_dot_v > 0)
		return (light->brightness * pow(r_dot_v / (ft_get_vector_leangth(v_r) \
						* ft_get_vector_leangth(v_v)), 50));
	return (0);
}	
