/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:49:25 by husarpka          #+#    #+#             */
/*   Updated: 2025/03/24 15:50:33 by husarpka         ###   ########.fr       */
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
	return ;
}

double ft_atod(const char *str)
{
    double result = 0.0;
    double fraction = 0.0;
    double divisor = 10.0;
    int sign = 1;

    while (*str == ' ' || *str == '\t')
        str++;
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
        str++;
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10.0 + (*str - '0');
        str++;
    }
    if (*str == '.')
    {
        str++;
        while (*str >= '0' && *str <= '9')
        {
            fraction += (*str - '0') / divisor;
            divisor *= 10.0;
            str++;
        }
    }
    if (*str != '\0')
        ft_error();
    return sign * (result + fraction);
}
