#ifndef FRACT_H
# define FRACT_H
#include "mlx/mlx.h"
#include <stdio.h>


typedef struct t_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img;
    char    *addr;
    int     bit_x_pixel;
    int     line_length;
    int     endian;
    int     x;
    int     y;
}               fract;


# endif