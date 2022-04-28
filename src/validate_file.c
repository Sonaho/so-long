/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:28:24 by aalmela-          #+#    #+#             */
/*   Updated: 2022/04/28 12:23:27 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_map(t_map *m)
{
	get_map_line(m);
	if (!m->c_line)
		return (-1);
	else if (validate_line(m->c_line, "01CEP") < 0)
	{	
		free(m->c_line);
		return (-1);
	}
	m->heigth = 1;
	m->width = ft_strlen(m->c_line);
	while (m->c_line)
	{
		free(m->c_line);
		get_map_line(m);
		if (m->c_line)
		{
			m->heigth ++;
			if (m->width != (int)ft_strlen(m->c_line)
				|| validate_line(m->c_line, "01CEP") < 0)
				return (-1);
		}
	}
	close (m->fd);
	return (0);
}

int	validate_line(char *line, char *chain)
{
	int		i;
	int		j;

	i = 0;
	while (line[i] != 0)
	{
		j = 0;
		while (j < 5)
		{
			if (line[i] == chain[j])
				break ;
			j ++;
		}
		if (j == 5 && line[i])
			return (-1);
		i ++;
	}
	return (1);
}

int	validate_walls(t_map *m)
{
	int	i;

	i = 0;
	if (!m)
		return (-1);
	m->fd = open(m->path, O_RDONLY);
	while (++i <= m->heigth && m->walls == 0)
	{	
		get_map_line(m);
		if (m->fd < 0)
			return (-1);
		if ((i == 1 || i == m->heigth) && validate_line(m->c_line, "1") < 0)
			m->walls = -2;
		else if (validate_line(m->c_line, "01CEP") < 0)
			m->walls = -3;
		else if (m->c_line[0] != '1'
			|| m->c_line[ft_strlen(m->c_line) - 1] != '1')
			m->walls = -4;
		free(m->c_line);
		if (m->walls < 0)
			break ;
	}
	close (m->fd);
	return (m->walls);
}

int	validate_extension(char *path)
{
	int	i;
	int	result;

	i = -1;
	while (path[++i] != '\0')
	{
		result = -1;
		if (path[i] == '.' && path[i + 1] == 'b'
			&& path[i + 2] == 'e' && path[i + 3] == 'r')
		{
			result = 0;
			i += 3;
		}
	}
	if (result == 0)
		printf("Valid extension\n");
	else
		printf("Invalid extension\n");
	return (result);
}

int	validate_content(t_map *m)
{
	int	i;

	if (!m)
		return (-1);
	m->fd = open(m->path, O_RDONLY);
	i = 0;
	while (++i <= m->heigth)
	{
		get_map_line(m);
		if (m->fd < 0)
			return (-1);
		if (m->c_line)
		{
			search_chars(m);
			free (m->c_line);
		}
	}
	if (m->fd >= 0)
		close (m->fd);
	if (m->content > 0 && m->exit == 1 && m->player == 1)
		return (1);
	else
		return (-1);
}
