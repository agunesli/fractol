#include "fractol.h"
#include <stdio.h>

void	init_pixel(int pixel[WIDTH][HEIGHT])
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			pixel[i][j] = 0;
			j++;
		}
		i++;
	}
}

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
	printf("Le dessin des pixels est fini\n");
}

void	buddhabrot(t_vars *vars, t_complex c)
{
	int			i;
	int			x,y;
	double		dist;
	double		tmp;
	t_complex	z;
	int			pixel[WIDTH][HEIGHT];

	z.r = 0;
	z.i = 0;
	init_pixel(pixel);
	dist = z.r * z.r + z.i * z.i;
	i = 0;
	tmp = 0;
	while (i < vars->iter && dist < 4)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		x = (z.r - vars->xmin) * vars->zoom;
		y = (z.i - vars->ymin) * vars->zoom;
		pixel[x][y] = 1;
		// printf("on remplie le tablean pixel\n");
		dist = z.r * z.r + z.i * z.i;
		i++;
	}
	// printf("Le tableau pixel est rempli\n");
	if (i != vars->iter)
		draw_pixel(pixel, vars);
}

void	draw_buddhabrot(t_vars *vars)
{
	double		x;
	double		y;
	t_complex	c;
	int			i;

	i = 0;
	y = 0;
	printf("Le dessin va etre commence\n");
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.r = x / vars->zoom + vars->xmin;
			c.i = y / vars->zoom + vars->ymin;
			printf("Les donnees de c sont envoyees\n");
			buddhabrot(vars, c);
			x++;
//			printf(" i = %d \n", i);
			// color(vars, i);
			// my_mlx_pixel_put(vars, x, y);
		//	my_mlx_pixel_put(vars, x, y, 0x00000);
			// if (i == vars->iter)
			// 	my_mlx_pixel_put(vars, x, y, 0x00000);
			// else
			// 	my_mlx_pixel_put(vars, x, y, 0xFFFFFF);
		}
		y++;
	}
	printf("FINI !\n");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
