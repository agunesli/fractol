/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:05:35 by agunesli          #+#    #+#             */
/*   Updated: 2022/05/31 01:02:23 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	draw(vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		ft_close(vars);
	else if (keycode == ESP && vars->zoom == 100)
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

int	mouse_move(int x, int y, t_vars *vars)
{
	if (vars->fractal == JULIA && vars->lock == 0)
	{
		vars->julia_ci.r = 2 * (double)x / WIDTH - 1;
		vars->julia_ci.i = 2 * (double)y / HEIGHT - 1;
		draw(vars);
	}
	return (0);
}

void	mouse_hook2(double hx, double hy, double hz, t_vars *vars)
{
	hz = 1.1f;
	vars->zoom *= hz;
	vars->xmin = vars->xmin * hz + hx * (1 - hz);
	vars->ymin = vars->ymin * hz + hy * (1 - hz);
	vars->xmax = vars->xmax * hz + hx * (1 - hz);
	vars->ymax = vars->ymax * hz + hy * (1 - hz);
	vars->iter -= 5;
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	double	hx;
	double	hy;
	double	hz;

	hx = x * (vars->xmax - vars->xmin) / WIDTH + vars->xmin;
	hy = y * (vars->ymax - vars->ymin) / HEIGHT + vars->ymin;
	if (button == 4)
	{
		hz = 0.9f;
		vars->zoom *= hz;
		vars->xmin = vars->xmin * hz + hx * (1 - hz);
		vars->ymin = vars->ymin * hz + hy * (1 - hz);
		vars->xmax = vars->xmax * hz + hx * (1 - hz);
		vars->ymax = vars->ymax * hz + hy * (1 - hz);
		vars->iter += 5;
	}
	else if (button == 5)
		mouse_hook2(hx, hy, hz, vars);
	draw(vars);
	return (0);
}
