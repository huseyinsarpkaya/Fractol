/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:26:27 by husarpka          #+#    #+#             */
/*   Updated: 2025/03/24 04:45:38 by husarpka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "stdlib.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>

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
    int x, y;
	int color_val;
	int pixel;
    x = 0;
    while (x < WIDTH) 
	{
        y = 0;
        while (y < HEIGHT) 
		{
            	color_val = calculate_pixel_color(data, x, y);
            	pixel = (y * data->line_length + x * (data->bpp / 8));
				//line_length = 1600 -----  bpp = 32
            *(unsigned int *)(data->addr + pixel) = color_val;

            y++;
        }
        x++;
    }
}


int main(int argc, char **argv) 
{
	if (argc == 2)
	{
		if (!ft_strcmp("Mandelbrot",argv[1]))
			return(0);
	t_data data;
	ft_value(&data);
	ft_mlx_function(&data);
	mlx_mouse_hook(data.win, mouse_zoom, &data);
	mandelbrot(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	//ft_free_memory(&data);
	}
	else
	
	return 0;
}
