/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_miniRT.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquirinu <tquirinu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:06:11 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/19 15:07:29 by tquirinu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_on_exit(void *data)
{
	t_scene	*scene;

	scene = (t_scene *)data;
	ft_free_scene(scene);
	exit(EXIT_SUCCESS);
}

void	ft_exit_rt(char *msg, t_scene *scene)
{
	ft_putstr_fd(msg, 1);
	ft_on_exit(scene);
}

static void	ft_check_file_format(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i] != '\0')
		i++;
	if (ft_strncmp(file_name + (i - 3), ".rt", 4) != 0)
	{
		ft_putstr_fd("Wrong file format\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_img	img;
	t_scene	scene;

	if (argc != 2)
	{
		ft_putstr_fd("Wrong number of arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_check_file_format(argv[1]);
	scene.img = &img;
	ft_init_new_scene(&scene);
	ft_scene_parser(argv[1], &scene);
	ft_check_scene(&scene);
	scene.mlx_ptr = mlx_init();
	scene.win_ptr = mlx_new_window(scene.mlx_ptr, WIDTH, HIGHT, "miniRT");
	img.img = mlx_new_image(scene.mlx_ptr, WIDTH, HIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	ft_ray_traysing_start(&scene, scene.mlx_ptr, scene.win_ptr);
	mlx_hook(scene.win_ptr, 2, 1L << 0, ft_deal_key, &scene);
	mlx_hook(scene.win_ptr, 17, 1L << 17, ft_on_exit, &scene);
	mlx_loop(scene.mlx_ptr);
	ft_free_scene(&scene);
	return (0);
}
