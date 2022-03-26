/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:11:33 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/11 18:30:29 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_object	*ft_add_new_pl(t_scene *scene, t_plane *plane)
{
	t_object	*obj;

	if (!plane)
		return (NULL);
	obj = ft_add_new_object(scene);
	if (!obj)
		return (NULL);
	obj->type = PLANE;
	obj->obj = plane;
	return (obj);
}

int	ft_parse_pl(char *line, t_scene *scene)
{
	char		**split_line;
	t_object	*obj;
	t_plane		*plane;

	plane = malloc(sizeof(t_plane));
	obj = ft_add_new_pl(scene, plane);
	if (!obj)
		return (0);
	split_line = ft_split(line, ' ');
	if (ft_split_line_len(split_line) != 4)
	{
		ft_free_split_line(split_line);
		return (0);
	}
	if (!ft_parse_vector(split_line[1], &plane->center, 0) \
			|| !ft_parse_vector(split_line[2], &plane->orientation, 1) \
			|| !ft_parse_rgb(split_line[3], &obj->rgb))
	{
		ft_free_split_line(split_line);
		return (0);
	}
	ft_free_split_line(split_line);
	return (1);
}
