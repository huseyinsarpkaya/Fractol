/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:55:50 by husarpka          #+#    #+#             */
/*   Updated: 2025/03/24 15:33:17 by husarpka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int set_mandelbrot(t_data *data)
{
    ft_mlx_function(data);
    ft_value(data);
	mandelbrot(data);
	mlx_mouse_hook(data->win, mouse_zoom, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
    return (0);
}

int set_julia(t_data *data)
{
    ft_mlx_function(data);
    ft_value(data);
	julia(data);
	mlx_mouse_hook(data->win, julia_mouse_zoom, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
    return (0);
}