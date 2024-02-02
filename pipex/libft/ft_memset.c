/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:40:07 by sbejaoui          #+#    #+#             */
/*   Updated: 2021/11/02 15:40:07 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*z;
	size_t			i;

	z = (unsigned char *)s;
	i = 0;
	if (!s)
		return (NULL);
	while (i < n)
	{
		z[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
