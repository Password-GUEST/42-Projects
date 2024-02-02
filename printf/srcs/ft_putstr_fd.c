/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:54:06 by sabejaou          #+#    #+#             */
/*   Updated: 2023/11/08 11:51:14 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

void	ft_putstr_fd(char *s, int fd, unsigned int *ct)
{
	int	i;

	i = 0;
	if (!s)
		ft_putstr_fd("(null)", fd, ct);
	if (s && fd)
	{
		while (s[i])
			ft_putchar(s[i++], fd, ct);
	}
}
