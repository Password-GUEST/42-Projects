/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geometric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:13:50 by sbejaoui          #+#    #+#             */
/*   Updated: 2023/12/13 19:42:52 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"
#include <math.h>

#define NEAR 0.1f
#define FAR	1000.0f
#define FOV 90.0f

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

void	matrix_mult(t_point *res, t_point *pts, size_t count,
						t_mat4x4 mat)
{
	t_point		*end;
	t_point		pt;
	float		w;

	end = res + count;
	while (res != end)
	{
		pt = *pts++;
		res->x = pt.x * mat.m[0][0] + pt.y * mat.m[1][0]
			+ pt.z * mat.m[2][0] + mat.m[3][0];
		res->y = pt.x * mat.m[0][1] + pt.y * mat.m[1][1]
			+ pt.z * mat.m[2][1] + mat.m[3][1];
		res->z = pt.x * mat.m[0][2] + pt.y * mat.m[1][2]
			+ pt.z * mat.m[2][2] + mat.m[3][2];
		w = pt.x * mat.m[0][3] + pt.y * mat.m[1][3]
			+ pt.z * mat.m[2][3] + mat.m[3][3];
		if (w != 0.0f)
		{
			res->x /= w;
			res->y /= w;
			res->z /= w;
		}
		res++;
	}
}

void	matrix_mult3x3(t_point *res, t_point *pts, size_t count,
						t_mat3x3 mat)
{
	t_point		*end;
	t_point		pt;
	float		w;

	end = res + count;
	while (res != end)
	{
		pt = *pts++;
		res->x = pt.x * mat.m[0][0] + pt.y * mat.m[1][0]
			+ pt.z * mat.m[2][0];
		res->y = pt.x * mat.m[0][1] + pt.y * mat.m[1][1]
			+ pt.z * mat.m[2][1];
		res->z = pt.x * mat.m[0][2] + pt.y * mat.m[1][2]
			+ pt.z * mat.m[2][2];
		res++;
	}
}
#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif
t_mat4x4	llx_isometric_projection_matrix(int width, int height)
{
	t_mat4x4	mat;
	float		fov_rad;
	float		aspect_ratio;

	aspect_ratio = (float)height / ((float)width);
	fov_rad = 1.0f / tanf(FOV * 0.5f / 180.0f * (float)M_PI);
	ft_memset(mat.m, 0, sizeof(float) * 16);
	mat.m[0][0] = aspect_ratio * fov_rad;
	mat.m[1][1] = fov_rad;
	mat.m[2][2] = (FAR - NEAR) / 2;
	mat.m[3][2] = - (FAR + NEAR) / 2;
	mat.m[3][3] = 1;
	return (mat);
}
#define START_COLOR 0xff0000
#define END_COLOR 0xff00bf

int    gradiant(int start, int end, float perc)
{
    unsigned char    red;
    unsigned char    green;
    unsigned char    blue;

    red = (start >> 16) & 0xff;
    red += perc * ((end >> 16 & 0xff) - red);
    green = (start >> 8) & 0xff;
    green += perc * ((end >> 8 & 0xff) - green);
    blue = (start & 0xff);
    blue += perc * ((end & 0xff) - blue);
    red &= 0xff;
    blue &= 0xff;
    green &= 0xff;
    return (red << 16 | green << 8 | blue);
}
void ft_drawline(t_point p1, t_point p2, unsigned int color, t_general *infg) 
{
    int dx = abs(p2.x - p1.x);
    int dy = abs(p2.y - p1.y);
	int	dz = abs(p2.z - p1.z) / (dx + 1);
    int sx = p1.x < p2.x ? 1 : -1;
    int sy = p1.y < p2.y ? 1 : -1;
    int err = dx - dy;
    int x = p1.x;
    int y = p1.y;

    ft_mlx_put_pixel(&infg->img, x, y, gradiant(START_COLOR, END_COLOR, p1.z));
    while (x != p2.x || y != p2.y) {
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }
        if (e2 < dx) {
            err += dx;
            y += sy;
        }
		p1.z += dz * (p2.z > p1.z ? 1 : -1);
        ft_mlx_put_pixel(&infg->img, x, y, gradiant(START_COLOR, END_COLOR, fabs(p2.z - p1.z) / 100));
    }
}

// void ft_drawline (t_point2 p1, t_point2 p2, unsigned int color, t_general infg) 
// {
//     const int dx = p2.x - p1.x;
//     const int dy = p2.y - p1.y;
//     int Error = 2 * dy - dx;
//     int y = p1.y;
//     int x = p1.x+1;
//     mlx_pixel_put(infg.mlx, infg.win, p1.x, p1.y, color);
//     while (++x < p2.x) 
//     {
//         if (Error > 0) {
//             y++;
//             Error += 2 * dy - 2 * dx;
//         } else {
//             Error += 2 * dy;
//         }
//         mlx_pixel_put(infg.mlx, infg.win, x, y, color);
//     }
// }

// void ft_drawline(t_general *infg, t_line *linedt, int color) {
//     int deltax = abs(linedt->endx - linedt->beginx);
//     int deltay = abs(linedt->endy - linedt->beginy);
//     int x = linedt->beginx;
//     int y = linedt->beginy;
//     int x_inc = (linedt->endx - linedt->beginx) > 0 ? 1 : -1;
//     int y_inc = (linedt->endy - linedt->beginy) > 0 ? 1 : -1;

//     if (deltax >= deltay) {
//         int error = deltax / 2;
//         for (int i = 0; i < deltax; i++) {
//             mlx_pixel_put(infg->mlx, infg->win, x + ft_translate(), y + ft_translate(), color);
//             error -= deltay;
//             if (error < 0) {
//                 y += y_inc;
//                 error += deltax;
//             }
//             x += x_inc;
//         }
//     } else {
//         int error = deltay / 2;
//         for (int i = 0; i < deltay; i++) {
//             mlx_pixel_put(infg->mlx, infg->win, x + ft_translate(), y + ft_translate(), color);
//             error -= deltax;
//             if (error < 0) {
//                 x += x_inc;
//                 error += deltay;
//             }
//             y += y_inc;
//         }
//     }
// }