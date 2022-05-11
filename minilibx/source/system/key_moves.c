/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:36:59 by aalmela-          #+#    #+#             */
/*   Updated: 2022/05/11 12:22:33 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_up(t_data *data)
{
	int	i;
	int	j;

	i = data->coordx - 1;
	j = data->coordy;
	if (data->end == 0)
		move(data, i, j);
}

void	move_down(t_data *data)
{
	int	i;
	int	j;

	i = data->coordx + 1;
	j = data->coordy;
	if (data->end == 0)
		move(data, i, j);
}

void	move_left(t_data *data)
{
	int	i;
	int	j;

	i = data->coordx;
	j = data->coordy - 1;
	if (data->end == 0)
		move(data, i, j);
}

void	move_right(t_data *data)
{
	int	i;
	int	j;

	i = data->coordx;
	j = data->coordy + 1;
	if (data->end == 0)
		move(data, i, j);
}
