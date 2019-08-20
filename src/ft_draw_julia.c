/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:01:52 by dtoy              #+#    #+#             */
/*   Updated: 2019/06/11 17:46:46 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_calculate_julia(t_args *args, int x, int y)
{
	int		i;
	double	tx;
	double	ty;

	i = 0;
	while (i < MAX_ITERATIONS)
	{
		tx = (*args).pr;
		ty = (*args).pi;
		(*args).pr = tx * tx - ty * ty + (*args).cre;
		(*args).pi = 2 * tx * ty + (*args).cim;
		if (((*args).pr * (*args).pr + (*args).pi * (*args).pi) > 4)
			break ;
		i++;
	}
	ft_put_color(args, x, y, i);
}

void			*ft_draw_julia(void *list)
{
	int		x;
	int		y;
	t_args	*args;
	double	dre;
	double	dim;

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
			ft_calculate_julia(args, x, y);
			x++;
		}
		y++;
	}
	pthread_exit(0);
}
