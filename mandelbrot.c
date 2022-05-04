#include "fractol.h"
#include <stdio.h>

int    mandelbrot(t_vars *vars,  t_complex c)
{
        int  i;
        double  dist;
        double  tmp;
        t_complex       z;

        z.r = 0;
        z.i = 0;
    	dist = z.r * z.r + z.i * z.i;
        i = 0;
       	tmp = 0;
//      printf("x = %f y = %f ",c.r,c.i);
        while (i < vars->iter && dist < 4) 
        {
                tmp = z.r;
                z.r = z.r * z.r - z.i * z.i + c.r;
                z.i = 2 * z.i * tmp + c.i;
     	        dist = z.r * z.r + z.i * z.i;
//		printf("z.r = %f z.i = %f => dist %f \n",z.r,z.i, dist);
                i++;
        }
	return (i);
//	printf("dist = %f et i = %d\n", dist, i);
}

void    draw_mandelbrot(t_vars *vars)
{

        double	x;
       	double	y;
        t_complex       c;
	int i;

	i = 0;
	vars->xmin = ((vars->x_img + (WIDTH >> 1)) / (vars->zoom / 2)) / -2;
	vars->ymin = ((vars->y_img + (HEIGHT >> 1)) / (vars->zoom / 2)) / -2;
	vars->xmax = -vars->xmin;
	vars->ymax = -vars->ymin;
	y = 0;
        while (y < HEIGHT)
        {
                x = 0;
                while (x < WIDTH)
                {
                        c.r = x / vars->zoom + vars->xmin;
                        c.i = y / vars->zoom + vars->ymin;
        		i =  mandelbrot(vars, c);
			if (i == vars->iter)
        	        	my_mlx_pixel_put(vars, x , y, 0xFF0000);
			else
        	       		my_mlx_pixel_put(vars, x, y, 0xFFFFFF);
                        x++;
                }
                y++;
        }
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
