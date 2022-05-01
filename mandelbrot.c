#include "fractol.h"
#include <stdio.h>

void    mandelbrot(t_vars *vars,  t_complex c)
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
        while (i < vars->iteri && dist < vars->xmax)
        {
                tmp = z.r;
                z.r = z.r * z.r - z.i * z.i + c.r;
                z.i = 2 * z.i * tmp + c.i;
     	        dist = z.r * z.r + z.i * z.i;
//		printf("z.r = %f z.i = %f => dist %f \n",z.r,z.i, dist);
                i++;
        }
//	printf("dist = %f et i = %d\n", dist, i);
	if (i == vars->iteri)
                my_mlx_pixel_put(vars, c.r, c.i, 0xFF0000);
	else
                my_mlx_pixel_put(vars, c.r, c.i, 0xFFFFFF);

/*//	printf("dist = %f\n",sqrt(z.r * z.r + z.i * z.i));
        if (sqrt(z.r * z.r + z.i * z.i) < vars->xmax)
	{
//		printf("x = %f y = %f ",c.r,c.i);
//		printf("red\n");
                my_mlx_pixel_put(vars, c.r, c.i, 0xFF0000);
        }
	else
	{
	//	printf("x = %f y = %f ",c.r,c.i);
	//	printf("white\n");
                my_mlx_pixel_put(vars, c.r, c.i, 0xFFFFFF);
	}*/
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
                        c.r = x / vars->zoom + vars->x.min;
                        c.i = y / vars->zoom + vars->y.min;
                        mandelbrot(vars, c);
                        x++;
                }
                y++;
        }
	mlx_put_image_to_window(d->img.mlx, d->img.win, d->img.image, 0, 0);
}
