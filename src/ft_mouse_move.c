/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:35:32 by dtoy              #+#    #+#             */
/*   Updated: 2019/08/13 21:34:50 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_mouse_move(int x, int y, t_params *fractol)
{
	double mre;
	double mim;

	if (((*fractol).type == 2 || (*fractol).type == 4) && (*fractol).shift == 1)
	{
		mre = (double)x / (WIN_WIDTH /
		((*fractol).maxre - (*fractol).minre)) + (*fractol).minre;
		mim = (double)y / (WIN_HEIGHT /
		((*fractol).maxim - (*fractol).minim)) + (*fractol).minim;
		(*fractol).cre = mre;
		(*fractol).cim = mim;
		(*fractol).poww = -mre;
		if (ft_threads_init(fractol) == -1)
		{
			free(fractol->args);
			mlx_destroy_image(fractol->mlx_params->mlx_ptr,
			fractol->mlx_params->img_ptr);
			ft_memdel((void **)&fractol->mlx_params->mlx_ptr);
			ft_memdel((void **)&fractol->mlx_params->win_ptr);
			ft_memdel((void **)&fractol->mlx_params);
			exit(0);
		}
	}
	return (0);
}
