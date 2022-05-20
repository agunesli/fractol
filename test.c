#include "fractol.h"
#include <stdio.h>

int	ft_close(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	exit(0);
	return (0);
}

void	init_data(t_vars *vars)
{
	vars->x_img = 0;
	vars->y_img = 0;
	if (vars->fractal == MANDELBROT)
	{
		vars->color.rr = 30 % (0x4F + 0x01);
		vars->color.rg = 90 % (0x4F + 0x01);
		vars->color.rb = 60 % (0x4F + 0x01);
		vars->xmin = -2.1;
		vars->xmax = 0.6;
		vars->ymin = -1.2;
		vars->ymax = 1.2;
		vars->iter = 100;
		vars->zoom = 100;
	//	vars->color = 0;
		vars->lock = 1;
	}
	else if (vars->fractal == JULIA) // a faire
	{
		vars->color.rr = 70 % (0x4F + 0x01);
		vars->color.rg = 90 % (0x4F + 0x01);
		vars->color.rb = 0 % (0x4F + 0x01);
		vars->xmin = -2.0;
		vars->xmax = 2.0;
		vars->ymin = -2.0;
		vars->ymax = 2.0;
		vars->iter = 100;
		vars->zoom = 100;
	//	vars->color = 0;
		vars->lock = 0;
	//	remarkable_julias(d);
	}
	else if (vars->fractal == BUDDHABROT) // a faire
	{
		vars->color.rr = 30 % (0x4F + 0x01);
		vars->color.rg = 90 % (0x4F + 0x01);
		vars->color.rb = 60 % (0x4F + 0x01);
		vars->xmin = -2.1;
		vars->xmax = 0.6;
		vars->ymin = -1.2;
		vars->ymax = 1.2;
		vars->iter = 100;
		vars->zoom = 100;
	//	vars->color = 0;
		vars->lock = 1;
	}
/*	vars->x_coor;
        vars->y_coor;*/
}

void	init_struct(t_vars *vars, char *fract)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		merror("Error with mlx_init\n");
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, fract);
	if (!vars->win)
		merror("Error with mlx_nex_window\n");
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars->img)
		merror("Error with mlx_new_image\n");
	vars->addr = mlx_get_data_addr(vars->img, &vars->bpp, &vars->line_length, &vars->endian);
	if (!vars->addr)
		merror("Error with mlx_init\n");
	init_data(vars);
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y)
{
	int	nb;

	if (x > -1 && y > -1 && x < WIDTH && y < HEIGHT)
	{
		nb = (y * vars->line_length + x * (vars->bpp / 8));
		vars->addr[nb + 0] = vars->color.r;
		vars->addr[nb + 1] = vars->color.g;
		vars->addr[nb + 2] = vars->color.b;
	}
}

void	my_mlx_pixel_put_color(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (x > -1 && y > -1 && x < WIDTH && y < HEIGHT)
	{
		dst = vars->addr + (y * vars->line_length + x * (vars->bpp / 8));
		*(unsigned int*)dst = color;
	}
}

void	draw(t_vars *vars)
{
	if (vars->fractal == MANDELBROT)
		draw_mandelbrot(vars);
/*	else if (vars->fractal == JULIA)
		draw_julia(vars);*/
	else if (vars->fractal == BUDDHABROT)
		draw_buddhabrot(vars);
	else
		merror("Probleme avec nom de la fractal\n");
//	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

// 1 => Mandelbrot 2 => Julia 3 =>  Buddhabrot
int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		merror("Un seul argument est attendu\n");
	vars.fractal = found_fractal(argv[1]);
	// printf("fract is %d\n", vars.fractal);
	init_struct(&vars, argv[1]);
	// printf("La structure a ete init\n");
	draw(&vars);
	// printf("Le dessin est fini\n");
	mlx_hook(vars.win, 17, 0, ft_close, &vars); // technique pierre
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
