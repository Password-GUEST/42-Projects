/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitcmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:20:19 by sbejaoui          #+#    #+#             */
/*   Updated: 2022/01/14 02:13:43 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strduppd(char const *s, char c, int *i, char *cmd)
{
	char	*str;
	int		size;
	int		j;

	str = 0;
	size = 0;
	j = 0;
	while (ft_check_c(s[*i], c) == 0 && s[*i])
	{
		size++;
		*i += 1;
	}
	str = (char *)malloc(sizeof(char) * (size + 2 + ft_strlen(cmd)));
	if (!str)
		return (ft_calloc(1, 0));
	*i = *i - size;
	while (ft_check_c(s[*i], c) == 0 && s[*i])
	{
		str[j] = s[*i];
		*i += 1;
		j++;
	}
	str[j] = '/';
	str[size + ft_strlen(cmd) - 1] = '\0';
	return (str);
}

char	**ft_splitcmd(char const *s, char c, char *cmd, int i)
{
	char	**str;
	int		j;

	j = 0;
	str = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_count_c(c, s)));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (ft_check_c(c, s[i]) == 0)
		{
			str[j] = ft_strduppd(s, c, &i, cmd);
			str[j] = ft_strjoin(str[j], cmd);
			ft_strlcat(str[j], cmd, ft_strlen(str[j]));
			j++;
		}
		else
			i++;
	}
	str[j] = 0;
	return (str);
}
