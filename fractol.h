/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:33:52 by agunesli          #+#    #+#             */
/*   Updated: 2022/04/26 23:16:48 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx/mlx.h"

# define MANDELBROT 1
# define JULIA 2
# define KOCH 3

# define WIDTH 1200
# define HEIGHT 800

# define ESC		65307
# define W		119
# define A		97
# define S		115
# define D		100
# define UP		65362
# define DOWN		65364
# define LEFT		65361
# define RIGHT		65363
# define ESP		32
# define ENTRER		65293
# define M_UP		5
# define M_DOWN		4
# define M_CLICKL	1	
# define M_CLICKR	3
# define M_CLICKS	2

typedef struct  s_complex
{
        double  r;
        double  i;
}       t_complex;

typedef struct	s_pixel
{
	t_complex	c;
	int		i;	
}	t_pixel;

// bpp => bits_per_pixel;
typedef struct  s_vars {
        void    *mlx;
        void    *win;
        int     fractal;
	int	lock; //pour julia 
	double	zoom;
	double	xmin;
	double	ymin;
	double	xmax;
	double	ymax;
	double	iteri;
	double	x_coor;
	double	y_coor;
	double	x_img;
	double	y_img;
	int	smooth;
	t_pixel	data;
        void    *img;
        char    *addr;
        int     bpp;
        int     line_length;
        int     endian;
}	t_vars;

//mandelbrot.c
void    mandelbrot(t_vars *vars,  t_complex c);
void    draw_mandelbrot(t_vars *vars);

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);

// utils.c
int	ft_strlen(char *str);
void	ft_putstr(char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	found_fractal(char *fract);
void	merror(char *str);

#endif
