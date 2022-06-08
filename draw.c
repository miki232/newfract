/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:44:22 by mtoia             #+#    #+#             */
/*   Updated: 2022/06/08 10:18:14 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"



void    draw(fract data)
{
	
	int i;
	i = 0;
	// mlx_pixel_put(data.mlx_ptr, data.win_ptr, data.x, data.y, 0x00FFFFFF);
	// while (i++ < 50)
	// {
	// 	mlx_pixel_put(data.mlx_ptr, data.win_ptr, i, i+10, 0x00FFFFFF);
	// }
	// mlx_loop(data.mlx_ptr);
	printf("%d  %d\n", data.x, data.y);
}

// void	isnside_check(fract data)
// {
// 	if(data.isinside)
// 	{
// 		mlx_pixel_put(data.mlx_ptr, data.win_ptr, data.y, data.x, 0x00FFFFFF);
// 	}
// }