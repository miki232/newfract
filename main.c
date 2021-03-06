/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:38:28 by mtoia             #+#    #+#             */
/*   Updated: 2022/06/27 09:48:36 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	error(void)
{
	ft_printf("\nPlease, insert whic fractal:\n");
	ft_printf("\n--Mandelbrot *Param*\n");
	ft_printf("--Julia *Param*\n");
	ft_printf("\n[Only One Parameters can be accepted]\n");
	ft_printf("\nUse WASD or Arrow Keys, for moving the fractal\n");
	ft_printf("Use '+' for zoom\n '-' for zoom-out\n");
	ft_printf("\nExample: ./fractol Mandelbrot 3\n");
	exit(0);
}

void	whichfract(t_fract *d)
{
	if (d->which_fract == 1)
		my_fract(d);
	else if (d->which_fract == 2)
		julia(d);
}

void	init(t_fract *d)
{
	d->ih = 750;
	d->iw = 750;
	d->movex = 0;
	d->mvy = 0;
	d->maxiterations = 20;
	d->incx = 0;
	d->incy = 0;
	d->cim = 0.27015;
	d->zo = 1.0f;
	d->zo = 1;
	d->mmx = -0.5;
	d->mvy = 0;
	d->mlx_ptr = mlx_init();
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->iw, d->ih, "Fract-ol");
	d->img = mlx_new_image(d->mlx_ptr, d->iw, d->ih);
	d->addr = mlx_get_data_addr(d->img, &d->btxp, &d->line_length, &d->endian);
}

void	input(t_fract *d, t_args *arg)
{
	if (arg->argc == 1 || arg->argc == 4)
		error();
	if (!ft_strncmp("Mandelbrot", arg->argv[1], 11))
	{
		d->which_fract = 1;
		d->inc = 2;
		if (arg->argc == 3)
			d->inc -= ((doubleatoi(arg->argv[2]) / 10));
	}
	else if (!ft_strncmp("Julia", arg->argv[1], 5))
	{
		d->which_fract = 2;
		d->cre = -0.7;
		if (arg->argc == 3)
			d->cre -= ((doubleatoi(arg->argv[2]) / 100));
	}
	else
		error();
}	

int	main(int argc, char **argv)
{
	t_fract	d;
	t_args	arg;

	arg.argc = argc;
	arg.argv = argv;
	input(&d, &arg);
	init(&d);
	mlx_hook(d.win_ptr, 2, 1L << 0, keypress, &d);
	mlx_hook(d.win_ptr, 17, (1L << 16), ftsclose, &d);
	mlx_mouse_hook(d.win_ptr, mouse, &d);
	whichfract(&d);
	mlx_loop(d.mlx_ptr);
}
