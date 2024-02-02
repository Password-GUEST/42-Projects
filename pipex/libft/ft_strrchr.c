/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:39:50 by sbejaoui          #+#    #+#             */
/*   Updated: 2021/11/02 15:39:50 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft.h"
#include "libft.h"

char	*ft_strrchr(const char *str, int to_find)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == to_find)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}
