/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ul_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:53:51 by sabejaou          #+#    #+#             */
/*   Updated: 2023/11/08 11:51:22 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

void	ft_putnbr_ul_fd(unsigned int nb, int fd, unsigned int *ct)
{
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd, ct);
		ft_putchar((nb % 10) + '0', fd, ct);
	}
	else if (nb < 10 && nb >= 0)
		ft_putchar(nb + '0', fd, ct);
}
