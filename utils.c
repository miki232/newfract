/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:21:38 by mtoia             #+#    #+#             */
/*   Updated: 2022/06/26 16:50:31 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	zoom(t_fract *data)
{
	data->zo = data->zo * 1.1;
	clear(data);
	if (data->which_fract == 1)
	{
		my_fract(data);
		data->maxiterations += 0.3;
	}
	else if (data->which_fract == 2)
		julia(data);
	return (0);
}

int	zoomout(t_fract *data)
{
	data->zo = data->zo / 1.1;
	clear(data);
	if (data->which_fract == 1)
	{
		my_fract(data);
		data->maxiterations -= 0.3;
	}
	else if (data->which_fract == 2)
		julia(data);
	return (0);
}

int	left(t_fract *data)
{
	data->mmx = data->mmx + 0.1 / data->zo;
	data->movex = data->movex + 0.1 / data->zo;
	clear(data);
	if (data->which_fract == 1)
		my_fract(data);
	else if (data->which_fract == 2)
		julia(data);
	return (0);
}

int	right(t_fract *data)
{
	data->mmx = data->mmx - 0.1 / data->zo;
	data->movex = data->movex - 0.1 / data->zo;
	clear(data);
	if (data->which_fract == 1)
		my_fract(data);
	else if (data->which_fract == 2)
		julia(data);
	return (0);
}

void	up(t_fract *data)
{
	data->mvy = data->mvy + 0.1 / data->zo;
	clear(data);
	if (data->which_fract == 1)
		my_fract(data);
	else if (data->which_fract == 2)
		julia(data);
}
