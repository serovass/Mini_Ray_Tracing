/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:09:29 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/11 18:11:54 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	ft_add_new_ambient_light(t_scene *scene)
{
	t_ambient_light	*ambient_light;

	if (scene->ambient_light != NULL)
		return (0);
	ambient_light = malloc(sizeof(t_ambient_light));
	if (!ambient_light)
		return (0);
	scene->ambient_light = ambient_light;
	return (1);
}

int	ft_parse_ambient_light(char *line, t_scene *scene)
{
	char	**split_line;

	if (!ft_add_new_ambient_light(scene))
		return (0);
	split_line = ft_split(line, ' ');
	if (ft_split_line_len(split_line) != 3)
	{
		ft_free_split_line(split_line);
		return (0);
	}
	if (!ft_parse_number(split_line[1], &scene->ambient_light->brightness) \
			|| !ft_check_brightness(&scene->ambient_light->brightness) \
			|| !ft_parse_rgb(split_line[2], &scene->ambient_light->rgb))
	{
		ft_free_split_line(split_line);
		return (0);
	}
	ft_free_split_line(split_line);
	return (1);
}
