//#include "fractol.h"
#include <math.h>
double	*mult(double z1[2], double z2[2])
{
	double	z[2];

	z[0] = z1[0] * z2[0] - z1[1] * z2[1];
	z[1] = z1[0] * z2[1] + z1[1] * z2[0];
	return (z);
}

double	*dist(double z[2])
	return (sqrt(z[0] * z[0] + z[1] * z[1]));

int	geom(double c[2])
{
	double	z[2];
	double	iteri;
	double	i;

	z[0] = 1;
	z[1] = 0;
	iteri = 10;
	i = 0;
	while (i < iteri)
	{	
		z = mult(z, c);
		i++;
	}	
	if (dist(z) > xmin)
		return (0);
	else
		return (1);	
}
