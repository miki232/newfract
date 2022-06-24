/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:46:26 by mtoia             #+#    #+#             */
/*   Updated: 2022/06/25 00:36:21 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int    julia(fract *data)
{
	double newRe, newIm, oldRe, oldIm;  //real and imaginary parts of new and old
	 //you can change these to zoom and change position
	//ColorRGB color; //the RGB color value for the pixel //after how much iterations the function should stop

	int y;
	int x;
	int i;
	//pick some values for the constant c, this determines the shape of the Julia Set
	//cRe = -0.7;
	// cIm = 0.27015;
	//loop through every pixel
	i = 0;
	y = 0;
	while (y < data->ImageHeight) //for (int y = 0; y < h; y++)
	{
		x = 0;
		while (x < data->ImageWidth) //for (int x = 0; x < w; x++)
		{
			//calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
			newRe = 1.5 * (x - data->ImageWidth / 2) / (0.5 * data->zoom * data->ImageWidth) + data->moveX;
			newIm = (y - data->ImageHeight / 2) / (0.5 * data->zoom * data->ImageHeight) + data->moveY;
			//i will represent the number of iterations
			i = 0;
			//start the iteration process
			while (i < data->maxIterations)//for(i = 0; i < maxIterations; i++)
			{
				//remember value of previous iteration
				oldRe = newRe;
				oldIm = newIm;
				//the actual iteration, the real and imaginary part are calculated
				newRe = oldRe * oldRe - oldIm * oldIm + data->cRe;
				newIm = 2 * oldRe * oldIm + data->cIm;
				//if the point is outside the circle with radius 2: stop
				if((newRe * newRe + newIm * newIm) > 5)
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
	return(0);
}
