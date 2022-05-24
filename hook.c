/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:05:35 by agunesli          #+#    #+#             */
/*   Updated: 2022/05/24 19:00:10 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	move_fractal(int keycode, t_vars *vars)
{
	t_complex	r;

	r.r = vars->xmax - vars->xmin;
	r.i = vars->ymax - vars->ymin;
	if (keycode == DOWN || keycode == S)
	{
		vars->ymin += r.i * 0.05;
		vars->ymax += r.i * 0.05;
	}
	else if (keycode == UP || keycode == W)
	{
		vars->ymin -= r.i * 0.05;
		vars->ymax -= r.i * 0.05;
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
//	printf("xmin = %f, xmax = %f, ymin = %f, ymax = %f \n",vars->xmin, vars->xmax, vars->ymin, vars->ymax);
	draw(vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		ft_close(vars);
	else if (keycode == ESP)
		vars->lock = !vars->lock;
	else if (keycode == UP || keycode == DOWN \
	|| keycode == LEFT || keycode == RIGHT \
	|| keycode == A || keycode == S \
	|| keycode == W || keycode == D)
		move_fractal(keycode, vars);
	else if (keycode == C)
		color_shift(vars);
	else if (keycode == M)
	{
		vars->fractal = (vars->fractal + 1) % 3;
		init_data(vars);
		draw(vars);
	}
	return (0);
}
/*
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
}*/
/*
void	apply_zoom(int x, int y, t_vars *vars)
{
	printf("xmin is %f ymin is %f\n",vars->xmin, vars->ymin);
	vars->xmin = ((x + (WIDTH >> 1)) / (vars->zoom / 2)) / -2;
	vars->ymin = ((y + (HEIGHT >> 1)) / (vars->zoom / 2)) / -2;
}*/

/*
static void	apply_zoom(int x, int y, t_vars *vars)
{
	double h = 0.05;

	vars->xmin = x + h;
	vars->xmax = x - h;
	vars->ymin = y + h;
	vars->ymax = y - h;
}
*/
int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	double	hx;
	double	hy;

	hx = 0.1;
	hy = hx;
//	double hx = IDTH / (vars->xmax - vars->xmin) + vars->xmin;
//	double hy = HEIGHT / (vars->ymax - vars->ymin) + vars->ymin;
	if (vars->fractal == JULIA && vars->lock == 0)
	{
//		vars->julia_ci.r = x;
//		vars->julia_ci.i = y;
		vars->julia_ci.r = 2 * (double)x / WIDTH - 1;
		vars->julia_ci.i = 2 * (double)y / HEIGHT - 1;
//		draw(vars);
//		write(1,"bouh\n",5);
	}
	if (button == 4)
	{
		vars->zoom += 100;
		vars->xmin += hx;
		vars->ymin += hy;
		vars->xmax -= hx;
		vars->ymax -= hy;
//		apply_zoom(x, y, vars);
		vars->iter += 5;
	}
	else if (button == 5)
	{
		vars->zoom -= 100;
		vars->xmin -= hx;
		vars->ymax += hy;
		vars->ymin -= hy;
		vars->xmax += hx;
//		apply_zoom(x, y, vars);
		vars->iter -= 5;
	}
//	printf("xmin = %f, xmax = %f, ymin = %f, ymax = %f \n",vars->xmin, vars->xmax, vars->ymin, vars->ymax);
	draw(vars);
	return (0);
}

