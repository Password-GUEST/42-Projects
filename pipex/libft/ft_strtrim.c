/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:00:38 by sbejaoui          #+#    #+#             */
/*   Updated: 2021/11/07 00:18:08 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] && ft_strchr(set, s1[j]))
		j++;
	i = ft_strlen(s1) - 1;
	while (i > 0 && s1[i] && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, j, i - j + 1));
}
