#include "fractol.h"

void	move_fractal(int keycode, t_vars *vars)
{
	t_complex	r;

	r.r = vars->xmax - vars->xmin;
	r.i = vars->ymax - vars->ymin;
	if (keycode == DOWN || keycode == S)
	{
		vars->ymin -= r.i * 0.05;
		vars->ymax -= r.i * 0.05;
	}
	else if (keycode == UP || keycode == W)
	{
		vars->ymin += r.i * 0.05;
		vars->ymax += r.i * 0.05;
	}
	else if (keycode == RIGHT || keycode == D)
	{
		vars->xmin += r.r * 0.05;
		vars->xmax += r.r * 0.05;
	}
	else if (keycode == LEFT || keycode == A)
	{
		vars->xmin -= r.r * 0.05;
		vars->xmax -= r.r * 0.05;
	}
	draw(vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		ft_close(keycode, vars);
	else if (keycode == ESP)
		vars->lock = !vars->lock;
	else if (keycode == UP || keycode == DOWN \
	|| keycode == LEFT || keycode == RIGHT \
	|| keycode == A || keycode == S \
	|| keycode == W || keycode == D)
		move_fractal(keycode, vars);
/*	else if (keycode == C)
		color_change(vars);*/
	return (0);
}

static double	interpolate(double start, double end, double inter)
{
	return (start + ((end - start) * inter));
}

static void	apply_zoom(int x, int y, t_vars *vars)
{
	t_complex	mouse;
	double		inter;

	inter = 1.0 / vars->zoom;
	mouse.r = x / (WIDTH / (vars->xmax - vars->xmin)) + vars->xmin;
	mouse.i = y / (HEIGHT / (vars->ymax - vars->ymin)) + vars->ymin;
	vars->xmin = interpolate(mouse.r, vars->xmin, inter);
	vars->ymin = interpolate(mouse.i, vars->ymin, inter);
	vars->xmax = interpolate(mouse.r, vars->xmax, inter);
	vars->ymax = interpolate(mouse.i, vars->xmax, inter);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == 4 || button == 1)
	{
		vars->zoom = 0.80;
		apply_zoom(x, y, vars);
		vars->iter -= 5;
	}
	else if (button == 5 || button == 2)
	{
		vars->zoom = 1.20;
		apply_zoom(x, y, vars);
		vars->iter += 5;
	}
	draw(vars);
	return (0);
}
