/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:33:47 by mtoia             #+#    #+#             */
/*   Updated: 2022/06/26 17:03:51 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	down(t_fract *data)
{
	data->mvy = data->mvy - 0.1 / data->zo;
	clear(data);
	if (data->which_fract == 1)
		my_fract(data);
	else if (data->which_fract == 2)
		julia(data);
}

void	inv_up(t_fract *data)
{
	data->inc = data->inc + 0.1;
	data->cre = data->cre + 0.001;
	clear(data);
	if (data->which_fract == 1)
		my_fract(data);
	else if (data->which_fract == 2)
		julia(data);
}

void	inv_down(t_fract *data)
{
	data->inc = data->inc - 0.1;
	data->cre = data->cre - 0.001;
	clear(data);
	if (data->which_fract == 1)
		my_fract(data);
	else if (data->which_fract == 2)
		julia(data);
}

int	keypress(int key, t_fract *data)
{
	if (key == ESC)
		exit(0);
	if (key == PLUS)
		zoom(data);
	if (key == MINUS)
		zoomout(data);
	if (key == LEFT || key == D)
		left(data);
	if (key == DOWN || key == W)
		down(data);
	if (key == RIGHT || key == A)
		right(data);
	if (key == UP || key == S)
		up(data);
	if (key == KB_PAGE_UP)
		inv_up(data);
	if (key == KB_PAGE_DOWN)
		inv_down(data);
	return (0);
}

int	mouse(int button, int x, int y, t_fract *param)
{
	(void)x;
	(void)y;
	if (button == 4)
		zoom(param);
	else if (button == 5)
		zoomout(param);
	return (0);
}
