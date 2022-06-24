/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:38:28 by mtoia             #+#    #+#             */
/*   Updated: 2022/06/25 01:18:06 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
void	error(void)
{
	ft_printf("Please, insert whic fractal:\n");
	ft_printf("--Mandelbrot *Param*\n");
	ft_printf("--Julia *Param*\n");
	ft_printf("Example: ./fractol Mandelbrot 3\n");
	exit(0);
}

int	ftsclose(void *data)
{
	(void)data;
	exit(0);
}

void	whichfract(fract *data)
{
	if (data->which_fract == 1)
		my_fract(data);
	else
		julia(data);
}

void	init(fract *data)
{
	data->ImageHeight = 800;
	data->ImageWidth = 800;
	data->moveX = 0;
	data->moveY = 0;
	data->maxIterations = 20;
	data->which_fract = 0;
	data->inc = 2;
	data->cIm = 0.27015;
	data->cRe = -0.7;
}

int	main(int argc, char **argv)
{
	fract	data;
	
	init(&data);
	data.inc = argc;
	if (argc == 1)
		error();
	if (!ft_strncmp("Mandelbrot", argv[1], 10))
	{
		data.which_fract = 1;
		if (argc == 3)
			data.inc -= ((ft_atoi(argv[2]) / 100));
	}
	else if (!ft_strncmp("Julia", argv[1], 5))
	{
		data.which_fract = 2;
		if (argc == 3)
			data.cRe -= ((ft_atoi(argv[2]) / 100));
	}
	else
		error();
	if (argc == 3)
		data.inc = ft_atoi(argv[2]);
	data.MaxRe = 0.5;
	data.MinIm = -1.0;
	data.MinRe = -1.5;
	data.zoom = 1.0f;
	data.zoom = 1;
	data.MamoveX = -0.5;
	data.moveY = 0;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.ImageWidth, data.ImageHeight, "Fract-ol");
	data.img = mlx_new_image(data.mlx_ptr, data.ImageWidth, data.ImageHeight);
	data.addr = mlx_get_data_addr(data.img, &data.bit_x_pixel, &data.line_length, &data.endian);
	mlx_hook(data.win_ptr, 2, 1L << 0, keypress, &data);
	mlx_hook(data.win_ptr, 17, (1L << 16), ftsclose, &data);
	mlx_mouse_hook(data.win_ptr, mouse, &data);
	whichfract(&data);
	mlx_loop(data.mlx_ptr);
}
