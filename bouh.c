#include "fractol.h"
#include <stdio.h>

int	key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	printf("keycode is %d\n", keycode);
	return (0);
}

int	mlx_mouse_move(void *win, int x, int y)
{
	printf("x = %d, y = %d\n",x,y);
	
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_mouse_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
