/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_burningship.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:01:17 by dtoy              #+#    #+#             */
/*   Updated: 2019/06/11 17:47:00 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_calculate_burningship(t_args *args, int x, int y)
{
	int		i;
	double	tx;
	double	ty;
	double	zr_sqr;
	double	zi_sqr;

	zr_sqr = (*args).z_r * (*args).z_r;
	zi_sqr = (*args).z_i * (*args).z_i;
	i = 0;
	while (i < MAX_ITERATIONS && (zr_sqr + zi_sqr) <= 4)
	{
		tx = (*args).z_r;
		ty = (*args).z_i;
		(*args).z_r = tx * tx - ty * ty + (*args).pr;
		(*args).z_i = 2 * fabs(tx * ty) + (*args).pi;
		zr_sqr = (*args).z_r * (*args).z_r;
		zi_sqr = (*args).z_i * (*args).z_i;
		i++;
	}
	ft_put_color(args, x, y, i);
	return (0);
}

void		*ft_draw_burningship(void *list)
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
			(*args).z_r = 0;
			(*args).z_i = 0;
			(*args).pr = x / dre + (*args).minre + (*args).movex;
			(*args).pi = y / dim + (*args).minim + (*args).movey;
			ft_calculate_burningship(args, x, y);
			x++;
		}
		y++;
	}
	pthread_exit(0);
}
