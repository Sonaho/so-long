/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:07:04 by aalmela-          #+#    #+#             */
/*   Updated: 2022/01/21 12:34:39 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned long	i;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		i = 0;
	else if (ft_strlen(s + start) <= len)
		i = ft_strlen(s + start);
	else
		i = len;
	ret = (char *)malloc(i + 1);
	if (ret == NULL)
		return (NULL);
	ret[i] = 0;
	if (i > 0)
		ft_memcpy(ret, &s[start], i);
	return (ret);
}
