/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:08:14 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/08 00:49:39 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_maker.h"

static int	ft_win(t_data *data)
{
	ft_printf("Congratulations ! You win with %d moves.\n", data->move_nb);
	ft_handle_hook(XK_Escape, data);
	return (OK);
}

static void	ft_put_anim(t_data *data, char *area)
{
	if (*area == PEXIT || *area == PATKEX || *area == EXIT)
		ft_put_exit(data, &(data->skin)->exit);
	else if (*area == PATK || *area == PLAYER || *area == ITEM
		|| *area == MOB || *area == TEMPTY)
		ft_put_img(data, (data->skin)->empty.sp_arr[0], KO);
	if (*area == PEXIT)
		ft_put_ent(data, &(data->skin)->player);
	else if (*area == PATK)
		ft_put_attack_ent(data, &(data->skin)->player, area);
	else if (*area == PATKEX)
		ft_put_attack_ent(data, &(data->skin)->player, area);
	else if (*area == PLAYER)
		ft_put_ent(data, &(data->skin)->player);
	else if (*area == ITEM)
		ft_put_obj(data, &(data->skin)->item);
	else if (*area == MOB)
		ft_put_ent(data, &(data->skin)->mob);
}

static int	ft_render(t_data *data)
{
	int	co[2];
	int	max[2];
	int	ind[2];

	ft_get_map_aff(data, co, max);
	ind[Y] = 0;
	while ((co[Y] + ind[Y]) < max[Y])
	{
		ind[X] = 0;
		while ((co[X] + ind[X]) < max[X])
		{
			data->img_x = ind[X];
			data->img_y = ind[Y];
			ft_put_anim(data, &data->map[co[Y] + ind[Y]][co[X] + ind[X]]);
			if (data->map[co[Y] + ind[Y]][co[X] + ind[X]] == PEXIT
				&& !data->item_nb)
				return (ft_win(data));
			ind[X]++;
		}
		ind[Y]++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
	ft_put_move_count(data);
	return (OK);
}

int	ft_game_loop(t_data *data)
{
	long long	now;
	long long	diff;

	if (!data->win_ptr)
		return (KO);
	now = ft_get_time();
	diff = now - data->time;
	if (diff > 100)
	{
		data->time = now;
		if (!data->win_ptr)
			return (KO);
		ft_render(data);
	}
	return (OK);
}
