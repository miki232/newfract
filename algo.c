
#include "fract.h"

void    my_fract(fract data)
{
    unsigned int	ImageHeight = 1080;
	unsigned int ImageWidth = 1019;
	unsigned int y = 0;
	double MinRe = -0.5;////
	double MaxRe = 0.5;/////////cambiando i valori si riesce a fare una sorta di zoom
	double MinIm = -0.50;/////
	double MaxIm = MinIm+(MaxRe-MinRe)*ImageHeight/ImageWidth;
	double Re_factor = (MaxRe-MinRe)/(ImageWidth-1);
	double Im_factor = (MaxIm-MinIm)/(ImageHeight-1);
	unsigned MaxIterations = 30;
	unsigned int x = 200;
	unsigned int n = 200;

	while(y++ < ImageHeight)
	{
		double c_im = MaxIm - y*Im_factor;
		x = 0;
		while (++x < ImageWidth)
		{
			double c_re = MinRe + x*Re_factor;

			double Z_re = c_re, Z_im = c_im;
			int isInside = 1;
			n = 0;
			while(++n < MaxIterations)
			{
				double Z_re2 = Z_re*Z_re;
				double Z_im2 = Z_im*Z_im;
				if(Z_re2 + Z_im2 > 4)
				{
					isInside = 0;
					break;
				}
				// if (Z_re2 + Z_im2 < 0.05)
				// {
				// 	my_mlx_pixel_put(&img, x, y, 0x00EFFDFD);
				// }
				// if (Z_re2 + Z_im2 <= 1)
				// {
				// 	my_mlx_pixel_put(&img, x, y, 0x00D3BEFB);
				// }
				// if (Z_re2 + Z_im2 < 0.2)
				// {
				// 	my_mlx_pixel_put(&img, x, y, 0x00CC8AFF);
				// }
				Z_im = 2*Z_re*Z_im + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
			}
			if(isInside)
			{
				//printf("%d\n", x);
				//x *= 0.5;
				//y *= 0.5;
				//printf("%d", x);
				//printf("%d   %d\n", x, y);
                data.x = x;
                data.y = y;
                draw();
			}
		}
		y++;
	}
}

void    draw(fract data);
{
    
}