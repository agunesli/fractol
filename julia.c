/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 00:49:57 by agunesli          #+#    #+#             */
/*   Updated: 2022/05/31 00:55:09 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_vars *vars, t_complex c, double x, double y)
{
	int			i;
	double		tmp;
	t_complex	z;

	z.r = (vars->xmax - vars->xmin) * x / WIDTH + vars->xmin;
	z.i = (vars->ymax - vars->ymin) * y / HEIGHT + vars->ymin;
	i = 0;
	tmp = 0;
	while (i < vars->iter && (z.r * z.r + z.i * z.i) < 4)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		i++;
	}
	return (i);
}

void	draw_julia(t_vars *vars)
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
			c.r = vars->julia_ci.r;
			c.i = vars->julia_ci.i;
			i = julia(vars, c, x, y);
			color(vars, i);
			my_mlx_pixel_put(vars, x, y);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
