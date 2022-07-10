/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:47:09 by mtoia             #+#    #+#             */
/*   Updated: 2022/06/27 09:42:07 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct t_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	char			*addr;
	int				btxp;
	int				line_length;
	int				endian;
	int				x;
	int				y;
	int				i;
	int				ih;
	int				iw;
	int				which_fract;
	double			zo;
	double			movex;
	double			mmx;
	double			mvy;
	double			inc;
	double			cre;
	double			cim;
	int				fd;
	double			pr;
	double			pi;
	double			newre;
	double			newim;
	double			ore;
	double			incx;
	double			pow;
	double			incy;
	double			oim;
	float			maxiterations;
}	t_fract;

typedef struct t_arg
{
	int		argc;
	char	**argv;
}	t_args;

typedef enum e_keys
{
	KB_PAGE_UP = 116,
	KB_PAGE_DOWN = 121,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	ESC = 53,
	PLUS = 69,
	MINUS = 78,
	RIGHT = 123,
	LEFT = 124,
	UP = 125,
	DOWN = 126,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}	t_keys;

typedef enum palette
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
}	t_palette;

int		mouse(int button, int x, int y, t_fract *param);
int		color(int inter, t_fract *data);
void	put2screen(t_fract *data);
void	my_mlx_pixel_put(t_fract *data, int x, int y, int color);
int		keypress(int key, t_fract *data);
int		my_fract(t_fract *data);
int		julia(t_fract *data);
void	draw(t_fract data);
void	isnside_check(t_fract data);
double	doubleatoi(const char *str);
int		ftsclose(void *data);
int		clear(t_fract *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_printf(const char *str, ...);
char	*ft_itoa(int num);
int		zoomout(t_fract *data);
int		left(t_fract *data);
int		right(t_fract *data);
void	up(t_fract *data);
void	down(t_fract *data);
void	inv_up(t_fract *data);
int		zoom(t_fract *data);
int fibonacci(t_fract *d);

#endif
