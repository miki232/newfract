/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:47:09 by mtoia             #+#    #+#             */
/*   Updated: 2022/06/21 19:47:12 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct t_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	char			*addr;
	int				bit_x_pixel;
	int				line_length;
	int				endian;
	unsigned int	x;
	unsigned int	y;
	int				isinside;
	unsigned int	ImageHeight;
	unsigned int	ImageWidth;
	int				which_fract;
	double			MinRe;
	double			MaxRe;
	double			MinIm;
	double			MaxIm;
	double			zoom;
	double			moveX;
	double			MamoveX;
	double			moveY;
	double			inc;
	double			cRe;
	double			cIm;
}	fract;

typedef struct t_mouse
{
	double	x;
	double	y;
	double	prev_x;
	double	prev_y;
	int		left_down;
	int		mid_down;
}	s_mouse;

enum
{
	KB_PAGE_UP = 116,
	KB_PAGE_DOWN = 121,
	ESC = 53,
	PLUS = 69,
	MINUS = 78,
	LEFT = 123,
	RIGHT = 124,
	DOWN = 125,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void	put2screen(fract *data);
void	my_mlx_pixel_put(fract *data, int x, int y, int color);
int		keypress(int key, fract *data);
int		my_fract(fract *data);
int		julia(fract *data);
void	draw(fract data);
void	isnside_check(fract data);
int		ft_atoi(const char *str);
int		ftclose(int keycode, fract *vars);
int		clear(fract *data);
int		mouse_move(int x, int y, s_mouse *mouse);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_printf(const char *str, ...);
// int	mouseclick(int x, int y, s_mouse *mouse);
# endif
