#include "fractol.h"

void    mandelbrot(t_vars *vars,  t_complex c)
{
        int     i;
        double  dist;
        double  tmp;
        t_complex       z;

        z.r = 0;
        z.i = 0;
        dist = z.r * z.r + z.i * z.i;
        tmp = 0;
        i = 0;
        while (i < vars->iteri)
        {
                tmp = z.r;
                z.r = z.r * z.r - z.i * z.i + c.r;
                z.i = 2 * z.i * tmp + c.i;
                dist = z.r * z.r + z.i * z.i;
                i++;
        }
        if (dist < vars->xmax)
                my_mlx_pixel_put(vars, c.r, c.i, 0x00FF0000);
        else
                my_mlx_pixel_put(vars, c.r, c.i, 0x000000);
}

void    draw_mandelbrot(t_vars *vars)
{

        int     x;
        int     y;
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
