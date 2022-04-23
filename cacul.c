//#include "fractol.h"
#include <math.h>
#include <stdio.h>
#define xmin -10
#define ymin -10
#define xmax 10
#define ymax 10

typedef struct	s_complex
{
	double	r;
	double	i;
}	t_complex;

t_complex	*mult(t_complex *z1, t_complex *z2)
{
	t_complex	*z;

	z->r = z1->r * z2->r - z1->i * z2->i;
	z->i = z1->r * z2->i + z1->i * z2->r;
	return (z);
}

double	dist(t_complex *z)
{
	return (sqrt(z->r * z->r + z->i * z->i));
}

t_complex	*add(t_complex *z1, t_complex *z2)
{
	t_complex	*z;

	z->r = z1->r + z2->r;
	z->i = z1->i + z2->i;
	return (z);
}

int	quad(t_complex *c)
{
	t_complex	*z;
	int		iteri;
	int		i;

	z->r = 0;
	z->i = 0;
	iteri = 100;
	i = 0;
	while (i < iteri)
	{	
		z = add(mult(z, z), c);
		i++;
	}	
	if (dist(z) < xmax)
		return (1);
	return (0);	
}

int	geom(t_complex *c)
{
	t_complex	*z;
	int		iteri;
	int		i;

	z->r = 0;
	z->i = 0;
	iteri = 100;
	i = 0;
	while (i < iteri)
	{	
		z = mult(z, c);
		i++;
	}	
	if (dist(z) < xmax)
		return (1);
	return (0);	
}

void	figure()
{
	double	delta;
	double	i;
	double	j;
	t_complex	c;

	i = xmin;
	j = ymin;
	delta = 1;
	while (i < xmax)
	{
		while (j < ymax)
		{
			c.r = i;
			c.i = j;
			if (geom(&c))
				printf("bouh\n"); //put_pixel
			j += delta;
		}
		i += delta;
	}
}
