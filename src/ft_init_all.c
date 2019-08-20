/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:57:59 by dtoy              #+#    #+#             */
/*   Updated: 2019/08/13 21:29:41 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_fractol_init(t_params *fractol)
{
	(*fractol).r = 255;
	(*fractol).g = 255;
	(*fractol).b = 255;
	(*fractol).poww = -2;
	(*fractol).maxre = 4;
	(*fractol).maxim = 2;
	(*fractol).minre = -4;
	(*fractol).minim = -2;
	(*fractol).cre = -0.7;
	(*fractol).cim = 0.27015;
}

static int		ft_mlx_init(t_params *fractol)
{
	int		bpp;
	int		s_l;
	int		end;

	if (!(fractol->mlx_params =
	(t_mlx_params*)ft_memalloc(sizeof(t_mlx_params))))
		return (-1);
	if (!(fractol->mlx_params->mlx_ptr = mlx_init()))
		return (-1);
	if (!(fractol->mlx_params->win_ptr =
	mlx_new_window(fractol->mlx_params->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "F")))
		return (-1);
	if (!(fractol->mlx_params->img_ptr =
	mlx_new_image(fractol->mlx_params->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		return (-1);
	if (!((*fractol).data =
	mlx_get_data_addr(fractol->mlx_params->img_ptr, &bpp, &s_l, &end)))
		return (-1);
	return (1);
}

int				ft_key_release(int x, t_params *fractol)
{
	if (x == 257)
	{
		(*fractol).shift = 0;
		ft_key_press(-1, fractol);
	}
	return (0);
}

int				ft_init_all(t_params *fractol)
{
	if (!(fractol->args = (t_args*)ft_memalloc(sizeof(t_args) * THREADS)))
		return (-1);
	if (!(ft_mlx_init(fractol)))
	{
		ft_memdel((void **)&(*fractol).args);
		ft_memdel((void **)&fractol->mlx_params);
		return (-1);
	}
	ft_fractol_init(fractol);
	if (ft_threads_init(fractol) == -1)
	{
		ft_memdel((void **)&fractol->args);
		mlx_destroy_image(fractol->mlx_params->mlx_ptr,
		fractol->mlx_params->img_ptr);
		ft_memdel((void **)&fractol->mlx_params->mlx_ptr);
		ft_memdel((void **)&fractol->mlx_params->win_ptr);
		ft_memdel((void **)&fractol->mlx_params);
		return (-1);
	}
	mlx_hook(fractol->mlx_params->win_ptr, 2, 0, &ft_key_press, fractol);
	mlx_hook(fractol->mlx_params->win_ptr, 3, 0, &ft_key_release, fractol);
	mlx_hook(fractol->mlx_params->win_ptr, 4, 0, &ft_mouse_press, fractol);
	mlx_hook(fractol->mlx_params->win_ptr, 6, 0, &ft_mouse_move, fractol);
	mlx_loop(fractol->mlx_params->mlx_ptr);
	return (0);
}
