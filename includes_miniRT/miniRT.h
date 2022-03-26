/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquirinu <tquirinu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:08:27 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/19 16:13:16 by tquirinu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h> 
//# include <mlx.h>
# include "mlx.h"
# include "get_next_line.h"
# include "miniRT_types.h"
# include "parser.h"
# include "ray_traysing.h"
# include "intersect_all.h"

# define WIDTH 800
# define HIGHT 600

t_vector	ft_new_vector(double x, double y, double z);
t_vector	ft_vectors_subtraction(t_vector vector_1, t_vector vector_2);
double		ft_get_vector_leangth(t_vector vector);
void		ft_vector_normalization(t_vector *vector);
double		ft_vectors_dot_product(t_vector vector_1, t_vector vector_2);
t_vector	ft_vectors_cross_product(t_vector vector_1, t_vector vector_2);
t_vector	ft_vector_multiplication(t_vector vector, double d);
t_vector	ft_vector_add(t_vector vector_1, t_vector vector_2);
void		ft_free_scene(t_scene *scene);
void		ft_check_scene(t_scene *scene);
void		ft_init_new_scene(t_scene *scene);
t_object	*ft_add_new_object(t_scene *scene);
void		ft_putstr_fd(char *s, int fd);
void		ft_exit_rt(char *msg, t_scene *scene);
int			ft_deal_key(int key, t_scene *scene);
void		my_mlx_pixel_put(t_scene *scene, int x, int y, int color);

#endif
