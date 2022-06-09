
#include "fract.h"

int     main()
{
 
    fract   data;
    data.ImageHeight = 900;
    data.ImageWidth = 900;
    data.MaxRe = 2.0;
    data.MinIm = -0.80;
    data.MinRe = -1.0;
    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, 900, 900, "SUCA FRA");
    data.img = mlx_new_image(data.mlx_ptr, 900, 900);
    data.addr = mlx_get_data_addr(data.img, &data.bit_x_pixel, &data.line_length, &data.endian);
    mlx_hook(data.win_ptr, 2, 1L<<0, keypress, &data);
    my_fract(&data);
//////magari creare una funzione tipo print_pxl 
}