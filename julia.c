#include "fractol.h"
#include <stdio.h>

int	julia(t_vars *vars, t_complex c, double x, double y)
{
	int			i;
	double		dist;
	double		tmp;
	t_complex	z;

	z.r = x / vars->zoom + vars->xmin;
	z.i = y / vars->zoom + vars->ymin;
	dist = z.r * z.r + z.i * z.i;
	i = 0;
	tmp = 0;
	while (i < vars->iter && dist < 4)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		dist = z.r * z.r + z.i * z.i;
		i++;
	}
	return (i);
}

void	draw_julia(t_vars *vars)
{
	double		x;
	double		y;
	t_complex	c;
	int			i;

	i = 0;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c.r = vars->julia_ci.r;
			c.i = vars->julia_ci.i;
/*			c.r = 0.285;
			c.i = 0.01;*/
			i = julia(vars, c, x, y);
			color(vars, i);
			my_mlx_pixel_put(vars, x, y);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
