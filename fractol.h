/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:27:09 by husarpka          #+#    #+#             */
/*   Updated: 2025/03/23 07:05:27 by husarpka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "minilibx-linux/mlx.h"

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
	double	zoom;
}	t_data;

int mouse_zoom(int button, int x, int y, t_data *data);
int key_hook(int keycode, void *param);
int close_window(void *param);
int color(int iter);
void mandelbrot(t_data *data) ;
#endif 

