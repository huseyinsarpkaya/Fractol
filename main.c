/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:26:27 by husarpka          #+#    #+#             */
/*   Updated: 2025/03/18 18:13:11 by husarpka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "stdlib.h"
#include <unistd.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

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
    {
        close_window(param);
    }
    return (0);
}

int color(int iter) {
    int color;
    int red = (iter * 9) % 256;
    int green = (iter * 7) % 256;
    int blue = (iter * 3) % 256;
    color = (red << 16) | (green << 8) | blue;
    return color;
}

void mandelbrot(t_data *data) {
    int x, y;
    double c_re, c_im, z_re, z_im, tmp;
    int iter;

    y = 0;
    while (y < HEIGHT) {
        x = 0;
        while (x < WIDTH) {
            c_re = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            c_im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
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

            x++;
        }
        y++;   
    }                        	
}     

int main(int argc, char **argv) 
{
    (void)argv;

    if (argc == 1) 
    {
        t_data data; 

        data.mlx = mlx_init();
        data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Mandelbrot Fractal");

        data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
        data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_length, &data.endian);

        mandelbrot(&data);

        mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);

        mlx_key_hook(data.win, key_hook, &data);

        mlx_hook(data.win, 17, 0, close_window, &data);

        mlx_loop(data.mlx); 
        return 0;
    }
    else
    {
        write(1, "Hatalı argüman girdiniz\n", 26);
        return (0);
    }
}
