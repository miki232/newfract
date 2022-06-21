
#include "fract.h"

int    julia(fract *data)
{
	double newRe, newIm, oldRe, oldIm;  //real and imaginary parts of new and old
	 //you can change these to zoom and change position
	//ColorRGB color; //the RGB color value for the pixel
	int maxIterations = 30; //after how much iterations the function should stop
	int h = 800;
	int w = 800;
	//pick some values for the constant c, this determines the shape of the Julia Set
	//cRe = -0.7;
	// cIm = 0.27015;
	//loop through every pixel
	for (int y = 0; y < h; y++)
	for (int x = 0; x < w; x++)
	{
		//calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
		newRe = 1.5 * (x - w / 2) / (0.5 * data->zoom * w) + data->moveX;
		newIm = (y - h / 2) / (0.5 * data->zoom * h) + data->moveY;
		//i will represent the number of iterations
		int i;
		//start the iteration process
		for(i = 0; i < maxIterations; i++)
		{
		//remember value of previous iteration
		oldRe = newRe;
		oldIm = newIm;
		//the actual iteration, the real and imaginary part are calculated
		newRe = oldRe * oldRe - oldIm * oldIm + data->cRe;
		newIm = 2 * oldRe * oldIm + data->cIm;
		//if the point is outside the circle with radius 2: stop
		if ((newRe * newRe + newIm * newIm) > 1)
					my_mlx_pixel_put(data, x, y, 0x000002);
			if ((newRe * newRe + newIm * newIm) > 2)
				my_mlx_pixel_put(data, x, y, 0xFF6100);
			if ((newRe * newRe + newIm * newIm) > 2.5)
				my_mlx_pixel_put(data, x, y, 0xFFB600);
			if((newRe * newRe + newIm * newIm) > 3) 
				my_mlx_pixel_put(data, x, y, 0xFFF300);
			if((newRe * newRe + newIm * newIm) > 3.5) 
				my_mlx_pixel_put(data, x, y, 0x00FFE4);
			if((newRe * newRe + newIm * newIm) > 4) 
				my_mlx_pixel_put(data, x, y, 0x00CDFF);
			if((newRe * newRe + newIm * newIm) > 4.5) 
				my_mlx_pixel_put(data, x, y, 0x1C75FF);
			if((newRe * newRe + newIm * newIm) > 5)
			{
					my_mlx_pixel_put(data, x, y, 0x1C3BFF);
					break;
			}
		}
		//use color model conversion to get rainbow palette, make brightness black if maxIterations reached
		//color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < maxIterations)));
		//draw the pixel
		//pset(x, y, color);
	}
	//make the Julia Set visible and wait to exit
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