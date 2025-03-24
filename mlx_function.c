/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:33:14 by husarpka          #+#    #+#             */
/*   Updated: 2025/03/24 15:53:34 by husarpka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_mlx_function(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_free_memory(data);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if(!data->img)
		ft_free_memory(data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractal");
	if (!data->win)
		ft_free_memory(data);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length, &data->endian);
	if (!data->addr)
		ft_free_memory(data);	
	return (0);
}
