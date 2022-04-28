/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:32:15 by aalmela-          #+#    #+#             */
/*   Updated: 2022/04/28 15:15:09 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	create_images(t_map *m)
{
	if (!m)
		return ;
}

int	load_images(t_map *m)
{
	m->img.wall = mlx_xpm_file_to_image(m->mlx, WALL,
			&m->img.width, &m->img.height);
	if (!m->img.wall)
		ft_putstr_fd("Error loading WALL\n", 1);
	m->img.player = mlx_xpm_file_to_image(m->mlx, PLAYER,
			&m->img.width, &m->img.height);
	if (!m->img.player)
		ft_putstr_fd("Error loading PLAYER\n", 1);
	m->img.collect = mlx_xpm_file_to_image(m->mlx, CONTENT,
			&m->img.width, &m->img.height);
	if (!m->img.collect)
		ft_putstr_fd("Error loading CONTENT\n", 1);
	m->img.exit = mlx_xpm_file_to_image(m->mlx, EXIT,
			&m->img.width, &m->img.height);
	if (!m->img.exit)
		ft_putstr_fd("Error loading EXIT\n", 1);
	m->img.space = mlx_xpm_file_to_image(m->mlx, SPACE,
			&m->img.width, &m->img.height);
	if (!m->img.space)
		ft_putstr_fd("Error loading SPACE\n", 1);
	if (!m->img.wall || !m->img.player || !m->img.collect
		|| !m->img.exit || !m->img.space)
		return (-1);
	else
		return (1);
}

void	print_map(t_map *m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m->heigth)
	{	
		j = -1;
		while (++j < m->width)
			add_picture(m, i, j);
	}
}

void	add_picture(t_map *m, int i, int j)
{
	if (m->map[i][j] == '1')
		mlx_put_image_to_window(m->mlx, m->win,
			m->img.wall, j * 50, i * 50);
	else if (m->map[i][j] == 'P')
		mlx_put_image_to_window(m->mlx, m->win,
			m->img.player, j * 50, i * 50);
	else if (m->map[i][j] == 'C')
		mlx_put_image_to_window(m->mlx, m->win,
			m->img.collect, j * 50, i * 50);
	else if (m->map[i][j] == 'E')
		mlx_put_image_to_window(m->mlx, m->win,
			m->img.exit, j * 50, i * 50);
	else if (m->map[i][j] == '0')
		mlx_put_image_to_window(m->mlx, m->win,
			m->img.space, j * 50, i * 50);
}
