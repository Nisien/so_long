/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:10:09 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/07 08:06:48 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_maker.h"

int	ft_handle_esc(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (OK);
}

int	ft_cross_close(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	return (OK);
}

int	ft_handle_hook(int keysym, t_data *data)
{
	if (keysym == W_KEY || keysym == K_UP)
	{
		data->skin->player.dir = UP;
		ft_move_column(data, -1);
	}
	else if (keysym == A_KEY || keysym == K_LEFT)
	{
		data->skin->player.dir = LEFT;
		ft_move_row(data, -1);
	}
	else if (keysym == S_KEY || keysym == K_DOWN)
	{
		data->skin->player.dir = DOWN;
		ft_move_column(data, 1);
	}
	else if (keysym == D_KEY || keysym == K_RIGHT)
	{
		data->skin->player.dir = RIGHT;
		ft_move_row(data, 1);
	}
	else if (keysym == Q_KEY || keysym == K_SPACE)
		ft_attack(data);
	else
		ft_handle_esc(keysym, data);
	return (OK);
}
