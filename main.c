/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:26:27 by husarpka          #+#    #+#             */
/*   Updated: 2025/03/24 15:49:01 by husarpka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "stdlib.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>



int main(int argc, char **argv)
{
    t_data data;
	if (argc == 2)
	{
		if (ft_strcmp("Mandelbrot",argv[1]))
        set_mandelbrot(&data);
    }          
    else if(argc == 4)
    {
        if (ft_strcmp("Julia",argv[1]))
        {
            data.re = ft_atod(argv[2]);
            data.im = ft_atod(argv[3]);
            set_julia(&data);
        }
    }
	else
        ft_error();
	return 0;
}
