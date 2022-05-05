/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:55:44 by aalmela-          #+#    #+#             */
/*   Updated: 2022/05/05 09:49:09 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_valid(t_data *data)
{
	if (data->mlx)
		return (1);
	return (0);
}

int	validate(char *path, t_data *data)
{
	if (!file_exist(path, data))
		put_error (FOPEN, data);
	else if (!validate_extension(path))
		put_error (EXTENSION, data);
	else if (!validate_map_size(data))
		put_error(MAPINVALID, data);
	else if (validate_walls(data) <= 0)
		put_error(MAPINVALIDWALL, data);
	else if (!validate_content(data))
		put_error(MAPINVALIDCONTENT, data);
	else
		return (1);
	return (0);
}
