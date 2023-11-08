/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_winmaker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:55:13 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/08 05:39:53 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_maker.h"

static void	ft_get_map_y(t_data *data, int *co, int *max, int *pp)
{
	if (data->map_y <= data->max_y)
	{
		co[Y] = 0;
		max[Y] = data->max_y;
	}
	else
	{
		if (pp[Y] < data->max_y - 1)
			co[Y] = 0;
		else
			co[Y] = pp[Y] - 1;
		max[Y] = data->max_y + co[Y];
		if (max[Y] > data->map_y)
		{
			max[Y] = data->map_y;
			co[Y] = max[Y] - data->max_y;
		}
	}
}

static void	ft_get_map_x(t_data *data, int *co, int *max, int *pp)
{
	if (data->map_x <= data->max_x)
	{
		co[X] = 0;
		max[X] = data->max_x;
	}
	else
	{
		if (pp[X] < data->max_x - 1)
			co[X] = 0;
		else
			co[X] = pp[X] - 1;
		max[X] = data->max_x + co[X];
		if (max[X] > data->map_x)
		{
			max[X] = data->map_x;
			co[X] = max[X] - data->max_x;
		}
	}
}

void	ft_get_map_aff(t_data *data, int *co, int *max)
{
	int	pp[2];

	ft_find_player_pos(data->map, &pp[X], &pp[Y]);
	ft_get_map_x(data, co, max, pp);
	ft_get_map_y(data, co, max, pp);
	if (data->last_x != co[X] || data->last_y != co[Y])
	{
		data->last_x = co[X];
		data->last_y = co[Y];
		ft_set_map(data);
	}
}

void	ft_put_move_count(t_data *data)
{
	char	*temp;
	char	*nb;

	nb = ft_itoa(data->move_nb);
	temp = ft_strjoin("MOVE COUNT : ", nb);
	free(nb);
	ft_draw_rectangle(&data->img, 20, 10);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 25, 0xFFFFFF, temp);
	free(temp);
}

long long	ft_get_time(void)
{
	struct timeval	timeval;
	long long		microtime;

	gettimeofday(&timeval, NULL);
	microtime = timeval.tv_sec * 1000LL + timeval.tv_usec / 1000;
	return (microtime);
}
