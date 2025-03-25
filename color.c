/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 04:00:42 by husarpka          #+#    #+#             */
/*   Updated: 2025/03/25 16:16:02 by husarpka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color(int iter)
{
	int	red;
	int	green;
	int	blue;

	red = (iter * 9) % 256;
	green = (iter * 7) % 256;
	blue = (iter * 14) % 256;
	return ((red << 16) | (green << 8) | blue);
}
