/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunesli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:33:52 by agunesli          #+#    #+#             */
/*   Updated: 2022/04/09 16:19:29 by agunesli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../mlx/mlx.h"

# define MANDELBROT 1
# define JULIA 2
# define KOCH 3

# define WIDTH 1920
# define HEIGHT 1080

#  define ESC		65307

/*#  define K_NUM_MULT	65450
#  define K_NUM_DIV	65455
#  define K_NUM_PLUS	65451
#  define K_NUM_MINUS	65453
#  define K_NUM_ENTER	65421
#  define K_NUM_0	65438
#  define K_UP		65362
#  define K_DOWN	65364
#  define K_LEFT	65361
#  define K_RIGHT	65363
#  define K_DIGIT_1	49
#  define K_L		108*/


// bpp => bits_per_pixel;
typedef struct  s_vars {
        void    *mlx;
        void    *win;
        int     fractal;
	int	lock; //pour julia 
	double	zoom;
	double	xmin;
	double	ymin;
	double	xmax;
	double	ymax;
	double	iteri;
	double	x_coor;
	double	y_coor;
	double	x_img;
	double	y_img;
        void    *img;
        char    *addr;
        int     bpp;
        int     line_length;
        int     endian;
}	t_vars;

typedef struct  s_complex
{
        double  r;
        double  i;
}       t_complex;

// utils.c
int	ft_strlen(char *str);
void	ft_putstr(char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	found_fractal(char *fract);
void	merror(char *str);

#endif
