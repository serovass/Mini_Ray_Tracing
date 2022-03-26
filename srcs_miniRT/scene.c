/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:05:18 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/12 16:39:34 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_init_new_scene(t_scene *scene)
{
	scene->mode = 'c';
	scene->ambient_light = NULL;
	scene->light = NULL;
	scene->camera = NULL;
	scene->obj = NULL;
}

void	ft_check_scene(t_scene *scene)
{
	if (scene->ambient_light == NULL)
		ft_exit_rt("File error: ambient light\n", scene);
	if (scene->light == NULL)
		ft_exit_rt("File error: light\n", scene);
	if (scene->camera == NULL)
		ft_exit_rt("File error: camera\n", scene);
}

void	ft_free_scene(t_scene *scene)
{
	t_object	*tmp;

	if (scene->ambient_light != NULL)
		free(scene->ambient_light);
	if (scene->light != NULL)
		free(scene->light);
	if (scene->camera != NULL)
		free(scene->camera);
	while (scene->obj != NULL)
	{
		tmp = scene->obj;
		scene->obj = tmp->next;
		free(tmp->obj);
		free(tmp);
	}
}

t_object	*ft_add_new_object(t_scene *scene)
{
	t_object	*obj;
	t_object	*tmp;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (NULL);
	obj->obl_id = 0;
	obj->next = NULL;
	if (scene->obj == NULL)
		scene->obj = obj;
	else
	{
		tmp = scene->obj;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = obj;
	}
	return (obj);
}
