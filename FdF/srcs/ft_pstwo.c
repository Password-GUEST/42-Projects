/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pstwo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 03:55:02 by sbejaoui          #+#    #+#             */
/*   Updated: 2023/11/28 03:08:00 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	ft_initbeginpstwo(t_general *infg, t_line *linedt)
{
	linedt->endx = linedt->beginx - linedt->espx;
	linedt->endy = linedt->tmpey - linedt->espy;
	if (linedt->beginy == infg->scrw / 2
		|| linedt->beginy == (infg->scrh / 4)
		* 3 - (linedt->espy * linedt->ps))
		linedt->endy = linedt->beginy - linedt->espy;
	linedt->tmpey = linedt->endy;
	linedt->tmpex = linedt->endx;
}

void	ft_changevaluespstwo(t_general *infg, t_line *linedt)
{
	linedt->ps++;
	infg->x++;
	linedt->beginx = infg->scrw / 2 + (linedt->espx * linedt->ps);
	linedt->beginy = (infg->scrh / 4) * 3 - (linedt->espy * linedt->ps);
}

void	ft_lasttwo(t_general infg, t_line linedt)
{
	infg.x--;
	infg.y = linedt.tmpy - 1;
	while (infg.y >= 0)
	{
		ft_initbeginpstwo(&infg, &linedt);
		if (infg.x && infg.y && infg.tabst[infg.x][infg.y].z > 0)
			linedt.endy -= infg.tabst[infg.x][infg.y].z * linedt.cfy;
		else if (infg.x && infg.y && infg.tabst[infg.x][infg.y].z < 0)
			linedt.endy += infg.tabst[infg.x][infg.y].z * linedt.cfny;
		// printf("%d %d => %2d\n", infg.x, infg.y, infg.tabst[infg.x][infg.y].z);
		// if (linedt.beginy != (infg.scrh / 4)
		// 	* 3 - (linedt.espy * linedt.ps)
		// 	&& linedt.beginy != (infg.scrh / 4) * 3 && linedt.ps)
			// ft_drawline(&infg, &linedt,
			// 	ft_color(infg.tabcolor[infg.x][infg.y]));
		linedt.beginx = linedt.endx;
		linedt.beginy = linedt.endy;
		infg.y--;
	}
}

void	ft_tracepstwo(t_general infg, t_line linedt)
{
	printf("bx: %d by: %d\n", linedt.beginx, linedt.beginy);
	// infg.x += 5;
	linedt.beginy = linedt.beginx;
	linedt.beginx = linedt.beginy - linedt.beginy;
	while (infg.x < linedt.tmpx - 1)
	{
		infg.y = linedt.tmpy - 1;
		while (infg.y >= 0)
		{
			// printf("%d %d\n", infg.x, infg.y);
			ft_initbeginpstwo(&infg, &linedt);
			if (infg.x && infg.y && infg.tabst[infg.x - 1][infg.y].z > 0)
				linedt.endy -= infg.tabst[infg.x - 1][infg.y].z * linedt.cfy;
			else if (infg.x && infg.y && infg.tabst[infg.x - 1][infg.y].z < 0)
				linedt.endy += infg.tabst[infg.x - 1][infg.y].z * linedt.cfny;
			// if (linedt.beginy != (infg.scrh / 4)
			// 	* 3 - (linedt.espy * linedt.ps)
			// 	&& linedt.beginy != (infg.scrh / 4) * 3 && linedt.ps)
				// ft_drawline(&infg, &linedt,
				// 	ft_color(infg.tabcolor[infg.x][infg.y]));
			linedt.beginx = linedt.endx;
			linedt.beginy = linedt.endy;
			infg.y--;
		}
		ft_changevaluespstwo(&infg, &linedt);
		printf("\n");
	}
	// ft_lasttwo(infg, linedt);
	printf("\x1b[0m\n last coords x:%d y:%d\n", infg.x, infg.y);
}
