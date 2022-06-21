
#include "fract.h"
#include <math.h>

int	my_fract(fract *data)
{
	double	pr, pi; //real and imaginary part of the pixel p
	double	newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old z
	// data->zoom = 1, data->moveX = -0.5, data->moveY = 0; //you can change these to zoom and change position
	//ColorRGB color; //the RGB color value for the pixel
	int maxIterations = 20;//after how much iterations the function should stop
	int h = 800;
	int w = 800;
	int y;
	y = 0;
	int x;
	x = 0;
	//loop through every pixel
	//for(int y = 0; y < h; y++)
	while (y < h)
	{
		x = 0;//for(int x = 0; x < w; x++)
		while (x < w)
		{
			//calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
			pr = 1.5 * (x - w / 2) / (0.7 * data->zoom * w) + data->MamoveX;
			pi = (y - h / 2) / (0.5 * data->zoom * h) + data->moveY;
			newRe = newIm = oldRe = oldIm = 0; //these should start at 0,0
			//"i" will represent the number of iterations
			int	i;
			//start the iteration process
			for (i = 0; i < maxIterations; i++)
			{
			//remember value of previous iteration
			oldRe = newRe;
			oldIm = newIm;
			//the actual iteration, the real and imaginary part are calculated
			newRe = oldRe * oldRe - oldIm * oldIm + pr;
			newIm = data->inc * oldRe * oldIm + pi;
			//if the point is outside the circle with radius 2: stop
			//color = r(i % 256, 255, 255 * (i < maxIterations)));
			if ((newRe * newRe + newIm * newIm) > 1)
					my_mlx_pixel_put(data, x, y, 0x000002);
			if ((newRe * newRe + newIm * newIm) > 2)
				my_mlx_pixel_put(data, x, y, 0xFF6100);
			if ((newRe * newRe + newIm * newIm) > 2.5)
				my_mlx_pixel_put(data, x, y, 0xFFB600);
			if ((newRe * newRe + newIm * newIm) > 3) 
				my_mlx_pixel_put(data, x, y, 0xFFF300);
			if ((newRe * newRe + newIm * newIm) > 3.5) 
				my_mlx_pixel_put(data, x, y, 0x00FFE4);
			if ((newRe * newRe + newIm * newIm) > 4) 
				my_mlx_pixel_put(data, x, y, 0x00CDFF);
			if ((newRe * newRe + newIm * newIm) > 4.5) 
				my_mlx_pixel_put(data, x, y, 0x1C75FF);
			if ((newRe * newRe + newIm * newIm) > 5)
			{
					my_mlx_pixel_put(data, x, y, 0x1C3BFF);
					break;
			}
			}
			x++;
		}
		y++;
	}
	put2screen(data);
	return (0);
}
