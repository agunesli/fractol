/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:04:07 by agunesli          #+#    #+#             */
/*   Updated: 2022/05/23 12:12:41 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color(t_vars *vars, int i)
{
	if (i == vars->iter)
	{
		vars->color.r = 0.0;
		vars->color.g = 0.0;
		vars->color.b = 0.0;
	}
	else
	{
		vars->color.r = (vars->color.rr * i) * 255 / vars->iter;
		vars->color.g = (vars->color.rg * i) * 255 / vars->iter;
		vars->color.b = (vars->color.rb * i) * 255 / vars->iter;
	}
}

void	color_shift(t_vars *vars)
{
	vars->color.rr = vars->color.rr + 1 % 255;
	vars->color.rb = vars->color.rb + 10 % 255;
	vars->color.rg = vars->color.rg + 100 % 255;
	draw(vars);
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
		*(unsigned int *)dst = color;
	}
}
