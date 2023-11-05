/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:07:52 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/05 22:22:32 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_maker.h"

static void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

static void	ft_draw_img(t_img *src, t_img *dst, int x, int y)
{
	char	*px;
	int		y_px;
	int		x_px;

	y_px = 0;
	while (y_px < 100)
	{
		x_px = 0;
		while (x_px < 100)
		{
			px = src->addr + (y_px * src->len + x_px * (src->bpp / 8));
			if (*(unsigned int *)px != 0xFF000000)
				img_pix_put(dst, x_px + x, y_px + y, *(unsigned int *)px);
			x_px++;
		}
		y_px++;
	}
}

void	ft_put_img(t_data *data, void *img_ptr)
{
	t_img	temp;
	int		x;
	int		y;

	x = IMG_SIZE * data->img_x;
	y = IMG_SIZE * data->img_y;
	temp.ptr = img_ptr;
	temp.addr = mlx_get_data_addr(temp.ptr, &temp.bpp, &temp.len, &temp.endian);
	ft_draw_img(&temp, &data->img, x, y);
}

void	ft_put_obj(t_data *data, t_obj *obj)
{
	ft_put_img(data, obj->sp_arr[obj->state]);
	if (obj->state == (obj->sp_nb - 1))
		obj->state = 0;
	else
		obj->state++;
}

void	ft_put_ent(t_data *data, t_ent *ent)
{
	ft_put_img(data, (data->skin)->empty.sp_arr[0]);
	ft_put_obj(data, &ent->right);
}
