/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:11:49 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/11 18:35:33 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_object	*ft_add_new_sp(t_scene *scene, t_sphere *sphere)
{
	t_object	*obj;

	if (!sphere)
		return (NULL);
	obj = ft_add_new_object(scene);
	if (!obj)
		return (NULL);
	obj->type = SPHERE;
	obj->obj = sphere;
	return (obj);
}

int	ft_parse_sp(char *line, t_scene *scene)
{
	char		**split_line;
	t_object	*obj;
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	obj = ft_add_new_sp(scene, sphere);
	if (!obj)
		return (0);
	split_line = ft_split(line, ' ');
	if (ft_split_line_len(split_line) != 4)
	{
		ft_free_split_line(split_line);
		return (0);
	}
	if (!ft_parse_vector(split_line[1], &sphere->center, 0) \
			|| !ft_parse_number(split_line[2], &sphere->diameter) \
			|| !ft_parse_rgb(split_line[3], &obj->rgb))
	{
		ft_free_split_line(split_line);
		return (0);
	}
	ft_free_split_line(split_line);
	return (1);
}
