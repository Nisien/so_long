/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:07:52 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/07 03:11:42 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_maker.h"

void	ft_put_img(t_data *data, void *img_ptr, int option)
{
	t_img	temp;
	int		x;
	int		y;

	x = IMG_SIZE * data->img_x;
	y = IMG_SIZE * data->img_y;
	temp.ptr = img_ptr;
	temp.addr = mlx_get_data_addr(temp.ptr, &temp.bpp, &temp.len, &temp.endian);
	if (!option)
		ft_draw_with_black(&temp, &data->img, x, y);
	else
		ft_draw_img(&temp, &data->img, x, y);
}

void	ft_put_exit(t_data *data, t_obj *obj)
{
	ft_put_img(data, obj->sp_arr[obj->state], OK);
	if (!data->item_nb && obj->state < (obj->sp_nb - 1))
		obj->state++;
}

void	ft_put_obj(t_data *data, t_obj *obj)
{
	ft_put_img(data, obj->sp_arr[obj->state], OK);
	if (obj->state == (obj->sp_nb - 1))
		obj->state = 0;
	else
		obj->state++;
}

void	ft_put_ent(t_data *data, t_ent *ent)
{
	if (ent->dir == RIGHT)
		ft_put_obj(data, &ent->right);
	else if (ent->dir == LEFT)
		ft_put_obj(data, &ent->left);
	else if (ent->dir == UP)
		ft_put_obj(data, &ent->up);
	else if (ent->dir == DOWN)
		ft_put_obj(data, &ent->down);
}
