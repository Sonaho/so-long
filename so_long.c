/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:15:36 by aalmela-          #+#    #+#             */
/*   Updated: 2022/04/28 15:35:18 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int arg, char **args)
{
	t_map	*m;

	if (arg < 2)
	{
		perror("[-]");
		return (0);
	}
	m = load_map(args[1]);
	if (!m)
		return (0);
	m->mlx = mlx_init();
	if (!m->mlx)
		return (0);
	m->win = mlx_new_window(m->mlx, m->width * 50,
			m->heigth * 50, "So Long");
	if (load_images(m) == -1)
		ft_putstr_fd("Error loading images\n", 1);
	print_map(m);
	mlx_key_hook(m->win, key_hook, &m);
	mlx_hook(m->win, 17, 0, clean_memory, &m);
	mlx_loop(m->mlx);
	return (1);
}
