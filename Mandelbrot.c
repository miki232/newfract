/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:46:49 by mtoia             #+#    #+#             */
/*   Updated: 2022/06/25 15:20:10 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#include <math.h>

int	ftsclose(void *data)
{
	(void)data;
	exit(0);
}

void	calc(t_fract *d)
{
	d->ore = d->newre;
	d->oim = d->newim;
	d->newre = d->ore * d->ore - d->oim * d->oim + d->pr + d->incx;
	d->newim = d->inc * d->ore * d->oim + d->pi + d->incy;
}

void	calc1(t_fract *d)
{
	d->pr = 1.5 * (d->x - d->iw / 2) / (0.7 * d->zo * d->iw) + d->mmx;
	d->pi = (d->y - d->ih / 2) / (0.5 * d->zo * d->ih) + d->mvy;
	d->newre = 0;
	d->newim = 0;
	d->ore = 0;
	d->oim = 0;
	d->i = 0;
}

int	my_fract(t_fract *d)
{
	d->y = 0;
	while (d->y < d->ih)
	{
		d->x = 0;
		while (d->x < d->iw)
		{
			calc1(d);
			while (d->i < d->maxiterations)
			{
				calc(d);
				if ((d->newre * d->newre + d->newim * d->newim) > 4)
				{
					my_mlx_pixel_put(d, d->x, d->y, color(d->i, d));
					break ;
				}
				d->i++;
			}
			d->x++;
		}
		d->y++;
	}
	put2screen(d);
	return (0);
}
