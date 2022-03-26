/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:27:27 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/12 19:07:34 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TYPES_H
# define MINIRT_TYPES_H

typedef struct s_img			t_img;
typedef struct s_rgb			t_rgb;
typedef struct s_vector			t_vector;
typedef struct s_object			t_object;
typedef struct s_camera			t_camera;
typedef struct s_ambient_light	t_ambient_light;
typedef struct s_light			t_light;
typedef struct s_sphere			t_sphere;
typedef struct s_plane			t_plane;
typedef struct s_cylinder		t_cylinder;
typedef struct s_scene			t_scene;

typedef enum e_object_type
{
	SPHERE,
	PLANE,
	CYLINDER,
}	t_object_type;

struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_rgb
{
	double	r;
	double	g;
	double	b;
};

struct s_vector
{
	double	x;
	double	y;
	double	z;
};

struct s_camera
{
	t_vector	view_point;
	t_vector	orientation;
	double		view_field;
};

struct s_ambient_light
{
	double	brightness;
	t_rgb	rgb;
};

struct s_light
{
	double		brightness;
	t_vector	light_point;
	t_rgb		rgb;
};

struct s_sphere
{
	t_vector	center;
	double		diameter;
};

struct s_plane
{
	t_vector	center;
	t_vector	orientation;
};

struct s_cylinder
{
	t_vector	center;
	t_vector	orientation;
	double		diametr;
	double		height;
};

struct s_object
{
	int				obl_id;
	t_object_type	type;
	void			*obj;
	t_rgb			rgb;
	struct s_object	*next;
};

struct s_scene
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			mode;
	t_img			*img;
	t_ambient_light	*ambient_light;
	t_light			*light;
	t_camera		*camera;
	t_object		*obj;
};

#endif
