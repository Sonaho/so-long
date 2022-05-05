/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:53:19 by aalmela-          #+#    #+#             */
/*   Updated: 2022/05/05 09:48:53 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	clean_memory(t_data *data)
{
	if (data->c_line)
		free(data->c_line);
	if (!data->error)
		destroy_window(data);
	data->c_line = NULL;
	data->error = NULL;
	return (0);
}
