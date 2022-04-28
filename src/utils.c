/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:29:16 by aalmela-          #+#    #+#             */
/*   Updated: 2022/04/28 15:17:02 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_map_line(t_map *m)
{
	char	*gnl;

	if (!m->fd || m->fd <= 0)
		m->fd = open(m->path, O_RDONLY);
	if (m->fd > 0)
	{
		gnl = get_next_line(m->fd);
		m->c_line = ft_strtrim(gnl, "\n");
		free (gnl);
	}
}

void	search_chars(t_map *m)
{
	int	j;

	j = 0;
	while (m->c_line[j] != '\0')
	{
		if (m->c_line[j] == 'C')
			m->content ++;
		else if (m->c_line[j] == 'E')
			m->exit ++;
		else if (m->c_line[j] == 'P')
			m->player ++;
		j++;
	}
}

char	**create_structure(t_map *m)
{
	char	**ret;
	int		i;

	ret = (char **)malloc(m->heigth * sizeof(char *));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < m->heigth)
	{
		ret[i] = (char *)malloc(m->width * sizeof(char *));
		if (!ret[i])
		{
			while (i > -1)
				free(ret[i--]);
			free(ret);
			return (NULL);
		}
	}
	return (ret);
}

int	clean_memory(t_map *m)
{	
	int	i;

	if (m)
	{
		i = -1;
		//while (++i <= m->heigth)
		//{	
			//if (m->map[i])
				//free(m->map[i]);
		//}
	}
	return (0);
}
