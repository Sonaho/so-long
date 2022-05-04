/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:18:17 by aalmela-          #+#    #+#             */
/*   Updated: 2022/05/04 15:05:35 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/so_long.h"

int	create_screen(t_data *data)
{
	ft_putstr_fd("\nStarting library mlx", 1);
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_putstr_fd("\nError: fail library mlx", 1);
		return (-1);
	}
	data->win = mlx_new_window(data->mlx, 640,
			480, "Prueba de widnow");
	ft_putstr_fd("\nCreando los hooks", 1);
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 17, 0, &clean_memory, data);
	mlx_loop(data->mlx);
	return (0);
}

int	load_images(t_data *data)
{
	int	size;

	size = 50;
	data->img.wall = mlx_xpm_file_to_image(data->mlx, WALL, &size, &size);
	if (!data->img.wall)
		ft_putstr_fd("Error loading WALL\n", 1);
	data->img.player = mlx_xpm_file_to_image(data->mlx, PLAYER, &size, &size);
	if (!data->img.player)
		ft_putstr_fd("Error loading PLAYER\n", 1);
	data->img.collect = mlx_xpm_file_to_image(data->mlx, CONTENT, &size, &size);
	if (!data->img.collect)
		ft_putstr_fd("Error loading CONTENT\n", 1);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, EXIT, &size, &size);
	if (!data->img.exit)
		ft_putstr_fd("Error loading EXIT\n", 1);
	data->img.space = mlx_xpm_file_to_image(data->mlx, SPACE, &size, &size);
	if (!data->img.space)
		ft_putstr_fd("Error loading SPACE\n", 1);
	if (!data->img.wall || !data->img.player || !data->img.collect
		|| !data->img.exit || !data->img.space)
		return (0);
	else
		return (1);
}
