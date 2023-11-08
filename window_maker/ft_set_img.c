/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 01:54:10 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/07 08:16:40 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_maker.h"

static void	*ft_string_to_img(t_data *data, char *sp)
{
	void	*temp;
	int		size;

	size = IMG_SIZE;
	temp = mlx_xpm_file_to_image(data->mlx_ptr, sp, &size, &size);
	free(sp);
	return (temp);
}

static void	ft_obj_to_img(t_data *data, t_obj *obj)
{
	int	i;

	i = 0;
	while (i < obj->sp_nb)
	{
		obj->sp_arr[i] = ft_string_to_img(data, obj->sp_arr[i]);
		i++;
	}
}

static void	ft_ent_to_img(t_data *data, t_ent *ent)
{
	ft_obj_to_img(data, &ent->up);
	ft_obj_to_img(data, &ent->down);
	ft_obj_to_img(data, &ent->left);
	ft_obj_to_img(data, &ent->right);
	ft_obj_to_img(data, &ent->mv_up);
	ft_obj_to_img(data, &ent->mv_down);
	ft_obj_to_img(data, &ent->mv_left);
	ft_obj_to_img(data, &ent->mv_right);
	ft_obj_to_img(data, &ent->atk_up);
	ft_obj_to_img(data, &ent->atk_down);
	ft_obj_to_img(data, &ent->atk_left);
	ft_obj_to_img(data, &ent->atk_right);
}

void	ft_set_img(t_data *data)
{
	data->img.ptr = mlx_new_image(data->mlx_ptr, data->win_x, data->win_y);
	data->img.addr = mlx_get_data_addr(data->img.ptr, &data->img.bpp,
			&data->img.len, &data->img.endian);
	ft_obj_to_img(data, &(data->skin)->empty);
	ft_obj_to_img(data, &(data->skin)->wall);
	ft_obj_to_img(data, &(data->skin)->exit);
	ft_obj_to_img(data, &(data->skin)->item);
	ft_ent_to_img(data, &(data->skin)->mob);
	ft_ent_to_img(data, &(data->skin)->player);
}
