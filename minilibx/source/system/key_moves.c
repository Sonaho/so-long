/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:36:59 by aalmela-          #+#    #+#             */
/*   Updated: 2022/05/05 12:43:16 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_up(t_data *data)
{
	int	i;
	int	j;

	i = data->coordx - 1;
	j = data->coordy;
	move(data, i, j);
}

void	move_down(t_data *data)
{
	int	i;
	int	j;

	i = data->coordx + 1;
	j = data->coordy;
	move(data, i, j);
}

void	move_left(t_data *data)
{
	int	i;
	int	j;

	i = data->coordx;
	j = data->coordy - 1;
	move(data, i, j);
}

void	move_right(t_data *data)
{
	int	i;
	int	j;

	i = data->coordx;
	j = data->coordy + 1;
	move(data, i, j);
}

void	move(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		ft_putendl_fd(WALLDETECTED, 1);
	else if (data->map[i][j] == 'C')
		ft_putendl_fd("Move and eat, content detected", 1);
	else if (data->map[i][j] == 'E')
	{	
		if (data->content == 0)
			ft_putendl_fd("Move and exit", 1);
		else
			ft_putendl_fd(EXITDETECTED, 1);
	}
	else if (data->map[i][j] == '0')
		ft_putendl_fd("Move", 1);
}
