/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:40:10 by sbejaoui          #+#    #+#             */
/*   Updated: 2021/11/02 15:40:10 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest || !src || !n)
		return (dest);
	else if (dest > src)
	{
		i = n - 1;
		while (i > 0)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			if (i)
				i--;
		}
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	}
	else
	{
		return (ft_memcpy(dest, src, n));
	}
	return ((void *)dest);
}
