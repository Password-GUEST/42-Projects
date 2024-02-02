/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 07:25:39 by sbejaoui          #+#    #+#             */
/*   Updated: 2024/01/15 18:17:39 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	ft_mlx_put_pixel(t_image *img, int x, int y, int color)
{
	int	*dst;
	int	addr;

	dst = (int *)img->addr;
	addr = y * (img->line_length >> 2) + x;
	// if (addr >= img->max_addr >> 1)
	// 	printf("addr %d \n", addr);
	if (addr >= 0 && addr < img->max_addr)
		dst[addr] = color;
}

void	ft_draw_rect(t_image *img, int w, int h, int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < h)
	{
		x = -1;
		while (++x < w)
		{
			ft_mlx_put_pixel(img, x, y, color);	
		}
	}
}

int	ft_create_image(t_general *infg)
{
	infg->img.img = mlx_new_image(infg->mlx, infg->scrw, infg->scrh);
	if (!infg->img.img)
		return (1);
	infg->img.addr = mlx_get_data_addr(infg->img.img, &infg->img.bit_per_pixel, &infg->img.line_length, &infg->img.endian);
	if (!infg->img.addr)
		return (mlx_destroy_image(infg->mlx, infg->img.img), 1);
	infg->img.bit_per_pixel /= 8;
	infg->img.max_addr = infg->scrw * infg->scrh;
	return (0);
}

int	ft_initinfg(t_general *infg, char *argv)
{
	infg->scrw = 2000;
	infg->scrh = 2000;
	infg->mlx = mlx_init();
	infg->zoom = 0;
	infg->transx = 0;
	infg->transy = 0;
	infg->transz = 1;
	infg->rotx = 0;
	infg->roty = 0;
	infg->rotz = 0;
	infg->win = mlx_new_window(infg->mlx, infg->scrw, infg->scrh, "fdf");
	if (ft_create_image(infg))
		return (1);
	return (0);
}

void	ft_drawisometricgrid(t_general	infg)
{
	t_line	linedt;

	ft_bzero(&linedt, sizeof(t_line));
	ft_initlinedt(&linedt, infg);
	ft_tracepsone(&infg, &linedt);
	infg.y = linedt.tmpy - 1;
	linedt.ps = 0;
	infg.x = 0;
	linedt.beginx = infg.scrw / 2.5;
	linedt.beginy = (infg.scrh / 4) * 3.5;
	ft_tracepstwo(infg, linedt);
}

int	ft_close(int keycode, t_general *vars)
{

	return (0);
}


t_point *redimension_tab(t_point **twodtab, int width, int height)
{
	size_t	z;
	size_t	x;
	t_point	*onedtab;
	
	onedtab = malloc(sizeof(t_point) * width * height);
	if (!onedtab)
		return (NULL);
	z = 0;
	while (z < width)
	{
		x = 0;
		while (x < height)
		{
			onedtab[z * height + x] = twodtab[z][x];
			x++;
		}
		z++;
	}
	return (onedtab);
}

void	to_point( t_point *res, t_general *infg, t_point *tabstoned)
{
	t_point		*end_ptr;
	float		to_mul_x;
	float		to_mul_y;

	to_mul_x = (float)infg->scrw / 2  * infg->transz;
	to_mul_y = (float)infg->scrh / 2  * infg->transz;
	end_ptr = res + infg->count;
	while (res != end_ptr)
	{
		res->x = (int)((tabstoned->x + 1.0f) * to_mul_x);
		res->y = (int)((tabstoned->y + 1.0f) * to_mul_y);
		res->z = (int)((tabstoned->z + 1.0f));
		// res->col = infg->tabcolor[(int)tabstoned->x][(int)tabstoned->y];
		tabstoned++;
		res++;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	draw_fdf_lines(t_point *pts, size_t count, t_general *infg)
{
	t_point	*end;
	size_t		idx;

	idx = 0;
	end = pts-- + count;
	// printf("idx %d\n", end);
	while (++pts != end)
	{
		if (idx % infg->x < (size_t)infg->x - 1)
		{
			ft_drawline((*pts), (*(pts + 1)), 0xFFFFFF, infg);
			// printf("R{%1.f:%1.f}-{%1.f:%1.f}  ", pts->x, pts->y, (pts + 1)->x, (pts + 1)->y);
		}
		if (idx++ / infg->x < (size_t)infg->y - 1)
		{
			ft_drawline(*pts, *(pts + infg->x), 0xFFFFFF, infg);
			// printf("D{%1.f:%1.f}-{%1.f:%1.f}  ", pts->x, pts->y, (pts + 1)->x, (pts + 1)->y);
		}
		// printf("idx %d\n", idx);
	}
	// printf("\n");
}
void	ft_rotate_x(double *y, double *z, double teta)
{
	double y_temp = *y;
	*y = (cos(teta) * (*y)) - (sin (teta) * (*z));
	*z = (sin(teta) * y_temp) +  (cos(teta) * (*z));
}

void	ft_rotate_y(double *x, double *z, double teta)
{
    double temp_x = *x;
    *x = cos(teta) * (*x) + sin(teta) * (*z);
    *z = -sin(teta) * (temp_x) + cos(teta) * (*z);
}

void ft_rotate_z(double *x, double *y, double teta)
{
	double temp_x = *x;
	*x = (cos(teta) * (*x)) - (sin (teta) * (*y));
	*y = (sin(teta) * (temp_x)) + (cos(teta) * (*y));
}

t_mat3x3	ft_initrotx(t_mat3x3 rotx, double teta)
{
	rotx.m[0][0] = 1;
	rotx.m[0][1] = 0;
	rotx.m[0][2] = 0;
	rotx.m[1][0] = 0;
	rotx.m[1][1] = cos(teta);
	rotx.m[1][2] = -sin(teta);
	rotx.m[2][0] = 0;
	rotx.m[2][1] = sin(teta);
	rotx.m[2][2] = cos(teta);
}

t_mat3x3	ft_initroty(t_mat3x3 roty, double teta)
{
	roty.m[0][0] = cos(teta);
	roty.m[0][1] = 0;
	roty.m[0][2] = sin(teta);
	roty.m[1][0] = 0;
	roty.m[1][1] = 1;
	roty.m[1][2] = 0;
	roty.m[2][0] = -sin(teta);
	roty.m[2][1] = 0;
	roty.m[2][2] = cos(teta);
}

t_mat3x3	ft_initrotz(t_mat3x3 rotz, double teta)
{
	rotz.m[0][0] = cos(teta);
	rotz.m[0][1] = -sin(teta);
	rotz.m[0][2] = 0;
	rotz.m[1][0] = sin(teta);
	rotz.m[1][1] = cos(teta);
	rotz.m[1][2] = 0;
	rotz.m[2][0] = 0;
	rotz.m[2][1] = 0;
	rotz.m[2][2] = 1;
}

t_matrot ft_matinit(t_matrot rot)
{
	rot.rotx = ft_initrotx(rot.rotx, 0);
	rot.roty = ft_initroty(rot.roty, 3.14/4);
	rot.rotz = ft_initrotz(rot.rotz, 0);
	return(rot);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!src && !dest)
		return (dest);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return ((void *)dest);
}

void	ft_draw_projection(t_general *infg)
{
	t_mat4x4	projmatrix;
	t_point		*tabonedcpy;
	t_matrot	rot;
	t_point		*tab2d;
	size_t		i;

	i = 0;
	rot = ft_matinit(rot);
	tabonedcpy = malloc(sizeof(t_point) * infg->count);
	ft_memcpy(tabonedcpy, infg->tabstoned, sizeof(t_point) * infg->count);
	tab2d = malloc(sizeof(t_point) * infg->count);
	if(!tab2d)
		return ;
	// matrix_mult3x3(tabonedcpy, tabonedcpy, infg->count, rot.rotz);
	// matrix_mult3x3(tabonedcpy, tabonedcpy, infg->count, rot.rotx);
	// matrix_mult3x3(tabonedcpy, tabonedcpy, infg->count, rot.roty);
	for (int i = 0; i < infg->count; i++)
	{
		// tabonedcpy[i].y = fabs(tabonedcpy[i].y - infg. / 2);
		tabonedcpy[i].x = fabs(tabonedcpy[i].x - infg->x / 3.14);
	}
	for (int i = 0; i < infg->count; i++)
	{
		ft_rotate_x(&tabonedcpy[i].y, &tabonedcpy[i].z, infg->rotx);
		ft_rotate_y(&tabonedcpy[i].x, &tabonedcpy[i].z, infg->roty);
		ft_rotate_z(&tabonedcpy[i].x, &tabonedcpy[i].y, infg->rotz);
	}
	for(int lo = 0; lo < infg->count; lo++)
	{
		tabonedcpy[lo].x += infg->transx;
		tabonedcpy[lo].y += infg->transy;
		// printf("zav:%1.f  ", tabonedcpy[i].z);
		tabonedcpy[lo].z += infg->transz;
		// printf("zap:%1.f  \n", tabonedcpy[i].z);
	}
	projmatrix = llx_isometric_projection_matrix(infg->scrw + infg->zoom, infg->scrh + infg->zoom);
	// printf("\n");

	matrix_mult(tabonedcpy, tabonedcpy, infg->count, projmatrix);
	// for (int i = 0; i < infg->count; i++)
	// {
	// 	infg->tabstoned[i].x += 1;
		// printf("z:%1.f  ", infg->tabstoned[i].z);
	// }
	// printf("\n");
	to_point(tab2d, infg, tabonedcpy);
	for (int i = 0; i < infg->count; i++)
	{
		// infg->tabstoned[i].x -= 1;
		// printf("z:%1.f  ", tabonedcpy[i].z);
	}
	free(tabonedcpy);
	draw_fdf_lines(tab2d, infg->count, infg);
}

int	ft_translate(int keycode, t_general *vars)
{
	// printf("KEYNUM: %d\n", keycode);
	if (keycode == 65361)
	{
		// mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
		vars->transx -= 0.05;
		// ft_draw_projection(vars);
		vars->need_render = 1;
	}
	else if (keycode == 65363)
	{
		// mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
		vars->transx += 0.05;
		// ft_draw_projection(vars);
		vars->need_render = 1;
	}
	if (keycode == 65362)
	{
		// mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
		vars->transy -= 0.05;
		// ft_draw_projection(vars);
		vars->need_render = 1;
	}
	else if (keycode == 65364)
	{
		// mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
		vars->transy += 0.05;
		// ft_draw_projection(vars);
		vars->need_render = 1;
	}
	else if (keycode == 65436) //1
	{
		// mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
		vars->rotx += 3.14/1000;
		// ft_draw_projection(vars);
		vars->need_render = 1;
	}
	else if (keycode == 65433) // 2
	{
		// mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
		vars->roty += 3.14/1000;
		// ft_draw_projection(vars);
		vars->need_render = 1;
	}
	else if (keycode == 65435) // 3
	{
		// mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
		vars->rotz += 3.14/1000;
		// ft_draw_projection(vars);
		vars->need_render = 1;
	}
	else if (keycode == 65430) // 4
	{
		// mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
		vars->rotx -= 3.14/1000;
		// ft_draw_projection(vars);
		vars->need_render = 1;
	}
	else if (keycode == 65437) //5
	{
		// mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
		vars->roty -= 3.14/1000;
		// ft_draw_projection(vars);
		vars->need_render = 1;
	}
	else if (keycode == 65432) //6
	{
		// mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
		vars->rotz += 3.14/1000;
		// ft_draw_projection(vars);
		vars->need_render = 1;
	}
	else if (keycode == 65451) //+
	{
		// mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
		vars->transz *= 1.1;
		// ft_draw_projection(vars);
		vars->need_render = 1;
	}
	else if (keycode == 65453) //-
	{
		// mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
		vars->transz /= 1.1;
		// ft_draw_projection(vars);
		vars->need_render = 1;
	}
	if (keycode == 65307) // exit
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		exit(0);
	}
	return (0);
}

int	main_loop(void *param)
{
	t_general	*infg;

	infg = (t_general *)param;
	if (infg->need_render)
	{
		// printf("render image\n");
		ft_draw_rect(&infg->img, infg->scrw, infg->scrh, 0x0);
		ft_draw_projection(infg);
		mlx_put_image_to_window(infg->mlx, infg->win, infg->img.img, 0, 0);
		infg->need_render = 0;
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
	// infg.y = 0;
	infg.tabst = sizetab(argv[1], &infg);
	ft_print_tab(infg.tabst, infg.x, infg.y);
	infg.tabstoned = redimension_tab(infg.tabst, infg.x, infg.y);
	ft_print_tabod(infg.tabstoned, infg.count);
	if (!infg.tabst || !infg.tabstoned|| !infg.tabcolor)
	{
		ft_putstr_fd("Erreur liée au fichier", 2);
		return (-2);
	}
	// ft_drawisometricgrid(infg);
	
	for (int i = 0; i < infg.count; i++)
	{
		infg.tabstoned[i].x /= (float)infg.x;
		infg.tabstoned[i].y /= (float)infg.y;
		infg.tabstoned[i].z /= (float)3;
	}
	// ft_drawline((t_point2){0, 1000}, (t_point2){500, 500}, 0xFFFFFF, infg);
	// mlx_update_image(&infg.mlx);
	infg.need_render = 1;

	mlx_hook(infg.win, 17, 1L << 0, ft_close, &infg);
	mlx_hook(infg.win, 2, 1L << 0, ft_close, &infg);
	mlx_hook(infg.win, 2, 1L << 0, ft_translate, &infg);
	mlx_loop_hook(infg.mlx, &main_loop, &infg);
	mlx_loop(infg.mlx);
}
