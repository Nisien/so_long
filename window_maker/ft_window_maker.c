/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_maker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:49:59 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/08 04:30:38 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_maker.h"

static void	ft_winmaker_error(t_data *data)
{
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	ft_free_skin(data->skin);
	exit(KO);
}

static int	ft_get_item_nb(char **map)
{
	int	i;
	int	j;
	int	nb;

	nb = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ITEM)
				nb++;
			j++;
		}
		i++;
	}
	return (nb);
}

static void	ft_get_window_size(t_data *data)
{
	int	ix;
	int	iy;

	ix = 1;
	iy = 1;
	data->map_y = 0;
	while (data->map[data->map_y])
		data->map_y++;
	data->map_x = ft_strlen(*data->map);
	while (IMG_SIZE * ix < data->win_x && ix <= data->map_x)
		ix++;
	while (IMG_SIZE * iy < data->win_y && iy <= data->map_y)
		iy++;
	data->win_x = IMG_SIZE * (ix - 1);
	data->win_y = IMG_SIZE * (iy - 1);
	data->max_x = ix - 1;
	data->max_y = iy - 1;
}

static void	ft_set_hook(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &ft_game_loop, data);
	mlx_hook(data->win_ptr, ClientMessage, StructureNotifyMask,
		ft_cross_close, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &ft_handle_hook, data);
	mlx_do_key_autorepeatoff(data->mlx_ptr);
}

void	ft_window_maker(t_skin *skin)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	data.map = skin->map_arr;
	data.skin = skin;
	data.item_nb = ft_get_item_nb(data.map);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		ft_winmaker_error(&data);
	mlx_get_screen_size(data.mlx_ptr, &data.win_x, &data.win_y);
	ft_get_window_size(&data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.win_x,
			data.win_y, SL_TITLE);
	if (!data.win_ptr)
		ft_winmaker_error(&data);
	ft_set_img(&data);
	ft_set_map(&data);
	ft_set_hook(&data);
	mlx_loop(data.mlx_ptr);
	ft_unset_img(&data);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
