/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:33:52 by agunesli          #+#    #+#             */
/*   Updated: 2022/05/24 22:30:41 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx/mlx.h"

# define MANDELBROT 0
# define JULIA 1
# define BUDDHABROT 2

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
# define C		99
# define M		109

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	rr;
	int	rg;
	int	rb;

}	t_color;

// bpp => bits_per_pixel;
// lock for julia;
typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			fractal;
	int			lock;
	double		zoom;
	double		iter;
	double		xmin;
	double		ymin;
	double		xmax;
	double		ymax;
	t_complex	julia_ci;
	t_color		color;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}	t_vars;

//test.c
void	draw(t_vars *vars);
int		ft_close(t_vars *vars);
void	init_data(t_vars *vars);

//mandelbrot.c
int		mandelbrot(t_vars *vars, t_complex c);
void	draw_mandelbrot(t_vars *vars);

// utils.c
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		found_fractal(char *fract);
void	merror(char *str, t_vars *vars);

// hook
int		mouse_hook(int button, int x, int y, t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		mouse_move(int x, int y, t_vars *vars);

// draw
void	color(t_vars *vars, int i);
void	color_shift(t_vars *vars);
void	my_mlx_pixel_put(t_vars *vars, int x, int y);
void	my_mlx_pixel_put_color(t_vars *vars, int x, int y, int color);

//julia
int		julia(t_vars *vars, t_complex c, double x, double y);
void	draw_julia(t_vars *vars);

//buddhabrot
void	draw_buddhabrot(t_vars *vars);
void	draw_sierpinski(t_vars *vars);

#endif
