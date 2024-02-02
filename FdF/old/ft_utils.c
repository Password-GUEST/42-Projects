/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:19:59 by sabejaou          #+#    #+#             */
/*   Updated: 2023/11/20 13:44:32 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int	ft_atoi(char *str)
{
	int	sign;
	int	cti;
	int	i;

	i = 0;
	sign = 1;
	cti = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		cti = cti * 10 + str[i] - 48;
		i++;
	}
	return (cti * sign);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s && fd)
	{
		while (s[i])
			write(fd, &s[i++], 1);
	}
}

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[0] == '\0')
	{
		return ((char *)str);
	}
	while (str[i] && i < n)
	{
		j = 0;
		while (str[i + j] == to_find[j] && i + j < n)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}