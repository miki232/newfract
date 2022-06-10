/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:44:22 by mtoia             #+#    #+#             */
/*   Updated: 2022/06/10 10:04:46 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	my_mlx_pixel_put(fract *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bit_x_pixel / 8));
	*(unsigned int*)dst = color;
}

int	clear(fract *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, 900, 900);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return(0);
}

void  put2screen(fract *data)
{
	printf("%s\n", "Testazza di minchia");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
    mlx_loop(data->mlx_ptr);
}