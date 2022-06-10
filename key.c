/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:33:47 by mtoia             #+#    #+#             */
/*   Updated: 2022/06/10 09:57:27 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"


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