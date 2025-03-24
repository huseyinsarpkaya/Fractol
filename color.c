/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 04:00:42 by husarpka          #+#    #+#             */
/*   Updated: 2025/03/24 04:03:45 by husarpka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int color(int iter) 
{
	int red = (iter * 9) % 256;
	int green = (iter * 7) % 256;
	int blue = (iter * 14) % 256;
	return (red << 16) | (green << 8) | blue;
}


int calculate_pixel_color(t_data *data, int x, int y) 
{
    double c_re, c_im, z_re, z_im, tmp;
    int iter;

    c_re = data->min_re + (x / (double)WIDTH) * (data->max_re - data->min_re);
    c_im = data->min_im + (y / (double)HEIGHT) * (data->max_im - data->min_im);
    z_re = 0;
    z_im = 0;
    iter = 0;

    while (z_re * z_re + z_im * z_im <= 4 && iter < MAX_ITER) 
	{
        tmp = z_re * z_re - z_im * z_im + c_re;
        z_im = 2 * z_re * z_im + c_im;
        z_re = tmp;
        iter++;
    }

    return color(iter);
}
