/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:02:39 by dtoy              #+#    #+#             */
/*   Updated: 2019/08/13 21:15:25 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_calculate_mandelbrot(t_args *args, int x, int y)
{
	int		i;
	double	zr_sqr;
	double	zi_sqr;

	(*args).z_r = 0;
	(*args).z_i = 0;
	zi_sqr = (*args).z_i * (*args).z_i;
	zr_sqr = (*args).z_r * (*args).z_r;
	i = 0;
	while (zr_sqr + zi_sqr <= 4 && i < MAX_ITERATIONS)
	{
		(*args).z_i = (*args).z_r * (*args).z_i;
		(*args).z_i += (*args).z_i;
		(*args).z_i += (*args).pi;
		(*args).z_r = zr_sqr - zi_sqr + (*args).pr;
		zr_sqr = (*args).z_r * (*args).z_r;
		zi_sqr = (*args).z_i * (*args).z_i;
		i++;
	}
	ft_put_color(args, x, y, i);
	return (0);
}

void			*ft_draw_mandelbrot(void *list)
{
	int		x;
	int		y;
	double	dre;
	double	dim;
	t_args	*args;

	args = (t_args*)list;
	dre = (WIN_WIDTH / ((*args).maxre - (*args).minre));
	dim = (WIN_HEIGHT / ((*args).maxim - (*args).minim));
	y = (*args).y;
	while (y < WIN_HEIGHT / THREADS * (*args).numt)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			(*args).pr = x / dre + (*args).minre + (*args).movex;
			(*args).pi = y / dim + (*args).minim + (*args).movey;
			ft_calculate_mandelbrot(args, x, y);
			x++;
		}
		y++;
	}
	pthread_exit(0);
}
