/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:57:07 by aalmela-          #+#    #+#             */
/*   Updated: 2022/05/04 13:21:28 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/so_long.h"

void	put_error(char *str, t_data *data)
{
	ft_putstr_fd(str, 1);
	data->error = str;
	clean_memory(data);
	exit (1);
}

