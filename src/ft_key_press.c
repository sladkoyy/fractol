/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:05:41 by dtoy              #+#    #+#             */
/*   Updated: 2019/08/13 21:23:46 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_change_fractol(t_params *fractol)
{
	if ((*fractol).type == 1)
		(*fractol).fractal = ft_draw_mandelbrot;
	if ((*fractol).type == 2)
		(*fractol).fractal = ft_draw_julia;
	if ((*fractol).type == 3)
		(*fractol).fractal = ft_draw_burningship;
	if ((*fractol).type == 4)
		(*fractol).fractal = ft_draw_tricorn;
	return (0);
}

static void		ft_move(int x, t_params *fractol)
{
	if (x == 124)
		(*fractol).movex -= (0.05 * fabs((*fractol).maxre - (*fractol).minre));
	if (x == 123)
		(*fractol).movex += (0.05 * fabs((*fractol).maxre - (*fractol).minre));
	if (x == 126)
		(*fractol).movey += (0.05 * fabs((*fractol).maxim - (*fractol).minim));
	if (x == 125)
		(*fractol).movey -= (0.05 * fabs((*fractol).maxim - (*fractol).minim));
}

static void		ft_next_fractol(int x, t_params *fractol)
{
	if (x == 48)
	{
		(*fractol).type += 1;
		if ((*fractol).type == 5)
			(*fractol).type = 1;
		(*fractol).maxre = 4;
		(*fractol).maxim = 2;
		(*fractol).minre = -4;
		(*fractol).minim = -2;
	}
	ft_change_fractol(fractol);
}

void			ft_free_mlx(char *str, t_params *fractol)
{
	ft_memdel((void **)&fractol->args);
	mlx_destroy_image(fractol->mlx_params->mlx_ptr,
	fractol->mlx_params->img_ptr);
	ft_memdel((void **)&fractol->mlx_params->mlx_ptr);
	ft_memdel((void **)&fractol->mlx_params->win_ptr);
	ft_memdel((void **)&fractol->mlx_params);
	ft_error(str, fractol);
	exit(0);
}

int				ft_key_press(int x, t_params *fractol)
{
	if (x == 257)
		(*fractol).shift = 1;
	if (x == -1)
		(*fractol).shift = 0;
	ft_move(x, fractol);
	ft_change_color(x, fractol);
	ft_next_fractol(x, fractol);
	if (x == 53)
		ft_free_mlx("Exit.", fractol);
	if (ft_threads_init(fractol) == -1)
		ft_free_mlx("Error.", fractol);
	return (0);
}
