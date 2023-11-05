/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 01:38:34 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/05 23:06:31 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_maker.h"

static void	ft_unset_obj(t_data *data, t_obj *obj)
{
	int	i;

	i = 0;
	while (i < obj->sp_nb)
	{
		mlx_destroy_image(data->mlx_ptr, obj->sp_arr[i]);
		obj->sp_arr[i] = NULL;
		i++;
	}
}

static void	ft_unset_ent(t_data *data, t_ent *ent)
{
	ft_unset_obj(data, &ent->up);
	ft_unset_obj(data, &ent->down);
	ft_unset_obj(data, &ent->left);
	ft_unset_obj(data, &ent->right);
	ft_unset_obj(data, &ent->mv_up);
	ft_unset_obj(data, &ent->mv_down);
	ft_unset_obj(data, &ent->mv_left);
	ft_unset_obj(data, &ent->mv_right);
}

void	ft_unset_img(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.ptr);
	ft_unset_obj(data, &(data->skin)->empty);
	ft_unset_obj(data, &(data->skin)->wall);
	ft_unset_obj(data, &(data->skin)->exit);
	ft_unset_obj(data, &(data->skin)->item);
	ft_unset_ent(data, &(data->skin)->mob);
	ft_unset_ent(data, &(data->skin)->player);
}
