/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:18:17 by aalmela-          #+#    #+#             */
/*   Updated: 2022/05/05 11:50:40 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	create_screen(t_data *data)
{
	int	i;
	int	j;

	data->mlx = mlx_init();
	if (!data->mlx)
		put_error(LIBRARYERROR, data);
	data->win = mlx_new_window(data->mlx, data->width * 50,
			data->heigth * 50, TITLEAPP);
	print_map(data);
	i = -1;
	ft_putstr_fd("\n\n", 1);
	while (++i < data->heigth)
	{
		j = -1;
		while (data->map[i][++j] != 0)
			ft_putchar_fd(data->map[i][j], 1);
		ft_putchar_fd('\n', 1);
	}
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 17, 0, &clean_memory, data);
	mlx_loop(data->mlx);
	return (0);
}

void	print_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	get_map_line(data);
	if (!data->c_line)
		put_error(FOPEN, data);
	data->map = (char **)malloc(data->heigth * sizeof(char *));
	while (++i <= data->heigth)
	{
		j = -1;
		while (++j <= data->width)
			add_picture(data, i, j);
		data->map[i] = ft_strdup(data->c_line);
		get_map_line(data);
		if (!data->c_line)
			break ;
	}
}

int	load_images(t_data *data)
{
	int	size;

	size = 50;
	data->img.wall = mlx_xpm_file_to_image(data->mlx, WALL, &size, &size);
	if (!data->img.wall)
		put_error(IMAGEWALLNOTFOUND, data);
	data->img.player = mlx_xpm_file_to_image(data->mlx, PLAYER, &size, &size);
	if (!data->img.player)
		put_error(IMAGEPLAYERNOTFOUND, data);
	data->img.collect = mlx_xpm_file_to_image(data->mlx, CONTENT, &size, &size);
	if (!data->img.collect)
		put_error(IMAGECONTENTNOTFOUND, data);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, EXIT, &size, &size);
	if (!data->img.exit)
		put_error(IMAGEEXITNOTFOUND, data);
	data->img.space = mlx_xpm_file_to_image(data->mlx, SPACE, &size, &size);
	if (!data->img.space)
		put_error(IMAGESPACENOTFOUND, data);
	if (!data->img.wall || !data->img.player || !data->img.collect
		|| !data->img.exit || !data->img.space)
		return (0);
	else
		return (1);
}

void	add_picture(t_data *data, int i, int j)
{
	if (data->c_line[j] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.wall, j * 50, i * 50);
	else if (data->c_line[j] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player, j * 50, i * 50);
		data->coordx = i;
		data->coordy = j;
	}
	else if (data->c_line[j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.collect, j * 50, i * 50);
	else if (data->c_line[j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.exit, j * 50, i * 50);
	else if (data->c_line[j] == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.space, j * 50, i * 50);
}
