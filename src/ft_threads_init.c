/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:59:39 by dtoy              #+#    #+#             */
/*   Updated: 2019/08/13 21:29:46 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_args_init(t_params *fractol, int i)
{
	while (i < THREADS)
	{
		fractol->args[i].data = (*fractol).data;
		fractol->args[i].y = i * WIN_HEIGHT / THREADS;
		fractol->args[i].numt = i + 1;
		fractol->args[i].movey = (*fractol).movey;
		fractol->args[i].movex = (*fractol).movex;
		fractol->args[i].maxre = (*fractol).maxre;
		fractol->args[i].maxim = (*fractol).maxim;
		fractol->args[i].minre = (*fractol).minre;
		fractol->args[i].minim = (*fractol).minim;
		fractol->args[i].cre = (*fractol).cre;
		fractol->args[i].cim = (*fractol).cim;
		fractol->args[i].r = (*fractol).r;
		fractol->args[i].g = (*fractol).g;
		fractol->args[i].b = (*fractol).b;
		fractol->args[i].poww = (*fractol).poww;
		i++;
	}
}

int				ft_threads_init(t_params *fractol)
{
	pthread_t	thread[THREADS];
	int			i;
	int			status;
	int			status_addr;

	i = 0;
	while (i < THREADS)
	{
		ft_args_init(fractol, i);
		if ((status = pthread_create(&thread[i], NULL, (*fractol).fractal,
		(void*)&fractol->args[i])) != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		if ((status = pthread_join(thread[i], (void**)&status_addr)) != 0)
			return (-1);
		i++;
	}
	mlx_put_image_to_window(fractol->mlx_params->mlx_ptr,
	fractol->mlx_params->win_ptr, fractol->mlx_params->img_ptr, 0, 0);
	return (0);
}
