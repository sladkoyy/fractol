/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:34:38 by dtoy              #+#    #+#             */
/*   Updated: 2019/08/14 16:29:46 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_change_fractol(t_params *fractol, char **av)
{
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
	{
		(*fractol).fractal = ft_draw_mandelbrot;
		(*fractol).type = 1;
	}
	else if (ft_strcmp(av[1], "Julia") == 0)
	{
		(*fractol).fractal = ft_draw_julia;
		(*fractol).type = 2;
	}
	else if (ft_strcmp(av[1], "Burning ship") == 0)
	{
		(*fractol).fractal = ft_draw_burningship;
		(*fractol).type = 3;
	}
	else if (ft_strcmp(av[1], "Tricorn") == 0)
	{
		(*fractol).fractal = ft_draw_tricorn;
		(*fractol).type = 4;
	}
	else
		ft_error("Fractal is missing.", fractol);
	return (0);
}

static int	ft_validation(int ac, char **av, t_params *fractol)
{
	if (ac < 2)
		ft_error("Mandelbrot, Julia, Burning ship, Tricorn", fractol);
	if (ac > 2)
		ft_error("Multiple windows not supported.", fractol);
	ft_change_fractol(fractol, av);
	return (0);
}

int			main(int ac, char **av)
{
	t_params *fractol;

	if (!(fractol = (t_params*)ft_memalloc(sizeof(t_params))))
		return (0);
	ft_validation(ac, av, fractol);
	if (ft_init_all(fractol) == -1)
		ft_error("Error.", fractol);
	return (0);
}
