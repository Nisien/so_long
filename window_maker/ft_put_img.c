/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:07:52 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/05 01:57:11 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_maker.h"

void	ft_put_img(t_data *data, void *img_ptr)
{
	int	x;
	int	y;

	x = IMG_SIZE * data->img_x;
	y = IMG_SIZE * data->img_y;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, x, y);
}

void	ft_put_obj(t_data *data, t_obj *obj)
{
	ft_put_img(data, obj->sp_arr[obj->state]);
	if (obj->state == (obj->sp_nb - 1))
		obj->state = 0;
	else
		obj->state++;
}

void	ft_put_exit(t_data *data)
{
	ft_put_img(data, (data->skin)->exit.sp_arr[0]);
}

void	ft_put_ent(t_data *data, t_ent *ent)
{
	ft_put_obj(data, &ent->right);
}
