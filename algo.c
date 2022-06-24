/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:46:49 by mtoia             #+#    #+#             */
/*   Updated: 2022/06/25 00:34:04 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#include <math.h>


int	my_fract(fract *data)
{
	double	pr, pi; //real and imaginary part of the pixel p
	double	newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old z
	// data->zoom = 1, data->moveX = -0.5, data->moveY = 0; //you can change these to zoom and change position
	//ColorRGB color; //the RGB color value for the pixel
	//after how much iterations the function should stop
	//data->maxIterations = 20;
	int h = data->ImageHeight;
	int w = data->ImageWidth;
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
			i = 0;
			//start the iteration process
			while (i < data->maxIterations)
			{
				//remember value of previous iteration
				oldRe = newRe;
				oldIm = newIm;
				//the actual iteration, the real and imaginary part are calculated
				newRe = oldRe * oldRe - oldIm * oldIm + pr;
				newIm = data->inc * oldRe * oldIm + pi;
				if ((newRe * newRe + newIm * newIm) > 5)
				{
						my_mlx_pixel_put(data, x, y, color(i, data));
						break;
				}
				
				i++;
				
			}
			x++;
		}
		y++;
	}
	put2screen(data);
	return (0);
}

 