/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geometric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:13:50 by sbejaoui          #+#    #+#             */
/*   Updated: 2023/11/25 05:12:34 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

unsigned int	rgb_to_int(double r, double g, double b)
{
	unsigned int	color;

	color = 0;
	color += b;
	color += g * 256;
	color += r * 65536;
	return (color);
}

int	ft_color(int color)
{
	if (color)
		return (color);
	return (0xFFFFFF);
}

int	ft_translate()
{
	return (-100);
}
void	ft_rotate_x(double *y, double *z)
{
	double teta = 3.14/4;
	double y_temp = *y;
	*y = (cos(teta) * (*y)) + (sin (teta) * (*z));
	*z = (sin(teta) * y_temp) -  (cos(teta) * (*z));
}

void	ft_rotate_y(double *x, double *z)
{
	double teta = 3.14/4;
	double temp_x = *x;
	*x = (cos(teta) * (*x))  * (sin (teta) * (*z));
	*z = (-sin(teta) * (temp_x)) * (cos(teta) * (*z));
}

void ft_rotate_z(double *x, double *y)
{
	double teta = 3.14/4;
	double temp_x = *x;
	*x = (cos(teta) * (*x)) * (-sin (teta) * (*y));
	*y = (sin(teta) * (temp_x)) * (cos(teta) * (*y));
}
// void	ft_drawline(t_general *infg, t_line *linedt, int color)
// {
// 	double	deltax;
// 	double	deltay;
// 	double	pixelx;
// 	double	pixely;
// 	int		pixels;

// 	deltax = linedt->endx - linedt->beginx;
// 	deltay = linedt->endy - linedt->beginy;
// 	pixels = sqrt((deltax * deltax) + (deltay * deltay));
// 	pixely = linedt->beginy;
// 	pixelx = linedt->beginx;
// 	deltax /= pixels;
// 	deltay /= pixels;
// 	while (pixels)
// 	{
// 		ft_rotate_x(&pixely, infg());
// 		ft_rotate_y();
// 		ft_rotate_z(&pixelx, &pixely);
// 		mlx_pixel_put(infg->mlx, infg->win,  pixelx + ft_translate(),pixely + ft_translate(), color);
// 		pixelx += deltax;
// 		pixely += deltay;
// 		--pixels;
// 	}
// }

// void	ft_drawline(t_general *infg, t_line *linedt, int color)
// {
// 	int		deltax;
// 	int		deltay;
// 	int		pixelx;
// 	int		pixely;
// 	int		pixels;

// 	deltax = linedt->endx - linedt->beginx;
// 	deltay = linedt->endy - linedt->beginy;
// 	pixels = 2 * deltax - deltax;
// 	pixely = linedt->beginy;
// 	pixelx = linedt->beginx;

// 	while (pixelx < linedt->endx)
// 	{
// 		if (pixels >= 0)
// 		{
// 			mlx_pixel_put(infg->mlx, infg->win,  pixelx + ft_translate(),pixely + ft_translate(), color);
// 			pixely++;
// 			pixels = pixels + 22 * deltay - 2 * deltax;
// 		}
// 		else
// 		{
// 			mlx_pixel_put(infg->mlx, infg->win,  pixelx + ft_translate(),pixely + ft_translate(), color);
// 			pixels = pixels + 2 * deltay;
// 		}
// 		pixelx++;
// 	}
// }

void ft_drawline(t_general *infg, t_line *linedt, int color) {
    int deltax = abs(linedt->endx - linedt->beginx);
    int deltay = abs(linedt->endy - linedt->beginy);
    int x = linedt->beginx;
    int y = linedt->beginy;
    int x_inc = (linedt->endx - linedt->beginx) > 0 ? 1 : -1;
    int y_inc = (linedt->endy - linedt->beginy) > 0 ? 1 : -1;

    if (deltax >= deltay) {
        int error = deltax / 2;
        for (int i = 0; i < deltax; i++) {
            mlx_pixel_put(infg->mlx, infg->win, x + ft_translate(), y + ft_translate(), color);
            error -= deltay;
            if (error < 0) {
                y += y_inc;
                error += deltax;
            }
            x += x_inc;
        }
    } else {
        int error = deltay / 2;
        for (int i = 0; i < deltay; i++) {
            mlx_pixel_put(infg->mlx, infg->win, x + ft_translate(), y + ft_translate(), color);
            error -= deltax;
            if (error < 0) {
                x += x_inc;
                error += deltay;
            }
            y += y_inc;
        }
    }
}