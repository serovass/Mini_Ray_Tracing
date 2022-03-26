/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:12:46 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/11 18:46:26 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int		ft_parse_number(char *str, double *num);
char	**ft_split(char const *s, char c);
int		ft_strlen(char *str);
int		ft_split_line_len(char **split_line);
void	ft_free_split_line(char **split_line);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_scene_parser(char *file_name, t_scene *scene);
int		ft_parse_ambient_light(char *line, t_scene *scene);
int		ft_parse_light(char *line, t_scene *scene);
int		ft_parse_camera(char *line, t_scene *scene);
int		ft_parse_sp(char *line, t_scene *scene);
int		ft_parse_pl(char *line, t_scene *scene);
int		ft_parse_cy(char *line, t_scene *scene);
int		ft_parse_rgb(char *line, t_rgb *rgb);
int		ft_parse_vector(char *line, t_vector *vector, int o);
int		ft_check_brightness(double *brightness);
int		ft_check_view_field(double *view_field);
void	ft_parser_error_exit(int fd, char *line, t_scene *scene);

#endif
