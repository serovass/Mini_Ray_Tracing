/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:12:27 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/11 18:42:43 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_parser_error_exit(int fd, char *line, t_scene *scene)
{
	if (line)
		free(line);
	close(fd);
	ft_exit_rt("File error\n", scene);
}

int	ft_parsersing(char *line, t_scene *scene)
{
	int	pars;

	pars = 1;
	if (line[0] == '\0')
		;
	else if (ft_strncmp(line, "A ", 2) == 0)
		pars = ft_parse_ambient_light(line, scene);
	else if (ft_strncmp(line, "C ", 2) == 0)
		pars = ft_parse_camera(line, scene);
	else if (ft_strncmp(line, "L ", 2) == 0)
		pars = ft_parse_light(line, scene);
	else if (ft_strncmp(line, "sp ", 3) == 0)
		pars = ft_parse_sp(line, scene);
	else if (ft_strncmp(line, "pl ", 3) == 0)
		pars = ft_parse_pl(line, scene);
	else if (ft_strncmp(line, "cy ", 3) == 0)
		pars = ft_parse_cy(line, scene);
	else
		return (0);
	return (pars);
}

void	ft_scene_parser(char *file_name, t_scene *scene)
{
	int		fd;
	char	*line;
	int		gnl;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_exit_rt("File error\n", scene);
	gnl = get_next_line(fd, &line);
	while (gnl > 0)
	{
		if (!ft_parsersing(line, scene))
			ft_parser_error_exit(fd, line, scene);
		free(line);
		gnl = get_next_line(fd, &line);
	}
	if (gnl == -1)
		ft_parser_error_exit(fd, NULL, scene);
	else if (line[0] != '\0')
		ft_parser_error_exit(fd, line, scene);
	free(line);
	close(fd);
}
