/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:10:47 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/11 18:24:41 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	ft_add_new_light(t_scene *scene)
{
	t_light	*light;

	if (scene->light != NULL)
		return (0);
	light = malloc(sizeof(t_light));
	if (!light)
		return (0);
	scene->light = light;
	return (1);
}

int	ft_parse_light(char *line, t_scene *scene)
{
	char	**split_line;

	if (!ft_add_new_light(scene))
		return (0);
	split_line = ft_split(line, ' ');
	if (ft_split_line_len(split_line) != 4)
	{
		ft_free_split_line(split_line);
		return (0);
	}
	if (!ft_parse_vector(split_line[1], &scene->light->light_point, 0) \
			|| !ft_parse_number(split_line[2], &scene->light->brightness) \
			|| !ft_check_brightness(&scene->light->brightness) \
			|| !ft_parse_rgb(split_line[3], &scene->light->rgb))
	{
		ft_free_split_line(split_line);
		return (0);
	}
	ft_free_split_line(split_line);
	return (1);
}
