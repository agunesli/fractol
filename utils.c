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
		return (MANDELBROT);
	else if (!ft_strncmp("Julia", fract, 6))
		return (JULIA);
	else if (!ft_strncmp("Flocon de Koch", fract, 14))
		return (KOCH);
	else
	{
		ft_putstr("usage : fractol [fractals]\n fractals : \n");
		ft_putstr(" --> Mandelbort\n --> Julia\n --> Flocon de Koch\n");
		exit(EXIT_FAILURE);
		return (0);
	}
}

void	merror(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}
