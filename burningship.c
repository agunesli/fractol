/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:03:21 by agunesli          #+#    #+#             */
/*   Updated: 2022/05/23 12:03:23 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

double	abs(double x)
{
	if (x >= 0)
		return (x);
	else
		return (-x);
}

int	burningship(t_vars *vars, t_complex c)
{
	int			i;
	double		dist;
	double		tmp;
	t_complex	z;

	z.r = 0;
	z.i = 0;
	dist = z.r * z.r + z.i * z.i;
	i = 0;
	tmp = 0;
	while (i < vars->iter && dist < 4)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = abs(2 * z.i * tmp) + c.i;
		dist = z.r * z.r + z.i * z.i;
		i++;
	}
	return (i);
}

void	draw_burningship(t_vars *vars)
{
	double		x;
	double		y;
	t_complex	c;
	int			i;

	i = 0;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c.r = x * (vars->xmax - vars->xmin) / WIDTH + vars->xmin;
			c.i = y * (vars->ymax - vars->ymin) / HEIGHT + vars->ymin;
			i = burningship(vars, c);
			color(vars, i);
			my_mlx_pixel_put(vars, x, y);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
