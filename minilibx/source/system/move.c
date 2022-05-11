/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:36:59 by aalmela-          #+#    #+#             */
/*   Updated: 2022/05/11 14:20:50 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		ft_putendl_fd(WALLDETECTED, 1);
	else if (data->map[i][j] == 'C')
	{
		ft_putendl_fd("Move and eat, content detected", 1);
		data->content --;
		refresh_map(data, i, j);
	}
	else if (data->map[i][j] == 'E')
	{	
		if (data->content == 0)
		{
			ft_putendl_fd("Move and exit", 1);
			data->end = 1;
			refresh_map(data, i, j);
		}
		else
			ft_putendl_fd(EXITDETECTED, 1);
	}
	else if (data->map[i][j] == '0')
	{
		ft_putendl_fd("Move", 1);
		refresh_map(data, i, j);
	}
}

void	refresh_map(t_data *data, int i, int j)
{
	if (data->end == 0)
		data->map[i][j] = 'P';
	else
		data->map[i][j] = 'E';
	data->map[data->coordx][data->coordy] = '0';
	mlx_put_image_to_window(data->mlx, data->win,
		data->img.space, data->coordy * 50, data->coordx * 50);
	data->coordx = i;
	data->coordy = j;
	if (data->end == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player, data->coordy * 50, data->coordx * 50);
	else
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.exit, data->coordy * 50, data->coordx * 50);
		ft_putendl_fd("\n\nEND GAME!!!!!", 1);
	}
}
