/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:24:04 by sabejaou          #+#    #+#             */
/*   Updated: 2023/11/08 11:52:51 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(const char *fmt, ...);
void	ft_putnbr_ul_fd(unsigned int nb, int fd, unsigned int *ct);
void	ft_putchar(char c, int fd, unsigned int *ct);
void	ft_putnbr_fd(int nb, int fd, unsigned int *ct);
void	ft_putadd_fd(unsigned int nb, unsigned long fd, const char *hex,
			unsigned int *ct);
void	ft_putstr_fd(char *s, int fd, unsigned int *ct);
void	ft_putadd_ul_fd(unsigned long nb, unsigned long fd, const char *hex,
			unsigned int *ct);

#endif