/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:33:47 by mtoia             #+#    #+#             */
/*   Updated: 2022/06/17 21:26:07 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"


int zoom(fract *data)
{
	data->zoom = data->zoom * 1.2;
	//data->MinRe = data->MinRe + 0.02;
	clear(data);
	my_fract(data);
	return(0);
}

int zoomout(fract *data)
{
	data->zoom = data->zoom / 1.5;

	clear(data);
	my_fract(data);
	return(0);
}

int left(fract *data)
{
	data->moveX = data->moveX + 0.001; //* data->zoom;
	//data->MaxRe = data->MaxRe + 0.01 * data->zoom;
	clear(data);
	my_fract(data);
	return(0);
}

int right(fract *data)
{
	data->moveX = data->moveX - 0.001;
	//data->MaxRe = data->MaxRe - 0.01f;
	clear(data);
	my_fract(data);
	return(0);
}

void	up(fract *data)
{
	data->moveY = data->moveY + 0.01;
	clear(data);
	my_fract(data);
}

void	down(fract *data)
{
	data->moveY = data->moveY - 0.001;
	clear(data);
	my_fract(data);
}

void	inv_up(fract *data)
{
	data->inc = data->inc + 0.1;
	clear(data);
	my_fract(data);
}

void	inv_down(fract *data)
{
	data->inc = data->inc - 0.1;
	clear(data);
	my_fract(data);
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
	if (key == DOWN)
		down(data);
	if (key == KB_PAGE_UP)
	{
		inv_up(data);
	}
	if (key == KB_PAGE_DOWN)
	{
		inv_down(data);
	}
	return (0);		
}