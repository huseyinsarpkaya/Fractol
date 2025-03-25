/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:49:25 by husarpka          #+#    #+#             */
/*   Updated: 2025/03/25 16:12:56 by husarpka         ###   ########.fr       */
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

double parse_integer_part(const char **str)
{
    double result;

	result = 0.0;
    while (**str >= '0' && **str <= '9')
    {
        result = result * 10.0 + (**str - '0');
        (*str)++;
    }
    return result;
}

double parse_fractional_part(const char **str)
{
    double fraction;
    double divisor;
    
	fraction = 0.0;
	divisor = 10.0;
    if (**str == '.')
    {
        (*str)++;
        while (**str >= '0' && **str <= '9')
        {
            fraction += (**str - '0') / divisor;
            divisor *= 10.0;
            (*str)++;
        }
    }
    return fraction;
}


double ft_atod(const char *str)
{
    double result;
    double fraction;
    int sign;

	result = 0.0;
	fraction = 0.0;
	sign = 1;
    while (*str == ' ' || *str == '\t')
        str++;
    if (*str == '-' )
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
        str++;
    if (*str == '\0')
        ft_error();
    result = parse_integer_part(&str);
    if (*str == '.' && (*(str + 1) < '0' || *(str + 1) > '9'))
        ft_error();
    fraction = parse_fractional_part(&str);
    if (*str != '\0')
        ft_error();
    return (sign * (result + fraction));
}

