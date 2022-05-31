/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:08:04 by agunesli          #+#    #+#             */
/*   Updated: 2022/06/01 01:50:34 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	int	nb;

	nb = write(1, str, ft_strlen(str));
	(void)nb;
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
		return (MANDELBROT);
	else if (!ft_strncmp("Julia", fract, 6))
		return (JULIA);
	else if (!ft_strncmp("Burningship", fract, 11))
		return (BURNINGSHIP);
	else
	{
		ft_putstr("usage : fractol [fractals]\n fractals : \n");
		ft_putstr(" --> Mandelbrot\n --> Julia\n --> Burningship\n");
		exit(EXIT_FAILURE);
		return (0);
	}
}

void	merror(char *str, t_vars *vars)
{
	ft_putstr(str);
	if (vars->mlx)
		free(vars->mlx);
	exit(EXIT_FAILURE);
}
