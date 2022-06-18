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
    double zoom;
    double moveX;
    double moveY;
    double inc;

}               fract;

typedef struct t_mouse
{
    double	x;
	double	y;
	double	prev_x;
	double	prev_y;
	int 	left_down;
	int 	mid_down;
}             s_mouse;



enum {
    KB_PAGE_UP = 116,
    KB_PAGE_DOWN = 121,
	ESC = 53,
	PLUS = 69,
    MINUS = 78,
    LEFT = 123,
    RIGHT = 124,
    DOWN = 125,
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
int    julia(fract *data);
void    draw(fract data);
void	isnside_check(fract data);
int	ft_atoi(const char *str);
int	ftclose(int keycode, fract *vars);
int	clear(fract *data);
int	mouse_move(int x, int y, s_mouse *mouse);
// int	mouseclick(int x, int y, s_mouse *mouse);
# endif