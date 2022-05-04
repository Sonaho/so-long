/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:18:35 by aalmela-          #+#    #+#             */
/*   Updated: 2022/05/04 15:06:41 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	init_structure(t_data *data)
{
	data->content = 0;
	data->exit = 0;
	data->player = 0;
	data->walls = 0;
}


int	main(int arg, char **args)
{
	t_data	data;

	if (arg < 2)
		put_error (PARAM, &data);
	data.fd = 0;
	init_structure(&data);
	if (validate(args[1], &data) && load_images(&data))
		create_screen(&data);
	return (0);
}
