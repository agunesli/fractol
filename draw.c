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
