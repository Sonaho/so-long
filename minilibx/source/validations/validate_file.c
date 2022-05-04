/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:55:36 by aalmela-          #+#    #+#             */
/*   Updated: 2022/05/04 13:10:35 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	file_exist(char *path, t_data *data)
{
	int	result;

	result = 0;
	data->fd = open(path, O_RDONLY);
	if (data->fd > 0)
	{
		data->path = path;
		data->fd = close(data->fd);
		result = 1;
	}
	if (result == 1)
		ft_putstr_fd("\nFile exist", 1);
	return (result);
}

int	validate_extension(char *path)
{
	int	i;
	int	result;

	i = -1;
	while (path[++i] != '\0')
	{
		result = 0;
		if (path[i] == '.' && path[i + 1] == 'b'
			&& path[i + 2] == 'e' && path[i + 3] == 'r' && path[i + 4] == '\0')
		{
			result = 1;
			break ;
		}
	}
	if (result == 1)
		ft_putstr_fd("\nCorrect extension file", 1);
	return (result);
}
