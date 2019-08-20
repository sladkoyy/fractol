/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:03:57 by dtoy              #+#    #+#             */
/*   Updated: 2019/06/11 18:26:33 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_put_color(t_args *args, int x, int y, int i)
{
	if (i == MAX_ITERATIONS)
	{
		(*args).data[y * 4 * WIN_WIDTH + x * 4 + 0] = 0;
		(*args).data[y * 4 * WIN_WIDTH + x * 4 + 1] = 0;
		(*args).data[y * 4 * WIN_WIDTH + x * 4 + 2] = 0;
		(*args).data[y * 4 * WIN_WIDTH + x * 4 + 3] = 0;
	}
	else
	{
		(*args).data[y * 4 * WIN_WIDTH + x * 4 + 0] = i * (*args).b;
		(*args).data[y * 4 * WIN_WIDTH + x * 4 + 1] = i * (*args).g;
		(*args).data[y * 4 * WIN_WIDTH + x * 4 + 2] = i * (*args).r;
		(*args).data[y * 4 * WIN_WIDTH + x * 4 + 3] = i * 0;
	}
	return (0);
}
