/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:16:48 by sabejaou          #+#    #+#             */
/*   Updated: 2023/12/13 19:00:25 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	ft_print_tab(t_point **tab, size_t sizex, size_t sizey)
{
	size_t	x;
	size_t	y;
	
	y = 0;
	// printf("%d\n", sizex);
	while (y < sizey - 1)
	{
		x = 0;
		while (x < sizex - 1)
		{
			// printf("x:%1.f x:%1.f z:%1.f\n", (x + y) * y, tab[x][y].y, tab[x][y].x, tab[x][y].z);
			x++;
		}
		// printf("\n");
		y++;
	}
}

void	ft_print_tabod(t_point *tab, size_t count)
{
	size_t	i;
	
	i = 0;
	while (i < count)
	{
		// printf("x:%1.f y:%1.f z:%1.f\n", tab[i].x, tab[i].y, tab[i].z);
		i++;
	}
}
