
#include "fract.h"

int     main()
{
    fract   vars;

    vars.mlx_ptr = mlx_init();
    vars.win_ptr = mlx_new_window(vars.mlx_ptr, 680, 680, "SUCA FRA");
    vars.img = mlx_new_image(vars.mlx_ptr, 680, 680);
    vars.addr = mlx_get_data_addr(vars.img, &vars.bit_x_pixel, &vars.line_length, &vars.endian);
    my_fract();


}