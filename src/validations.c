/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:33:30 by aalmela-          #+#    #+#             */
/*   Updated: 2022/04/28 15:31:47 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*validations(t_map *m)
{
	int	error;

	error = 0;
	if (validate_map(m) < 0 || validate_walls(m) < 0)
		error = -1;
	else if (validate_content(m) > 0)
	{
		if (save_map(m) == 0)
			return (m);
		else
			return (NULL);
	}
	if (error < 0)
	{
		ft_putstr_fd("Map invalid", 1);
		ft_putnbr_fd(m->walls, 1);
		return (NULL);
	}
	return (NULL);
}
