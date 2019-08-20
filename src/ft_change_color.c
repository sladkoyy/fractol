/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:16:17 by dtoy              #+#    #+#             */
/*   Updated: 2019/06/11 18:28:10 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			ft_dark_green(t_params *fractol)
{
	(*fractol).r = 0;
	(*fractol).g = 15;
	(*fractol).b = 0;
}

static void			ft_orange(t_params *fractol)
{
	(*fractol).r = 255;
	(*fractol).g = 25;
	(*fractol).b = 0;
}

static void			ft_more_colors(t_params *fractol)
{
	(*fractol).r = 837204200;
	(*fractol).g = 578134256;
	(*fractol).b = 1486421565;
}

static void			ft_blue(t_params *fractol)
{
	(*fractol).r = 15;
	(*fractol).g = 15;
	(*fractol).b = 255;
}

void				ft_change_color(int x, t_params *fractol)
{
	if (x == 18)
	{
		(*fractol).r = 255;
		(*fractol).g = 255;
		(*fractol).b = 255;
	}
	if (x == 19)
		ft_orange(fractol);
	if (x == 20)
		ft_blue(fractol);
	if (x == 21)
		ft_dark_green(fractol);
	if (x == 23)
		ft_more_colors(fractol);
}
