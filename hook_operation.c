/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 03:56:46 by husarpka          #+#    #+#             */
/*   Updated: 2025/03/24 13:57:14 by husarpka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

int close_window(t_data *data)
{
	ft_free_memory(data);
	exit(0);
}

int key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		ft_free_memory(data);
		exit (0);
	}
	return (0);
}
