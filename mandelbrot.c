#include "fractol.h"
#include <stdio.h>

void    mandelbrot(t_vars *vars,  t_complex c)
{
        double   i;
        double  dist;
        double  tmp;
        t_complex       z;

        z.r = 0;
        z.i = 0;
    //    dist = sqrt(z.r * z.r + z.i * z.i);
        i = 0;
       	tmp = 0;
        while (i < vars->iteri /*&& dist < vars->xmax*/)
        {
                tmp = z.r;
                z.r = z.r * z.r - z.i * z.i + c.r;
                z.i = 2 * z.i * tmp + c.i;
      //          dist = sqrt(z.r * z.r + z.i * z.i);
                i++;
        }
	printf("dist = %f\n",sqrt(z.r * z.r + z.i * z.i));
        if (sqrt(z.r * z.r + z.i * z.i) < vars->xmax)
	{
		printf("x = %f y = %f ",c.r,c.i);
		printf("red\n");
                my_mlx_pixel_put(vars, c.r, c.i, 0xFF0000);
        }
	else
	{
	//	printf("x = %f y = %f ",c.r,c.i);
	//	printf("white\n");
                my_mlx_pixel_put(vars, c.r, c.i, 0xFFFFFF);
	}
}

void    draw_mandelbrot(t_vars *vars)
{

        double	x;
       	double	y;
        t_complex       c;

        y = 0;
        while (y < HEIGHT)
        {
                x = 0;
                while (x < WIDTH)
                {
                        c.r = x;
                        c.i = y;
                        mandelbrot(vars, c);
                        x++;
                }
                y++;
        }
}
