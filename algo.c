
#include "fract.h"

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