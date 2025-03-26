/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 03:56:46 by husarpka          #+#    #+#             */
/*   Updated: 2025/03/26 03:42:02 by husarpka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

int	close_window(t_data *data)
{
	ft_free_memory(data);
	exit(0);
}

int	key_hook_mandelbrot(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_free_memory(data);
	else if (keycode == 65363)
	{
		data->max_re += 0.05;
		data->min_re += 0.05;
	}
	else if (keycode == 65361)
	{
		data->max_re -= 0.05;
		data->min_re -= 0.05;
	}
	else if (keycode == 65362)
	{
		data->max_im -= 0.05;
		data->min_im -= 0.05;
	}
	else if (keycode == 65364)
	{
		data->max_im += 0.05;
		data->min_im += 0.05;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mandelbrot(data);
	return (0);
}
int	key_hook_julia(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_free_memory(data);
	else if (keycode == 65363)
	{
		data->max_re += 0.05;
		data->min_re += 0.05;
	}
	else if (keycode == 65361)
	{
		data->max_re -= 0.05;
		data->min_re -= 0.05;
	}
	else if (keycode == 65362)
	{
		data->max_im -= 0.05;
		data->min_im -= 0.05;
	}
	else if (keycode == 65364)
	{
		data->max_im += 0.05;
		data->min_im += 0.05;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	julia(data);
	return (0);
}