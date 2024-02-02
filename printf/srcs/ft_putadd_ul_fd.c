/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd_ul_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:01:57 by sabejaou          #+#    #+#             */
/*   Updated: 2023/11/10 23:24:47 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

void	ft_putadd_ul_fd(unsigned long nb, unsigned long fd, const char *hex,
		unsigned int *ct)
{
	if (nb >= 16)
	{
		ft_putadd_ul_fd(nb / 16, fd, hex, ct);
		ft_putchar(hex[nb % 16], fd, ct);
	}
	else if (nb < 16 && nb >= 0)
		ft_putchar(hex[nb], fd, ct);
}
