/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:40:24 by dtoy              #+#    #+#             */
/*   Updated: 2019/08/13 21:29:19 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_HEIGHT 720
# define WIN_WIDTH 1280
# define THREADS 60
# define MAX_ITERATIONS 150
# include <stdlib.h>
# include <pthread.h>
# include <math.h>
# include <stdio.h>
# include <mlx.h>
# include "../libft/includes/libft.h"

typedef struct		s_args
{
	char			*data;
	float			poww;
	int				y;
	int				numt;
	int				r;
	int				g;
	int				b;
	double			movex;
	double			movey;
	double			maxre;
	double			maxim;
	double			minre;
	double			minim;
	double			pr;
	double			pi;
	double			z_r;
	double			z_i;
	double			cre;
	double			cim;
}					t_args;

typedef struct		s_mlx_params
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*data;
}					t_mlx_params;

typedef struct		s_params
{
	t_mlx_params	*mlx_params;
	t_args			*args;
	int				shift;
	int				r;
	int				g;
	int				b;
	void			*(*fractal) (void*);
	float			poww;
	int				type;
	double			power;
	char			*data;
	double			movex;
	double			movey;
	double			cre;
	double			cim;
	double			maxre;
	double			maxim;
	double			minre;
	double			minim;
}					t_params;

void				ft_error(char *str, void *data);
void				ft_change_color(int x, t_params *fractol);
double				ft_interpolation(double start, double end, double intrpltn);
int					ft_put_color(t_args *args, int x, int y, int i);
void				*ft_draw_mandelbrot(void *list);
void				*ft_draw_julia(void *list);
void				*ft_draw_burningship(void *list);
void				*ft_draw_tricorn(void *list);
int					ft_threads_init(t_params *fractol);
int					ft_init_all(t_params *fractol);
int					ft_mouse_move(int x, int y, t_params *fractol);
int					ft_threads_init(t_params *fractol);
int					ft_mouse_press(int button, int x, int y, t_params *fractol);
int					ft_key_press(int x, t_params *fractol);

#endif
