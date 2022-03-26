/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:10:13 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/11 18:21:13 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_object	*ft_add_new_cy(t_scene *scene, t_cylinder *cylinder)
{
	t_object	*obj;

	if (!cylinder)
		return (NULL);
	obj = ft_add_new_object(scene);
	if (!obj)
		return (NULL);
	obj->type = CYLINDER;
	obj->obj = cylinder;
	return (obj);
}

int	ft_parse_cy(char *line, t_scene *scene)
{
	char		**split_line;
	t_object	*obj;
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	obj = ft_add_new_cy(scene, cylinder);
	if (!obj)
		return (0);
	split_line = ft_split(line, ' ');
	if (ft_split_line_len(split_line) != 6)
	{
		ft_free_split_line(split_line);
		return (0);
	}
	if (!ft_parse_vector(split_line[1], &cylinder->center, 0) \
			|| !ft_parse_vector(split_line[2], &cylinder->orientation, 1) \
			|| !ft_parse_number(split_line[3], &cylinder->diametr) \
			|| !ft_parse_number(split_line[4], &cylinder->height) \
			|| !ft_parse_rgb(split_line[5], &obj->rgb))
	{
		ft_free_split_line(split_line);
		return (0);
	}
	ft_free_split_line(split_line);
	return (1);
}
