/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:26:37 by sbejaoui          #+#    #+#             */
/*   Updated: 2021/11/07 00:16:48 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*tab;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	tab = (char *)malloc(sizeof(char) * len + 1);
	if (tab == NULL)
		return (0);
	while (str[i] != '\0')
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
