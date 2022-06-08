
#include "fract.h"

void	my_mlx_pixel_put(fract *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bit_x_pixel / 8));
	*(unsigned int*)dst = color;
}

int    my_fract(fract data, var getimg)
{
	data.y = 0;
	// getimg.MinRe = -0.5;////
	// getimg.MaxRe = 0.5;/////////cambiando i valori si riesce a fare una sorta di zoom
	// getimg.MinIm = -0.50;/////
	double MaxIm = getimg.MinIm+(getimg.MaxRe-getimg.MinRe)*getimg.ImageHeight/getimg.ImageWidth;
	double Re_factor = (getimg.MaxRe - getimg.MinRe)/(getimg.ImageWidth-1);
	double Im_factor = (MaxIm-getimg.MinIm)/(getimg.ImageHeight-1);
	unsigned MaxIterations = 30;
	data.x = 0;
	unsigned int n = 0;

	while(data.y++ < getimg.ImageHeight)
	{
		double c_im = MaxIm - data.y * Im_factor;
		data.x = 0;
		while (data.x++ < getimg.ImageWidth)
		{
			double c_re = getimg.MinRe + data.x * Re_factor;

			double Z_re = c_re, Z_im = c_im;
			data.isinside = 1;
			n = 0;
			while(++n < MaxIterations)
			{
				double Z_re2 = Z_re*Z_re;
				double Z_im2 = Z_im*Z_im;
				if(Z_re2 + Z_im2 > 4)
				{
					data.isinside = 0;
					break;
				}
				// if (Z_re2 + Z_im2 < 0.05)
				// {
				// 	mlx_pixel_put(data.mlx_ptr, data.win_ptr, data.x, data.y, 0x00FFFFFF);
				// }
				// if (Z_re2 + Z_im2 <= 1)
				// {
				// 	my_mlx_pixel_put(data.mlx_ptr, data.x, data.y, 0x00D3BEFB);
				// }
				// if (Z_re2 + Z_im2 < 0.2)
				// {
				// 	my_mlx_pixel_put(data.mlx_ptr, data.x, data.y, 0x00CC8AFF);
				// }
				Z_im = 2*Z_re*Z_im + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
			}
			if(data.isinside)
			{
				my_mlx_pixel_put(&data, data.x, data.y, 0x00FFFFFF);
			}
		}
	}
	mlx_hook(data.win_ptr, 2, 1L<<0, keypress, &data);
	//mlx_hook(data.win_ptr, 2, 1L<<0, ftclose, &data);
	put2screen(data);
	return(0);
}

int zoom(var get)
{
	//get.MaxRe = get.MaxRe + 0.5;
	//mlx_loop_hook(data.mlx_ptr, my_fract, &get);
	//put2screen(data);
	// my_fract(data, get);
	printf("%f", get.MaxRe);
	return(0);
}

int	keypress(int key, var get, fract data)
{
	data.y = 0;
	if (key == ESC)
		exit(0);
	if (key == D)
		zoom(get);
	return (0);		
}

void  put2screen(fract data)
{
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 0);
    mlx_loop(data.mlx_ptr);
}