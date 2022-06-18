
#include "fract.h"
#include <math.h>


int    my_fract(fract *data)
{
	// data->y = 0;
	// data->MaxIm = data->MinIm+(data->MaxRe-data->MinRe)*data->ImageHeight/data->ImageWidth;
	// double Re_factor = (data->MaxRe - data->MinRe)/(data->ImageWidth-1);
	// double Im_factor = (data->MaxIm-data->MinIm)/(data->ImageHeight-1);
	// unsigned MaxIterations = 30;
	// data->x = 0;
	// unsigned int n = 0;
	//int color;
	double pr, pi;           //real and imaginary part of the pixel p
	double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old z
	// data->zoom = 1, data->moveX = -0.5, data->moveY = 0; //you can change these to zoom and change position
	//ColorRGB color; //the RGB color value for the pixel
	int maxIterations = 20;//after how much iterations the function should stop
	int h = 1000;
	int w = 1000;
	int y;
	y = 0;
	int x;
	x = 0;

	//loop through every pixel
	//for(int y = 0; y < h; y++)
	while(y < h)
	{
		x = 0;//for(int x = 0; x < w; x++)
		while (x < w)
		{
			//calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
			pr = 1.5 * (x - w / 2) / (0.7 * data->zoom * w) + data->moveX;
			pi = (y - h / 2) / (0.5 * data->zoom * h) + data->moveY;
			newRe = newIm = oldRe = oldIm = 0; //these should start at 0,0
			//"i" will represent the number of iterations
			int i;
			//start the iteration process
			for(i = 0; i < maxIterations; i++)
			{
			//remember value of previous iteration
			oldRe = newRe;
			oldIm = newIm;
			//the actual iteration, the real and imaginary part are calculated
			newRe = oldRe * oldRe - oldIm * oldIm + pr;
			newIm = data->inc * oldRe * oldIm + pi;
			//if the point is outside the circle with radius 2: stop
			//color = r(i % 256, 255, 255 * (i < maxIterations)));
			// if ((newRe * newRe + newIm * newIm) > 1)
			// 	{
			// 		my_mlx_pixel_put(data, x, y, 0xf59490); ///no PorcoDio
			// 			//
			// 	}
			if ((newRe * newRe + newIm * newIm) > 2.5)
					my_mlx_pixel_put(data, x, y, 0x040b59);
			if ((newRe * newRe + newIm * newIm) > 3.5)
					my_mlx_pixel_put(data, x, y, 0x1722a3);
			if((newRe * newRe + newIm * newIm) > 4.5) 
					my_mlx_pixel_put(data, x, y, 0x4854db);
			if((newRe * newRe + newIm * newIm) > 5) 
			{
				my_mlx_pixel_put(data, x, y, 0x9ba2e8);
				break;
			}
			}
			x++;
		}
		y++;
		//use color model conversion to get rainbow palette, make brightness black if maxIterations reached
		//draw the pixel
		//pset(x, y, color);
	}
	// while(data->y++ < data->ImageHeight)
	// {
	// 	double c_im = data->MaxIm - data->y * Im_factor;
	// 	data->x = 0;
	// 	while (data->x++ < data->ImageWidth)
	// 	{
	// 		double c_re = data->MinRe + data->x * Re_factor;

	// 		double Z_re = c_re, Z_im = c_im;
	// 		data->isinside = 1;
	// 		n = 0;
	// 		while(++n < MaxIterations)
	// 		{
	// 			double Z_re2 = Z_re*Z_re;
	// 			double Z_im2 = Z_im*Z_im;
	// 			if(Z_re2 + Z_im2 > 4)
	// 			{
	// 				data->isinside = 0;
	// 				break;
	// 			}
	// 			Z_im = 2*Z_re*Z_im + c_im;
	// 			Z_re = Z_re2 - Z_im2 + c_re;
	// 		}
	// 		if(data->isinside)
	// 		{
	// 			my_mlx_pixel_put(data, data->x, data->y, 0x00FFFFFF);
	// 		}
	// 	}
	// }
	put2screen(data);
	return(0);
}
