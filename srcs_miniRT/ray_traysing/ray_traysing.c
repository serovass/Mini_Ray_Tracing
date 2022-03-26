/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_traysing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:15:40 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/12 16:13:54 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_ray		ft_get_ray(double x, double y, double fov_coeff, \
		t_look_at *look_at);
static int			ft_ray_traysing_color(t_scene *scene, t_ray	ray);
static t_look_at	*ft_get_look_at(t_vector *camera, t_vector *orientation);
static t_vector		ft_look_at_ray(t_vector ray, t_look_at *look_at);

void	ft_ray_traysing_start(t_scene *scene, void *mlx_ptr, void *win_ptr)
{
	int			mlx_x;
	int			mlx_y;
	double		fov_coeff;
	t_look_at	*look_at;

	fov_coeff = tan(scene->camera->view_field / 2 * M_PI / 180);
	look_at = ft_get_look_at(&scene->camera->view_point, \
			&scene->camera->orientation);
	mlx_y = 0;
	while (mlx_y < HIGHT)
	{
		mlx_x = 0;
		while (mlx_x < WIDTH)
		{
			my_mlx_pixel_put(scene, mlx_x, mlx_y, \
					ft_ray_traysing_color(scene, ft_get_ray(mlx_x, mlx_y, \
							fov_coeff, look_at)));
			mlx_x++;
		}
		mlx_y++;
	}
	free(look_at);
	mlx_put_image_to_window(mlx_ptr, win_ptr, scene->img->img, 0, 0);
}

static t_look_at	*ft_get_look_at(t_vector *camera, t_vector *orientation)
{
	t_look_at	*look_at;

	look_at = malloc(sizeof(t_look_at));
	look_at->right = ft_vectors_cross_product((t_vector){0, 1, 0}, \
			*orientation);
	ft_vector_normalization(&look_at->right);
	look_at->up = ft_vectors_cross_product(*orientation, look_at->right);
	ft_vector_normalization(&look_at->up);
	look_at->camera = *camera;
	look_at->orientation = *orientation;
	return (look_at);
}

static t_vector	ft_look_at_ray(t_vector ray, t_look_at *look_at)
{
	t_vector	new_ray;

	new_ray.x = (ray.x * look_at->right.x) + (ray.y * look_at->up.x) + \
				(ray.z * look_at->orientation.x) + look_at->camera.x;
	new_ray.y = (ray.x * look_at->right.y) + (ray.y * look_at->up.y) + \
				(ray.z * look_at->orientation.y) + look_at->camera.y;
	new_ray.z = (ray.x * look_at->right.z) + (ray.y * look_at->up.z) + \
				(ray.z * look_at->orientation.z) + look_at->camera.z;
	return (new_ray);
}

static t_ray	ft_get_ray(double x, double y, \
		double fov_coeff, t_look_at *look_at)
{
	double	p_x;
	double	p_y;
	t_ray	ray;

	p_x = (2 * x / (double)WIDTH - 1) * (double)WIDTH / (double)HIGHT * \
	fov_coeff;
	p_y = (1 - 2 * y / (double)HIGHT) * fov_coeff;
	ray.v_d = ft_new_vector(p_x, p_y, 1);
	ray.v_o = ft_look_at_ray((t_vector){0, 0, 0}, look_at);
	ray.v_d = ft_look_at_ray(ray.v_d, look_at);
	ray.v_d = ft_vectors_subtraction(ray.v_d, ray.v_o);
	ray.t_max = HUGE_VAL;
	ray.t_min = 0.01;
	ft_vector_normalization(&ray.v_d);
	return (ray);
}

static int	ft_ray_traysing_color(t_scene *scene, t_ray	ray)
{
	t_color	color;

	if (ft_intersect_all(scene->obj, &ray))
	{
		color.shadow = 1;
		color.brightness = scene->ambient_light->brightness;
		color.amb_rgb = ft_color_coefficient(scene->ambient_light->rgb, \
				scene->ambient_light->brightness);
		return (ft_create_trgb(0, ft_compute_lighting(scene, &ray, color)));
	}
	else
		return (0);
}
