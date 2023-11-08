/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 04:08:22 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/07 22:01:56 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_maker.h"

static int	ft_lose(t_data *data)
{
	ft_printf("Too bad, a monster catched you ! You lose with %d moves.\n",
		data->move_nb);
	ft_handle_hook(XK_Escape, data);
	return (OK);
}

static void	ft_do_move_column(t_data *data, int *co, int dir)
{
	if (data->map[co[Y] + dir][co[X]] == EXIT)
		data->map[co[Y] + dir][co[X]] = PEXIT;
	else
	{
		if (data->map[co[Y] + dir][co[X]] == ITEM)
			data->item_nb--;
		data->map[co[Y] + dir][co[X]] = PLAYER;
	}
	if (data->map[co[Y]][co[X]] == PEXIT)
		data->map[co[Y]][co[X]] = EXIT;
	else
		data->map[co[Y]][co[X]] = TEMPTY;
}

void	ft_move_column(t_data *data, int dir)
{
	int	co[2];

	ft_find_player_pos(data->map, &co[X], &co[Y]);
	if (data->map[co[Y] + dir][co[X]] == WALL)
		return ;
	if (data->map[co[Y] + dir][co[X]] == MOB)
	{
		ft_lose(data);
		return ;
	}
	ft_do_move_column(data, co, dir);
	data->move_nb++;
	ft_printf("Move count = %d\n", data->move_nb);
}

static void	ft_do_move_row(t_data *data, int *co, int dir)
{
	if (data->map[co[Y]][co[X] + dir] == EXIT)
		data->map[co[Y]][co[X] + dir] = PEXIT;
	else
	{
		if (data->map[co[Y]][co[X] + dir] == ITEM)
			data->item_nb--;
		data->map[co[Y]][co[X] + dir] = PLAYER;
	}
	if (data->map[co[Y]][co[X]] == PEXIT)
		data->map[co[Y]][co[X]] = EXIT;
	else
		data->map[co[Y]][co[X]] = TEMPTY;
}

void	ft_move_row(t_data *data, int dir)
{
	int	co[2];

	ft_find_player_pos(data->map, &co[X], &co[Y]);
	if (data->map[co[Y]][co[X] + dir] == WALL)
		return ;
	if (data->map[co[Y]][co[X] + dir] == MOB)
	{
		ft_lose(data);
		return ;
	}
	ft_do_move_row(data, co, dir);
	data->move_nb++;
	ft_printf("Move count = %d\n", data->move_nb);
}
