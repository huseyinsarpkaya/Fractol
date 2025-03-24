/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:10:14 by husarpka          #+#    #+#             */
/*   Updated: 2025/03/24 02:20:18 by husarpka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
int ft_free_memory(t_data *data)
{
    if (data->win)
    {
        mlx_destroy_window(data->mlx, data->win);
        data->win = NULL;
    }
    if (data->img)
    {
        mlx_destroy_image(data->mlx, data->img);
        data->img = NULL;
    }

    if (data->mlx)
    {
        mlx_destroy_display(data->mlx);
        free(data->mlx);
        data->mlx = NULL;
    }
	exit(0);
}
