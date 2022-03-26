/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquirinu <tquirinu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:05:48 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/19 16:17:30 by tquirinu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	my_mlx_pixel_put(t_scene *scene, int x, int y, int color)
{
	char	*dst;

	if (y >= HIGHT || x >= WIDTH || y < 1 || x < 1)
		return ;
	dst = scene->img->addr + (y * scene->img->line_length + x \
	* (scene->img->bits_per_pixel >> 3));
	*(unsigned int *)dst = color;
}

static void	ft_move_coordinate(int key, t_vector *coordinate)
{
	if (key == 123)
		coordinate->x -= 0.5;
	else if (key == 124)
		coordinate->x += 0.5;
	else if (key == 125)
		coordinate->y -= 0.5;
	else if (key == 126)
		coordinate->y += 0.5;
	else if (key == 27)
		coordinate->z -= 0.5;
	else if (key == 24)
		coordinate->z += 0.5;
}

int	ft_deal_key(int key, t_scene *scene)
{
	if (key == 8)
		scene->mode = 'c';
	else if (key == 37)
		scene->mode = 'l';
	else if (key == 9)
		scene->mode = 'v';
	else if (key > 100 || key == 27 || key == 24)
	{
		if (scene->mode == 'v')
		{
			ft_move_coordinate(key, &scene->camera->orientation);
			ft_vector_normalization(&scene->camera->orientation);
		}
		else if (scene->mode == 'c')
			ft_move_coordinate(key, &scene->camera->view_point);
		else if (scene->mode == 'l')
			ft_move_coordinate(key, &scene->light->light_point);
		ft_ray_traysing_start(scene, scene->mlx_ptr, scene->win_ptr);
	}
	else if (key == 53)
		ft_exit_rt("", scene);
	return (0);
}
