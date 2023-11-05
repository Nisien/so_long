/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:08:14 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/05 22:22:01 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_maker.h"

static void	ft_put_map(t_data *data, char area)
{
	usleep(2000);
	if (area == WALL)
		ft_put_obj(data, &(data->skin)->wall);
	else if (area == PLAYER)
		ft_put_ent(data, &(data->skin)->player);
	else if (area == ITEM)
	{
		ft_put_img(data, (data->skin)->empty.sp_arr[0]);
		ft_put_obj(data, &(data->skin)->item);
	}
	else if (area == MOB)
		ft_put_ent(data, &(data->skin)->mob);
	else if (area == EXIT)
		ft_put_img(data, (data->skin)->exit.sp_arr[0]);
	else if (area == EMPTY)
		ft_put_img(data, (data->skin)->empty.sp_arr[0]);
	else
		ft_put_img(data, (data->skin)->empty.sp_arr[0]);
}

int	ft_render(t_data *data)
{
	int	i;
	int	j;

	if (!data->win_ptr)
		return (KO);
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			data->img_x = j;
			data->img_y = i;
			ft_put_map(data, data->map[i][j]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
	return (OK);
}
