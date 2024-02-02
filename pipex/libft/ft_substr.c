/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:33:14 by sbejaoui          #+#    #+#             */
/*   Updated: 2021/11/07 00:18:17 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	int		i;

	i = 0;
	if (len <= 0 || !s || start >= ft_strlen(s))
		return (ft_strdup(""));
	s = &s[start];
	sstr = (char *)malloc((len + 1) * sizeof(char));
	if (!sstr)
		return (NULL);
	while (len > 0)
	{
		sstr[i] = s[i];
		i++;
		len--;
	}
	sstr[i] = '\0';
	return (sstr);
}
