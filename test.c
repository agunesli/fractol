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

// bpp => bits_per_pixel;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *(unsigned char *)s1
		&& *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	else
		return (0);
}

int	found_fractal(char *fract)
{
	if (!ft_strncmp("Mandelbrot", fract, 11))
		return (1);
	else if  (!ft_strncmp("Julia", fract, 6))
		return (2);
	else if  (!ft_strncmp("Flocon de Koch", fract, 14))
		return (3);
	else
	{
		ft_putstr("usage : fractol [fractals]\n fractals : \n");
		ft_putstr("--> Mandelbort\n --> Julia\n --> Flocon de Koch\n");
		exit(EXIT_FAILURE);
		return (0);
	}
}

void	merror(char *str)
{
	ft_putstr("str");
	exit(EXIT_FAILURE);
}
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
		ft_putstr("Un seul argument est attendu\n");
	else
		vars.fractal = found_fractal(argv[1]);		*/
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
