#ifndef FRACT_H
# define FRACT_H
#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct t_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img;
    char    *addr;
    int     bit_x_pixel;
    int     line_length;
    int     endian;
    unsigned int     x;
    unsigned int     y;
    int     isinside;
    unsigned int	ImageHeight;
    unsigned int ImageWidth;
    double MinRe;
    double MaxRe;
    double MinIm;
    double MaxIm;

}               fract;

enum {
	ESC = 53,
	D = 2,
    LEFT = 123,
    RIGHT = 124,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void  put2screen(fract *data);
void	my_mlx_pixel_put(fract *data, int x, int y, int color);
int	keypress(int key, fract *data);
int    my_fract(fract *data);
void    draw(fract data);
void	isnside_check(fract data);
int	ft_atoi(const char *str);
int	ftclose(int keycode, fract *vars);
int	clear(fract *data);


# endif