/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:49:25 by husarpka          #+#    #+#             */
/*   Updated: 2025/03/24 03:50:50 by husarpka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
    while (*s1 || *s2)
    {
        if (*s1 != *s2)
            return (0); 
        s1++;
        s2++;
    }
    return (1);
}
void ft_value(t_data *data)
{
	data->min_re = -2.0;
	data->max_re = 2.0;
	data->min_im = -2.0;
	data->max_im = 2.0;
	//data->zoom = 1.0;
	return ;
}