/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:41:43 by aalmela-          #+#    #+#             */
/*   Updated: 2022/05/04 14:46:18 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	get_map_line(t_data *data)
{
	char	*gnl;

	if (!data->fd || data->fd <= 0)
		data->fd = open(data->path, O_RDONLY);
	if (data->c_line)
		free (data->c_line);
	if (data->fd > 0)
	{
		gnl = get_next_line(data->fd);
		data->c_line = ft_strtrim(gnl, "\n");
		free (gnl);
	}
}

void	search_chars(t_data *data)
{
	int	j;

	j = 0;
	while (data->c_line[j] != '\0')
	{
		if (data->c_line[j] == 'C')
			data->content ++;
		else if (data->c_line[j] == 'E')
			data->exit ++;
		else if (data->c_line[j] == 'P')
			data->player ++;
		j++;
	}
}
