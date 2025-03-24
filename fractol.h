/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:27:09 by husarpka          #+#    #+#             */
/*   Updated: 2025/03/24 16:55:46 by husarpka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "minilibx-linux/mlx.h"

#define WIDTH 400
#define HEIGHT 400
#define MAX_ITER 300

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double re;
	double im;
	
}	t_data;
int julia_calculate_pixel_color(t_data *data, int x, int y);
double ft_atod(const char *str);
int set_julia(t_data *data);
void julia(t_data *data);
int julia_mouse_zoom(int button, int x, int y, t_data *data);
int mandelbrot_calculate_pixel_color(t_data *data, int x, int y);
int set_mandelbrot(t_data *data);
int ft_error(void);
int calculate_pixel_color(t_data *data, int x, int y);
int ft_mlx_function(t_data *data);
void ft_value(t_data *data);
int ft_strcmp(char *s1, char *s2);
int mouse_zoom(int button, int x, int y, t_data *data);
int key_hook(int keycode, t_data *data);
int close_window(t_data *data);
int color(int iter);
void mandelbrot(t_data *data) ;
int ft_free_memory(t_data *data);
#endif 

