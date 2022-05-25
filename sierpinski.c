#include "fractol.h"

int		sierpinski_carpet(t_vars *vars, int x, int y)
{
	int i;

	i = 0;
	x *= vars->zoom;
	y *= vars->zoom;
	while (i < vars->iter)
	{
		if ((x % 3 == 1) && (y % 3 == 1))
			return (0);
		x /= 3;
		y /= 3;
		i++;
	}
	return (20);
}

void	draw_sierpinski(t_vars *vars)
{
	double		x;
	double		y;
	int			i;

	i = 0;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			i = sierpinski_carpet(vars, x, y);
			color(vars, i);
			my_mlx_pixel_put(vars, x, y);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
