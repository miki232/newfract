/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:47:09 by mtoia             #+#    #+#             */
/*   Updated: 2022/06/25 01:06:25 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
	int	ImageHeight;
	int	ImageWidth;
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
	int				fd;
	float				maxIterations;
}	fract;

typedef struct t_mousse
{
	double	x;
	double	y;
	double	prev_x;
	double	prev_y;
	int		left_down;
	int		mid_down;
}	s_mousse;

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

enum palette
{
	yellow = 0xF7FF00,
	lime = 0xDCFF29,
	orange = 0xFF9300,
	orange1 = 0xFFB858,
	red = 0xFD3512,
	red1 = 0xFF9961,
	green = 0x9CC938,
	green1 = 0x4AE62B,
	cyano = 0x12FDAB,
	cyano1 = 0x00ffff,
	darkblue = 0x03006A,
	blue = 0x1240FD,
	light_blue = 0x5193FF,
	
};

int mouse(int button,int x,int y, fract *param);
int color(int inter, fract *data);
void	put2screen(fract *data);
void	my_mlx_pixel_put(fract *data, int x, int y, int color);
int		keypress(int key, fract *data);
int		my_fract(fract *data);
int		julia(fract *data);
void	draw(fract data);
void	isnside_check(fract data);
double		ft_atoi(const char *str);
int		ftsclose(void *data);
int		clear(fract *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_printf(const char *str, ...);
char	*ft_itoa(int num);
int	zoomout(fract *data);
int	left(fract *data);
int	right(fract *data);
int	zoom(fract *data);
# endif
