/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:24:51 by sabejaou          #+#    #+#             */
/*   Updated: 2023/11/10 23:09:33 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

void	ft_putadd_fd(unsigned int nb, unsigned long fd, const char *hex,
		unsigned int *ct)
{
	if (nb >= 16)
	{
		ft_putadd_fd(nb / 16, fd, hex, ct);
		ft_putchar(hex[nb % 16], fd, ct);
	}
	else if (nb < 16 && nb >= 0)
		ft_putchar(hex[nb], fd, ct);
}
