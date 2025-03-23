/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:26:27 by husarpka          #+#    #+#             */
/*   Updated: 2025/03/23 07:19:03 by husarpka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "stdlib.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>

#define WIDTH 400
#define HEIGHT 400
#define MAX_ITER 300

	



int mouse_zoom(int button, int x, int y, t_data *fract)
{
    double factor;
    double mouse_re;
    double mouse_im;

    mouse_re = fract->min_re + (fract->max_re - fract->min_re) * x / (double)WIDTH;
    mouse_im = fract->min_im + (fract->max_im - fract->min_im) * y / (double)HEIGHT;

    if (button == 4)  // Scroll up
        factor = 0.95; 
    else if (button == 5)  // Scroll down
        factor = 1.1; 
    else
        return (0);

    fract->min_re = mouse_re + (fract->min_re - mouse_re) * factor;
    fract->max_re = mouse_re + (fract->max_re - mouse_re) * factor;
    fract->min_im = mouse_im + (fract->min_im - mouse_im) * factor;
    fract->max_im = mouse_im + (fract->max_im - mouse_im) * factor;

    mandelbrot(fract);
    mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
    return (0);
}


// ... Diğer fonksiyonlar aynı kalabilir ...


int close_window(void *param)
{
	t_data *data = (t_data *)param;

	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int key_hook(int keycode, void *param)
{
	if (keycode == 65307)
		close_window(param);
	return (0);
}

int color(int iter) {
	int red = (iter * 9) % 256;
	int green = (iter * 7) % 256;
	int blue = (iter * 3) % 256;
	return (red << 16) | (green << 8) | blue;
}

void mandelbrot(t_data *data) {
	int x, y;
	double c_re, c_im, z_re, z_im, tmp;
	int iter;

	for (y = 0; y < HEIGHT; y++) {
		for (x = 0; x < WIDTH; x++) {
			c_re = data->min_re + (x / (double)WIDTH) * (data->max_re - data->min_re);
			c_im = data->min_im + (y / (double)HEIGHT) * (data->max_im - data->min_im);
			z_re = 0;
			z_im = 0;
			iter = 0;

			while (z_re * z_re + z_im * z_im <= 4 && iter < MAX_ITER) {
				tmp = z_re * z_re - z_im * z_im + c_re;
				z_im = 2 * z_re * z_im + c_im;
				z_re = tmp;
				iter++;
			}

			int color_val = color(iter);
			int pixel = (y * data->line_length + x * (data->bpp / 8));
			*(unsigned int *)(data->addr + pixel) = color_val;
		}
	}
}

int main(int argc, char **argv) 
{
	(void)argv;
	if (argc != 1) {
		write(1, "Hatalı argüman girdiniz\n", 26);
		return (0);
	}

	t_data data;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Mandelbrot Fractal");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_length, &data.endian);
	data.min_re = -2.0;
	data.max_re = 2.0;
	data.min_im = -2.0;
	data.max_im = 2.0;
	data.zoom = 1.0;
	
	
	mlx_mouse_hook(data.win, mouse_zoom, &data);
	mandelbrot(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 2, 0, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	
	return 0;
}
