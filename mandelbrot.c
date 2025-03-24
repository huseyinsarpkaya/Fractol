/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:40:23 by husarpka          #+#    #+#             */
/*   Updated: 2025/03/24 15:44:05 by husarpka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot_calculate_pixel_color(t_data *data, int x, int y)
{
    double c_re;
    double c_im;
    double z_re;
    double z_im;
    double tmp;
    int iter;

    z_re = 0;
    z_im = 0;
    iter = 0;
    c_re = data->min_re + (x / (double)WIDTH) * (data->max_re - data->min_re);
    c_im = data->min_im + (y / (double)HEIGHT) * (data->max_im - data->min_im);
   
    while (z_re * z_re + z_im * z_im <= 4 && iter < MAX_ITER) 
	{
        tmp = z_re * z_re - z_im * z_im + c_re;
        z_im = 2 * z_re * z_im + c_im;
        z_re = tmp;
        iter++;
    }
    return (color(iter));
}
int mouse_zoom(int button, int x, int y, t_data *data)
{
    double factor;
    double mouse_re;
    double mouse_im;

    mouse_re = data->min_re + (data->max_re - data->min_re) * x / (double)WIDTH;
    mouse_im = data->min_im + (data->max_im - data->min_im) * y / (double)HEIGHT;
    if (button == 4) 
        factor = 0.95; 
    else if (button == 5)  
        factor = 1.1; 
    else
        return (0);
    data->min_re = mouse_re + (data->min_re - mouse_re) * factor;
    data->max_re = mouse_re + (data->max_re - mouse_re) * factor;
    data->min_im = mouse_im + (data->min_im - mouse_im) * factor;
    data->max_im = mouse_im + (data->max_im - mouse_im) * factor;
    mandelbrot(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}

void mandelbrot(t_data *data)
{
    int x;
    int y;
	int color_val;
	int pixel;
    
    x = 0;
    while (x < WIDTH) 
	{
        y = 0;
        while (y < HEIGHT) 
		{
            	color_val = mandelbrot_calculate_pixel_color(data, x, y);
            	pixel = (y * data->line_length + x * (data->bpp / 8));
            *(unsigned int *)(data->addr + pixel) = color_val;
            y++;
        }
        x++;
    }
}
