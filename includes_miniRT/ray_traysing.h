/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_traysing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:11:42 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/12 19:16:02 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRAYSING_H
# define RAY_TRAYSING_H

typedef struct s_ray		t_ray;
typedef struct s_view_plane	t_view_plane;
typedef struct s_look_at	t_look_at;
typedef struct s_color		t_color;

struct s_view_plane
{
	double	width;
	double	hight;
	double	x_pixel;
	double	y_pixel;
};

struct s_look_at
{
	t_vector	right;
	t_vector	up;
	t_vector	camera;
	t_vector	orientation;
};

struct s_color
{
	double	shadow;
	double	brightness;
	t_rgb	amb_rgb;
	t_rgb	obj_rgb;
	t_rgb	l_rgb;
};

struct s_ray
{
	t_vector	v_o;
	t_vector	v_d;
	t_object	*closest_obj;
	double		closest_t;
	double		t_max;
	double		t_min;
};

void		ft_ray_traysing_start(t_scene *scene, void *mlx_ptr, void *win_ptr);
t_rgb		ft_compute_lighting(t_scene *scene, t_ray *ray, t_color bright);
t_vector	ft_get_normal(t_vector v_p, t_object *obj);
int			ft_create_trgb(int t, t_rgb color);
t_rgb		ft_color_coefficient(t_rgb color, double k);
t_rgb		ft_3color_mix(t_rgb c1, t_rgb c2, t_rgb c3);

#endif
