#include "fractol.h"
#include <stdio.h>
/*
//void	init_pixel(int pixel[WIDTH][HEIGHT])
void	init_pixel(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
//			pixel[i][j] = 0;
			my_mlx_pixel_put_color(vars, i, j, 0xFFFFFF);
			j++;
		}
		i++;
	}
}i*/
/*
void	draw_pixel(int pixel[WIDTH][HEIGHT], t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	// printf("On va dessiner les pixels\n");
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			if (pixel[i][j])
				my_mlx_pixel_put_color(vars, i, j, 0x00000);
			else
				my_mlx_pixel_put_color(vars, i, j, 0xFFFFFF);
			j++;
		}
		i++;
	}
//	printf("Le dessin des pixels est fini\n");
}*/

void	plot_way(t_vars *vars, t_complex c, t_complex z)
{
	
	int			i;
	double		tmp;
	int nb;
	
	i = 1;
	tmp = 0;
	nb = write(1, "bouh\n", 5);
	(void)nb;
	while (i < vars->iter && (z.r * z.r + z.i * z.i) > 4)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
//		my_mlx_pixel_put_color(vars, z.r, z.i, 0x00000);
		i++;
	}
}

void	buddhabrot(t_vars *vars, t_complex c, int x, int y)
{
	int			i;
	double		tmp;
	t_complex	z;

	z.r = 0;
	z.i = 0;
	i = 0;
	tmp = 0;
	while (i < vars->iter && (z.r * z.r + z.i * z.i) < 4)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		i++;
	}
//	printf("i = %d\n", i);
	if (i == vars->iter)
		my_mlx_pixel_put_color(vars, x, y, 0x00000);
	else
		my_mlx_pixel_put_color(vars, x, y, 0xFFFFFF);
	//	plot_way(vars, c, z);
//	else
	//	my_mlx_pixel_put_color(vars, z.r, z.i, 0x00000);
}

void	draw_buddhabrot(t_vars *vars)
{
	int		x;
	int		y;
	t_complex	c;

	y = 0;
//	init_pixel(vars);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.r = x * (vars->xmax - vars->xmin) / WIDTH + vars->xmin;
			c.i = y * (vars->ymax - vars->ymin) / HEIGHT + vars->ymin;
			buddhabrot(vars, c, x, y);
		//	color(vars, offs);
			/*if ( i == vars->iter)
				my_mlx_pixel_put(vars, x, y);
				//my_mlx_pixel_put_color(vars, x, y, 0x00000);
				//escapes[offs] = 1;
			else
				my_mlx_pixel_put(vars, x, y);
				//my_mlx_pixel_put_color(vars, x, y, 0xFFFFFF);
				//escapes[offs] = 0;*/
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
