/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:33:47 by mtoia             #+#    #+#             */
/*   Updated: 2022/06/21 19:22:57 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

// int	mouseclick(int x, int y, s_mouse *mouse)
// {

// 	//printf("%d\n %d", x, y);
// 	printf("click");
// 	mouse->left_down = 1;
// 	return(0);
// }

int	mouse_move(int x, int y, s_mouse *mouse)
{
	mouse->prev_x = mouse->x;
	mouse->prev_y = mouse->y;
	mouse->x = x - 900;
	mouse->y = y - 900;
	if (mouse->left_down)
		printf("click");
	return (0);
}

int	zoom(fract *data)
{
	data->zoom = data->zoom * 1.2;
	clear(data);
	if (data->which_fract == 1)
		my_fract(data);
	else if (data->which_fract == 2)
		julia(data);
	return (0);
}

int	zoomout(fract *data)
{
	data->zoom = data->zoom / 1.5;
	clear(data);
	if (data->which_fract == 1)
		my_fract(data);
	else if (data->which_fract == 2)
		julia(data);
	return (0);
}

int	left(fract *data)
{
	data->moveX = data->moveX + 0.01;
	data->MamoveX = data->MamoveX + 0.01;
	clear(data);
	if (data->which_fract == 1)
		my_fract(data);
	else if (data->which_fract == 2)
		julia(data);
	return (0);
}

int	right(fract *data)
{
	data->MamoveX = data->MamoveX - 0.01;
	data->moveX = data->moveX - 0.01;
	clear(data);
	if (data->which_fract == 1)
		my_fract(data);
	else if (data->which_fract == 2)
		julia(data);
	return (0);
}

void	up(fract *data)
{
	data->moveY = data->moveY + 0.01;
	clear(data);
	if (data->which_fract == 1)
		my_fract(data);
	else if (data->which_fract == 2)
		julia(data);
}

void	down(fract *data)
{
	data->moveY = data->moveY - 0.001;
	clear(data);
	if (data->which_fract == 1)
		my_fract(data);
	else if (data->which_fract == 2)
		julia(data);
}

void	inv_up(fract *data)
{
	data->inc = data->inc + 0.1;
	data->cRe = data->cRe + 0.01;
	clear(data);
	if (data->which_fract == 1)
		my_fract(data);
	else if (data->which_fract == 2)
		julia(data);
}

void	inv_down(fract *data)
{
	data->inc = data->inc - 0.1;
	data->cRe = data->cRe - 0.01;
	clear(data);
	if (data->which_fract == 1)
		my_fract(data);
	else if (data->which_fract == 2)
		julia(data);
}

int	keypress(int key, fract *data)
{
	if (key == ESC)
		exit(0);
	if (key == PLUS)
		zoom(data);
	if (key == MINUS)
		zoomout(data);
	if (key == RIGHT)
		right(data);
	if (key == 126)
		up(data);
	if (key == LEFT)
		left(data);
	if (key == DOWN)
		down(data);
	if (key == KB_PAGE_UP)
		inv_up(data);
	if (key == KB_PAGE_DOWN)
		inv_down(data);
	// if (key == 1)
	// 	printf("click");
	return (0);
}
