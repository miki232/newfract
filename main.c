
#include "fract.h"

int     main()
{
 
    fract   data;
    var     getimg;
    getimg.ImageHeight = 900;
    getimg.ImageWidth = 900;
    getimg.MaxRe = 0.50;
    getimg.MinIm = -1.0;
    getimg.MinRe = -0.80;
    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, 900, 900, "SUCA FRA");
    data.img = mlx_new_image(data.mlx_ptr, 900, 900);
    data.addr = mlx_get_data_addr(data.img, &data.bit_x_pixel, &data.line_length, &data.endian);
    my_fract(data, getimg);

}