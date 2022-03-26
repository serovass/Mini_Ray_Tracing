/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:09:47 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/11 18:16:12 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	ft_add_new_camera(t_scene *scene)
{
	t_camera	*camera;

	if (scene->camera != NULL)
		return (0);
	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (0);
	scene->camera = camera;
	return (1);
}

int	ft_parse_camera(char *line, t_scene *scene)
{
	char	**split_line;

	if (!ft_add_new_camera(scene))
		return (0);
	split_line = ft_split(line, ' ');
	if (ft_split_line_len(split_line) != 4)
	{
		ft_free_split_line(split_line);
		return (0);
	}
	if (!ft_parse_vector(split_line[1], &scene->camera->view_point, 0) \
			|| !ft_parse_vector(split_line[2], &scene->camera->orientation, 1) \
			|| !ft_parse_number(split_line[3], &scene->camera->view_field) \
			|| !ft_check_view_field(&scene->camera->view_field))
	{
		ft_free_split_line(split_line);
		return (0);
	}
	ft_free_split_line(split_line);
	ft_vector_normalization(&scene->camera->orientation);
	return (1);
}
