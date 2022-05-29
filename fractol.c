#include "fractol.h"
#include <stdio.h>

int	ft_close(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	if (vars->mlx)
		free(vars->mlx);
	exit(0);
	return (0);
}

void	init_data(t_vars *vars)
{
	vars->iter = 100;
	vars->zoom = 100;
	vars->lock = 1;
	vars->color.rr = 30 % (0x4F + 0x01);
	vars->color.rg = 90 % (0x4F + 0x01);
	vars->color.rb = 60 % (0x4F + 0x01);
	vars->xmin = -2;
	vars->xmax = 2;
	vars->ymin = -2;
	vars->ymax = 2;
	vars->julia_ci.r = 0.285;
	vars->julia_ci.i = 0.01;
/*	if (vars->fractal == MANDELBROT)
	{
		vars->color.rr = 30 % (0x4F + 0x01);
		vars->color.rg = 90 % (0x4F + 0x01);
		vars->color.rb = 60 % (0x4F + 0x01);
		vars->xmin = -2.1;
		vars->xmax = 0.6;
		vars->ymin = -1.2;
		vars->ymax = 1.2;
	}
	else if (vars->fractal == JULIA) 
	{
		vars->color.rr = 70 % (0x4F + 0x01);
		vars->color.rg = 90 % (0x4F + 0x01);
		vars->color.rb = 0 % (0x4F + 0x01);
		vars->xmin = -3;
		vars->xmax = -1.2;
		vars->ymin = -2;
		vars->ymax = 0.1;
		vars->julia_ci.r = 0.285;
		vars->julia_ci.i = 0.01;
	}
	else if (vars->fractal == BUDDHABROT)
	{
		vars->color.rr = 30 % (0x4F + 0x01);
		vars->color.rg = 90 % (0x4F + 0x01);
		vars->color.rb = 60 % (0x4F + 0x01);
		vars->xmin = -2.1;
		vars->xmax = 0.6;
		vars->ymin = -1.2;
		vars->ymax = 1.2;
	}*/
}

void	init_struct(t_vars *vars, char *fract)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		merror("Error with mlx_init\n", vars);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, fract);
	if (!vars->win)
		merror("Error with mlx_nex_window\n", vars);
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars->img)
		merror("Error with mlx_new_image\n", vars);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bpp,
			&vars->line_length, &vars->endian);
	if (!vars->addr)
		merror("Error with mlx_init\n", vars);
	init_data(vars);
}

void	draw(t_vars *vars)
{
	if (vars->fractal == MANDELBROT)
		draw_mandelbrot(vars);
	else if (vars->fractal == JULIA)
		draw_julia(vars);
	else if (vars->fractal == BUDDHABROT)
//		draw_sierpinski(vars);
		draw_buddhabrot(vars);
	else
		merror("Probleme avec nom de la fractal\n", vars);
}

// 0 => Mandelbrot 1 => Julia 2 => Buddhabrot
int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		ft_putstr("usage : fractol [fractals]\n fractals : \n");
		ft_putstr(" --> Mandelbort\n --> Julia\n --> Buddhabrot\n");
		exit(EXIT_FAILURE);
		return (0);
	}
	vars.fractal = found_fractal(argv[1]);
//	printf("fract is %d\n", vars.fractal);
	init_struct(&vars, argv[1]);
//	 printf("La structure a ete init\n");
	draw(&vars);
//	printf("Le dessin est fini\n");
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	mlx_hook(vars.win, 6, 1L << 6, mouse_move, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
