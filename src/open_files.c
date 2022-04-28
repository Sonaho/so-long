/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:55:10 by aalmela-          #+#    #+#             */
/*   Updated: 2022/04/28 15:36:31 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*load_map(char *path)
{
	int		fd;
	t_map	*m_map;

	if (!path || validate_extension(path) < 0)
		return (NULL);
	m_map = (t_map *)malloc(sizeof(t_map));
	fd = open(path, O_RDONLY);
	if (fd > 0 && m_map)
	{
		close(fd);
		m_map->path = path;
		init_structure(m_map);
		return (validations(m_map));
	}
	else
	{
		ft_putstr_fd("Error opening map or allocate memory\n", 1);
		return (NULL);
	}
	return (NULL);
}

void	init_structure(t_map *m)
{
	m->content = 0;
	m->exit = 0;
	m->player = 0;
	m->walls = 0;
}

int	save_map(t_map *m)
{
	int	i;

	m->map = create_structure(m);
	if (!m->map)
		return (-1);
	m->fd = open(m->path, O_RDONLY);
	i = -1;
	while (++i < m->heigth)
	{
		get_map_line(m);
		if (m->fd < 0 || !m->c_line)
			break ;
		ft_putstr_fd("Save in map: ", 1);
		ft_putstr_fd(m->c_line, 1);
		ft_putchar_fd('\n', 1);
		m->map[i] = ft_strdup(m->c_line);
		free (m->c_line);
	}
	return (0);
}
