/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 07:25:39 by sbejaoui          #+#    #+#             */
/*   Updated: 2023/11/27 19:52:47 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	ft_initinfg(t_general *infg, char *argv)
{
	infg->scrw = 1000;
	infg->scrh = 1000;
	infg->mlx = mlx_init();
	infg->win = mlx_new_window(infg->mlx, infg->scrw, infg->scrh, "fdf");
}

void	ft_drawisometricgrid(t_general	infg)
{
	t_line	linedt;

	ft_bzero(&linedt, sizeof(t_line));
	ft_initlinedt(&linedt, infg);
	ft_tracepsone(&infg, &linedt);
	infg.y = linedt.tmpy;
	linedt.ps = 0;
	infg.x = 0;
	linedt.beginx = infg.scrw / 2.5;
	linedt.beginy = (infg.scrh / 4) * 3.5;
	ft_tracepstwo(infg, linedt);
}

int	ft_close(int keycode, t_general *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_general	infg;
	int			i;
	int			j ;

	i = 0;
	j = 0;
	ft_bzero(&infg, sizeof(t_general));
	if (argc != 2 || !ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
	{
		ft_putstr_fd(ERR, 2);
		return (-1);
	}
	ft_initinfg(&infg, argv[1]);
	infg.y = 0;
	infg.tab = sizetab(argv[1], &infg);
	if (!infg.tab || !infg.tabcolor)
	{
		ft_putstr_fd("Erreur liée au fichier", 2);
		return (-2);
	}
	ft_drawisometricgrid(infg);
	mlx_hook(infg.win, 2, 1L << 0, ft_close, &infg);
	mlx_loop(infg.mlx);
}
