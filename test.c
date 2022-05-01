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
/*
void	image_set_pixel(t_vars *vars, int x, int y)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	*(int *)(vars->addr + ((x + y * WIDTH) * vars->bpp)) = color;
}

void	draw(t_vars vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			image_set_pixel(vars, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}*/

/*
void	init_max_min(t_vars *vars)
{
	if (vars->fractal == JULIA)
	{
		vars->xmax = 1.25;
		vars->xmin = -1.25;
		vars->ymax = 1.25;
		vars->ymin = -1.25;
	}
	else if (vars->fractal == MANDELBROT)
	{
		vars->xmax = 0.5;
		vars->xmin = -2;
		vars->ymax = 1.25;
		vars->ymin = -1.25;
	}
	else if (vars->fractal == KOCH)
	{
		vars->xmax = 0.5;
		vars->xmin = -2;
		vars->ymax = 1.25;
		vars->ymin = -1.25;
	}
} */

void	init_struct(t_vars *vars, char *fract)
{
	vars->fractal = found_fractal(fract);
	vars->mlx = NULL;
        vars->win = NULL;
        vars->zoom = 50;
	//pour julia
	if (vars->fractal == JULIA)
        	vars->lock = 0;
	else
        	vars->lock = 1;
	vars->xmax = 5;
	vars->xmin = -5;
	vars->ymax = 5;
	vars->ymin = -5;
       //	init_max_min(vars);
        vars->iteri = 10;
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
	
	if (x > -1 && y > -1 && x < WIDTH && y < HEIGHT)
	{
		dst = vars->addr + (y * vars->line_length + x * (vars->bpp / 8));
		*(unsigned int*)dst = color;
	}
}

void	draw_fractal(t_vars *vars)
{
	if (vars->fractal == MANDELBROT)
		draw_mandelbrot(vars);
/*	else if (vars->fractal == JULIA)
		draw_julia(vars);
	else if (vars->fratal == KOCH)
		draw_koch(vars);
	else
		merror("Probleme avec nom de la fractal\n");*/
//	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}


// 1 => Mandelbrot 2 => Julia 3 => Flocon de Koch
int	main(int argc, char **argv)
{
	t_vars	vars;

	
	if (argc != 2)
		merror("Un seul argument est attendu\n");
	
	init_struct(&vars, argv[1]); // a finir
	
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


	draw_fractal(&vars);
	//test pour voir le fonctionnement
/*	my_mlx_pixel_put(&vars, 50, 50, 0x00FF0000);
	my_mlx_pixel_put(&vars, 50, 75, 0x00FF0000);
	my_mlx_pixel_put(&vars, 75, 50, 0x00FF0000);
	my_mlx_pixel_put(&vars, 75, 75, 0x00FF0000);*/

//	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
//	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
	mlx_hook(vars.win, 2, 4, ft_close, &vars);
//	mlx_hook(vars.win, 4, 1L<<5, ft_close, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, &vars); // technique pierre 
//	mlx_hook(vars.win, 4, 1L<<2, ft_close, &vars); // press_mouse
//	mlx_hook(vars.win, 6, 1L<<6, mouse_move, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
