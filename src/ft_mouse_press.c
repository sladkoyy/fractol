/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_press.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:07:01 by dtoy              #+#    #+#             */
/*   Updated: 2019/06/13 18:23:11 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		ft_intrpltn(double start, double end, double intrpltn)
{
	return (start + ((end - start) * intrpltn));
}

static void	ft_zoom(t_params *fractol, double mre, double mim, double zoom)
{
	double	intrpltn;

	intrpltn = 1.0 / zoom;
	(*fractol).minre = ft_intrpltn(mre, (*fractol).minre, intrpltn);
	(*fractol).minim = ft_intrpltn(mim, (*fractol).minim, intrpltn);
	(*fractol).maxre = ft_intrpltn(mre, (*fractol).maxre, intrpltn);
	(*fractol).maxim = ft_intrpltn(mim, (*fractol).maxim, intrpltn);
}

int			ft_mouse_press(int button, int x, int y, t_params *fractol)
{
	double	mre;
	double	mim;

	mre = (double)x /
	(WIN_WIDTH / ((*fractol).maxre - (*fractol).minre)) + (*fractol).minre;
	mim = (double)y /
	(WIN_HEIGHT / ((*fractol).maxim - (*fractol).minim)) + (*fractol).minim;
	if (button == 5)
		ft_zoom(fractol, mre, mim, 1.05);
	if (button == 4)
		ft_zoom(fractol, mre, mim, 1 / 1.05);
	if (ft_threads_init(fractol) == -1)
	{
		ft_memdel((void **)&fractol->args);
		mlx_destroy_image(fractol->mlx_params->mlx_ptr,
		fractol->mlx_params->img_ptr);
		ft_memdel((void **)&fractol->mlx_params->mlx_ptr);
		ft_memdel((void **)&fractol->mlx_params->win_ptr);
		ft_memdel((void **)&fractol->mlx_params);
		ft_error("Error.", fractol);
		exit(0);
	}
	return (0);
}
