/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:40:02 by sbejaoui          #+#    #+#             */
/*   Updated: 2021/11/02 15:40:02 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int to_find)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == to_find)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == to_find)
		return ((char *)str + i);
	return (0);
}
