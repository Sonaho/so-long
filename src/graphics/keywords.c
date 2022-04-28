/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keywords.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:04:16 by aalmela-          #+#    #+#             */
/*   Updated: 2022/04/28 15:13:29 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_hook(int keycode, t_map *m)
{
	ft_putstr_fd("\nKey press: ", 1);
	ft_putnbr_fd(keycode, 1);
	if (keycode == 53)
	{
		ft_putstr_fd("\nCall Window destroy\n", 1);
		ft_putnbr_fd((int)m->mlx, 1);
		ft_putstr_fd("\n", 1);
		ft_putnbr_fd((int)m->win, 1);
		//mlx_string_put(m->mlx, m->win, 0, 0, 000000, "Vamos a borrar");
		mlx_destroy_window(m->mlx, m->win);
		ft_putstr_fd("\nWindow destroyed", 1);
		//clean_memory(m);
		return (0);
	}
	return (1);
}

int	destroy_win(t_map *m)
{
	ft_putstr_fd("Call Window destroy", 1);
	mlx_clear_window(m->mlx, m->win);
	ft_putstr_fd("Window destroyed", 1);
	exit (1);
	return (0);
}
