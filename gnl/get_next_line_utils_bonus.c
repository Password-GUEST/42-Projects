/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:41:40 by sbejaoui          #+#    #+#             */
/*   Updated: 2023/11/09 15:57:05 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*z;
	size_t			i;

	z = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		z[i] = 0;
		i++;
	}
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tab;
	unsigned char	*z;
	size_t			i;

	i = 0;
	tab = (unsigned char *)malloc(nmemb * size);
	if (!tab)
		return (NULL);
	z = tab;
	while (i < nmemb * size)
	{
		z[i] = 0;
		i++;
	}
	return (tab);
}

char	*ft_strealloc(char *src, int n)
{
	size_t	i;
	size_t	j;
	char	*dst;

	i = 0;
	dst = NULL;
	j = ft_strlen(src);
	dst = ft_calloc((j + n + 2), sizeof(char));
	if (dst)
	{
		if (!src)
		{
			return (dst);
		}
		while (i < j + n && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[j + n] = '\0';
		if (src)
			free(src);
		return (dst);
	}
	return (0);
}

int	ft_strchr(char *str, char to_find)
{
	int			i;

	i = 0;
	if (!str)
	{
		return (-1);
	}
	while (str[i])
	{
		if (str[i] == to_find)
		{
			return (i);
		}
		i++;
	}
	if (str[i] == to_find)
	{
		return (i);
	}
	return (-1);
}
