/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:32:32 by aalmela-          #+#    #+#             */
/*   Updated: 2022/05/04 14:50:50 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	validate_map_size(t_data *data)
{
	get_map_line(data);
	if (!data->c_line)
		return (0);
	else if (!validate_line(data->c_line, "01CEP"))
		return (0);
	data->heigth = 1;
	data->width = ft_strlen(data->c_line);
	while (data->c_line)
	{
		get_map_line(data);
		if (data->c_line)
		{
			data->heigth ++;
			if (data->width != (int)ft_strlen(data->c_line)
				|| !validate_line(data->c_line, "01CEP"))
				return (0);
		}
	}
	data->fd = close (data->fd);
	ft_putstr_fd("\nSize map correct", 1);
	return (1);
}

int	validate_line(char *line, char *chain)
{
	int		i;
	int		j;

	i = 0;
	while (line[i] != 0)
	{
		j = 0;
		while (j < (int)ft_strlen(chain))
		{
			if (line[i] == chain[j])
				break ;
			j ++;
		}
		if (j == (int)ft_strlen(chain) && line[i])
			return (0);
		i ++;
	}
	return (1);
}

int	validate_walls(t_data *data)
{
	int	i;

	i = -1;
	while (++i <= data->heigth && data->walls == 0)
	{	
		get_map_line(data);
		if (data->c_line)
		{
			if ((i == 0 || i == data->heigth)
				&& !validate_line(data->c_line, "1"))
				data->walls = -1;
			else if (data->c_line[0] != '1'
				|| data->c_line[ft_strlen(data->c_line) - 1] != '1')
				data->walls = -1;
			if (data->walls != 0)
				break ;
		}
		else if (i < data->heigth)
			return (0);
	}
	data->fd = close (data->fd);
	if (data->walls == 0)
		return (1);
	return (data->walls);
}

int	validate_content(t_data *data)
{
	int	i;

	i = -1;
	while (++i <= data->heigth)
	{
		get_map_line(data);
		if (data->fd < 0)
			return (0);
		if (data->c_line)
			search_chars(data);
	}
	if (data->fd >= 0)
		data->fd = close (data->fd);
	if (data->content > 0 && data->exit == 1 && data->player == 1)
		return (1);
	else
		return (0);
}
