
#include "fract.h"

void	my_mlx_pixel_put(fract *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bit_x_pixel / 8));
	*(unsigned int*)dst = color;
}

int    my_fract(fract *data)
{
	data->y = 0;
	data->MaxIm = data->MinIm+(data->MaxRe-data->MinRe)*data->ImageHeight/data->ImageWidth;
	double Re_factor = (data->MaxRe - data->MinRe)/(data->ImageWidth-1);
	double Im_factor = (data->MaxIm-data->MinIm)/(data->ImageHeight-1);
	unsigned MaxIterations = 30;
	data->x = 0;
	unsigned int n = 0;

	while(data->y++ < data->ImageHeight)
	{
		double c_im = data->MaxIm - data->y * Im_factor;
		data->x = 0;
		while (data->x++ < data->ImageWidth)
		{
			double c_re = data->MinRe + data->x * Re_factor;

			double Z_re = c_re, Z_im = c_im;
			data->isinside = 1;
			n = 0;
			while(++n < MaxIterations)
			{
				double Z_re2 = Z_re*Z_re;
				double Z_im2 = Z_im*Z_im;
				if(Z_re2 + Z_im2 > 4)
				{
					data->isinside = 0;
					break;
				}
				Z_im = 2*Z_re*Z_im + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
			}
			if(data->isinside)
			{
				my_mlx_pixel_put(data, data->x, data->y, 0x00FFFFFF);
			}
		}
	}
	put2screen(data);
	return(0);
}


int zoom(fract *data)
{
	data->MaxRe = data->MaxRe - 0.02;
	data->MinRe = data->MinRe + 0.02;
	clear(data);
	my_fract(data);
	return(0);
}

int zoomout(fract *data)
{
	data->MaxRe = data->MaxRe + 0.01f;

	clear(data);
	my_fract(data);
	return(0);
}

int left(fract *data)
{
	data->MinRe = data->MinRe + 0.01 * data->zoom;
	data->MaxRe = data->MaxRe + 0.01 * data->zoom;
	clear(data);
	my_fract(data);
	return(0);
}

int right(fract *data)
{
	data->MinRe = data->MinRe - 0.01f;
	data->MaxRe = data->MaxRe - 0.01f;
	clear(data);
	my_fract(data);
	return(0);
}

void	up(fract *data)
{
	data->MaxRe = data->MaxRe + 0.1;
	data->MinRe = data->MinRe - 0.1;
	clear(data);
	my_fract(data);
}

int	clear(fract *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, 900, 900);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return(0);
}

int	keypress(int key, fract *data)
{
	if (key == ESC)
		exit(0);
	if (key == PLUS)
	{
		zoom(data);
	}
	if (key == MINUS)
	{
		zoomout(data);
	}
	if (key == RIGHT)
	{
		right(data);
	}
	if (key == 126)
	{
		up(data);
	}
	if (key == LEFT)
		left(data);
	return (0);		
}

void  put2screen(fract *data)
{
	printf("%d", data->x);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
    mlx_loop(data->mlx_ptr);
}