/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:11:22 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/08 04:33:22 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_maker.h"

static void	ft_set_background(t_data *data, char area)
{
	if (area == WALL)
		ft_put_img(data, (data->skin)->wall.sp_arr[0], KO);
	else if (area == PLAYER)
		ft_put_img(data, (data->skin)->empty.sp_arr[0], OK);
	else if (area == ITEM)
		ft_put_img(data, (data->skin)->empty.sp_arr[0], OK);
	else if (area == MOB)
		ft_put_img(data, (data->skin)->empty.sp_arr[0], OK);
	else if (area == EXIT)
		ft_put_exit(data, &(data->skin)->exit);
	else if (area == EMPTY)
		ft_put_img(data, (data->skin)->empty.sp_arr[0], KO);
	else
		ft_put_img(data, (data->skin)->empty.sp_arr[0], KO);
}

int	ft_set_map(t_data *data)
{
	int	co[2];
	int	max[2];
	int	ind[2];

	if (!data->img.ptr)
		return (KO);
	ft_get_map_aff(data, co, max);
	data->last_x = co[X];
	data->last_y = co[Y];
	data->last_max_x = max[X];
	data->last_max_y = max[Y];
	ind[Y] = 0;
	while ((co[Y] + ind[Y]) < max[Y])
	{
		ind[X] = 0;
		while ((co[X] + ind[X]) < max[X])
		{
			data->img_x = ind[X];
			data->img_y = ind[Y];
			ft_set_background(data, data->map[co[Y] + ind[Y]][co[X] + ind[X]]);
			ind[X]++;
		}
		ind[Y]++;
	}
	return (OK);
}
