/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 03:33:33 by sbejaoui          #+#    #+#             */
/*   Updated: 2023/12/13 19:11:01 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stddef.h>
# include "../libmlx/mlx.h"
# include "../gnl/get_next_line.h"

# define ERR "Mauvais input, verifiez le nombre d'arguments ou le format"
# define START 1

typedef struct s_point
{
	double 	x;
	double 	y;
	double 	z;
}	t_point;

typedef struct s_point2
{
	double 	x;
	double 	y;
	size_t	col;
}	t_point2;


typedef struct s_mat4x4
{
	float	m[4][4];
}	t_mat4x4;


typedef struct s_mat3x3
{
	float	m[3][3];
}	t_mat3x3;

typedef struct s_matrot
{
	t_mat3x3 rotx;
	t_mat3x3 roty;
	t_mat3x3 rotz;
}	t_matrot;

typedef struct s_image
{
	void	*img;
	void	*addr;
	int		line_length;
	int		bit_per_pixel;
	int		endian;
	int		max_addr;
}				t_image;


typedef struct s_general
{
	int		**tab;
	t_point **tabst;
	t_point *tabstoned;
	int		**tabcolor;
	size_t	count;
	int		scrw;
	int		scrh;
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	t_image	img;
	size_t	first;
	double	transx;
	double	transy;
	double	transz;
	double	rotx;
	double	roty;
	double	rotz;
	double	tetax;
	double	tetay;
	double	tetaz;
	double	zoom;
	int		need_render;
}	t_general;

typedef struct s_line
{
	int	beginx;
	int	beginy;
	int	endx;
	int	endy;
	int	espx;
	int	espy;
	int	cfy;
	int	cfny;
	int	tmpx;
	int	tmpy;
	int	ps;
	int	tmpex;
	int tmpey;
}	t_line;

void			ft_initlinedt(t_line *linedt, t_general infg);
void			ft_drawisometricgrid(t_general	infg);
unsigned int	rgb_to_int(double r, double g, double b);
int				ft_color(int color);
void 			ft_drawline (t_point p1, t_point p2, unsigned int color, t_general *infg);
t_point			**ft_txttotab(int fd, char *alire, t_general *infg);
t_point			**sizetab(char *alire, t_general *infg);
void			ft_initbeginpstwo(t_general *infg, t_line *linedt);
void			ft_changevaluespstwo(t_general *infg, t_line *linedt);
void			ft_tracepstwo(t_general infg, t_line linedt);
void			ft_tracepstwowhi(t_general infg, t_line linedt);
void			ft_changevaluespsone(t_general *infg, t_line *linedt);
void			ft_initbeginpsone(t_general *infg, t_line *linedt);
void			ft_tracepsone(t_general *infg, t_line *linedt);
void			ft_tracepsonewhi(t_general *infg, t_line *linedt);
int				ft_atoi(char *str);
int				ft_atoi_base(char *str, char *base);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strnstr(const char *str, const char *to_find, size_t n);
void			ft_print_tab(t_point **tab, size_t sizex, size_t sizey);
void			ft_print_tabod(t_point *tab, size_t count);
void			*ft_memset(void *s, int c, size_t n);
t_mat4x4		llx_isometric_projection_matrix(int width, int height);
void			matrix_mult(t_point *res, t_point *pts, size_t count,
						t_mat4x4 mat);
void			matrix_mult3x3(t_point *res, t_point *pts, size_t count,
						t_mat3x3 mat);
						
void			ft_mlx_put_pixel(t_image *img, int x, int y, int color);

#endif