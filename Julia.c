/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:46:26 by mtoia             #+#    #+#             */
/*   Updated: 2022/06/25 11:20:38 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	call(t_fract *d)
{
	d->newre = 1.5 * (d->x - d->iw / 2) / (0.5 * d->zo * d->iw) + d->movex;
	d->newim = (d->y - d->ih / 2) / (0.5 * d->zo * d->ih) + d->mvy;
	d->i = 0;
}

void	call1(t_fract *d)
{
	d->ore = d->newre;
	d->oim = d->newim;
	d->newre = d->ore * d->ore - d->oim * d->oim + d->cre;
	d->newim = 2 * d->ore * d->oim + d->cim;
}

int	julia(t_fract *d)
{
	d->y = 0;
	while (d->y < d->ih)
	{
		d->x = 0;
		while (d->x < d->iw)
		{
			call(d);
			while (d->i < d->maxiterations)
			{
				call1(d);
				if ((d->newre * d->newre + d->newim * d->newim) > 5)
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
