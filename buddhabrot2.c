#include "fractol.h"
#include <stdio.h>

void	init_pixel(int pixel[WIDTH][HEIGHT])
//void	init_pixel(t_vars *vars)
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
//			my_mlx_pixel_put_color(vars, i, j, 0xFFFFFF);
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
//	printf("Le dessin des pixels est fini\n");
}

int	*buddhabrot(t_vars *vars, t_complex c, int pixel[WIDTH][HEIGHT])
{
	int			i;
	int			x,y;
	double		dist;
	double		tmp;
	t_complex	z;

	z.r = 0;
	z.i = 0;
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
//		my_mlx_pixel_put_color(vars, y,x, 0x00000);
		// printf("on remplie le tablean pixel\n");
		dist = z.r * z.r + z.i * z.i;
		i++;
	}
//	printf("bouh\n");
	// printf("Le tableau pixel est rempli\n");
//	if (i != vars->iter)
//		draw_pixel(pixel, vars);
	return (pixel);
}

void	draw_buddhabrot(t_vars *vars)
{
	double		x;
	double		y;
	t_complex	c;
	int			pixel[WIDTH][HEIGHT];

	y = 0;
	init_pixel(pixel);
//	init_pixel(vars);
//	printf("Le dessin va etre commence\n");
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.r = x / vars->zoom + vars->xmin;
			c.i = y / vars->zoom + vars->ymin;
			pixel = buddhabrot(vars, c, pixel);
			x++;
//			printf("Les donnees de c sont envoyees\n et x = %f",x);
		}
		y++;
		printf("Une ligne est fini y = %f!!!\n", y);
	}
	draw_pixel(pixel, vars);
//	printf("FINI !\n");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
