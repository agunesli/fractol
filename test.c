#include "fractol.h"

/*
int	get_transparency(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_red(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_green(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_blue(int trgb)
{
	return (trgb & 0xFF);
}
*/

/*
void	end_program(t_disp *d)
{
	mlx_destroy_image(d->mlx, d->pic);
	mlx_destroy_window(d->mlx, d->win);
	free(d);
	exit(0);
}
*/

int	mouse_move(int x, int y, t_vars *vars)
{
	if (vars->fractal == 2 && vars-> lock == 0)
	{
		vars->x_coor = 2 * (double)x / WIDTH - 1;
		vars->y_coor = 2 * (double)y / HEIGHT - 1;
	}
	return (0);
}

int	ft_close(int keycode, t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	// une fonction free 
	exit(0);
	return (0);
}
/*
//int funct(int button, int x, int y, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	// une fonction free 
	exit(0);
	return (0);
}*/

void	init_max_min(t_vars *vars)
{
	if (d->choice == JULIA)
	{
		d->p.xmax = 1.25;
		d->p.xmin = -1.25;
		d->p.ymax = 1.25;
		d->p.ymin = -1.25;
	}
	else if (d->choice == MANDELBROT)
	{
		d->p.xmax = 0.5;
		d->p.xmin = -2;
		d->p.ymax = 1.25;
		d->p.ymin = -1.25;
	}
	else if (d->choice == KOCH)
	{
		d->p.xmax = 0.5;
		d->p.xmin = -2;
		d->p.ymax = 1.25;
		d->p.ymin = -1.25;
	}
}

void	init_struct(t_vars *vars, char *fract)
{
	vars->mlx = NULL;
        vars->win = NULL;
	vars->fractal = found_fractal(fract);
        vars->zoom = 1;
	//pour julia
	if (vars->fractal == JULIA)
        	vars->lock = 0;
	else
        	vars->lock = 1;
       	init_max_min(vars);
        vars->iteri = 50;
	/*vars->x_coor;
        vars->y_coor;
        vars->x_img;
        vars->y_img;*/
        vars->img = NULL;
	vars->addr = NULL;
        vars->bpp = 0;
        vars->line_length = 0;
        vars->endian = 0;
}


void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bpp / 8));
	*(unsigned int*)dst = color;
}

// 1 => Mandelbrot 2 => Julia 3 => Flocon de Koch
int	main(void)
{
	t_vars	vars;

	
/*	if (argc != 2)
		merror("Un seul argument est attendu\n");*/
	
	init_struct(vars, argv[1]); // a faire
	
	vars.mlx = mlx_init();
	if (!vars.mlx)
		merror("Error with mlx_init\n");
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fractol");
	if (!vars.win)
		merror("Error with mlx_nex_window\n");
	vars.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	if (!vars.img)
		merror("Error with mlx_new_image\n");
	vars.addr = mlx_get_data_addr(vars.img, &vars.bpp, &vars.line_length, &vars.endian);
	if (!vars.addr)
		merror("Error with mlx_init\n");


	//test pour voir le fonctionnement
	my_mlx_pixel_put(&vars, 50, 50, 0x00FF0000);
	my_mlx_pixel_put(&vars, 50, 75, 0x00FF0000);
	my_mlx_pixel_put(&vars, 75, 50, 0x00FF0000);
	my_mlx_pixel_put(&vars, 75, 75, 0x00FF0000);

	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
//	mlx_hook(vars.win, 4, 1L<<5, ft_close, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, &vars); // technique pierre 
//	mlx_hook(vars.win, 4, 1L<<2, ft_close, &vars); // press_mouse
//	mlx_hook(vars.win, 6, 1L<<6, mouse_move, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
