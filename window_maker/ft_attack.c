/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:39:00 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/08 00:45:30 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_maker.h"

static void	ft_put_attack_obj(t_data *data, t_obj *obj, char *area)
{
	ft_put_img(data, obj->sp_arr[obj->state], OK);
	if (obj->state == (obj->sp_nb - 1))
	{
		obj->state = 0;
		if (*area == PATK)
			*area = PLAYER;
		else if (*area == PATKEX)
			*area = PEXIT;
	}
	else
		obj->state++;
}

void	ft_put_attack_ent(t_data *data, t_ent *ent, char *area)
{
	if (ent->dir == RIGHT)
		ft_put_attack_obj(data, &ent->atk_right, area);
	else if (ent->dir == LEFT)
		ft_put_attack_obj(data, &ent->atk_left, area);
	else if (ent->dir == UP)
		ft_put_attack_obj(data, &ent->atk_up, area);
	else if (ent->dir == DOWN)
		ft_put_attack_obj(data, &ent->atk_down, area);
}

static void	ft_do_attack(t_data *data, int *co)
{
	if (data->map[co[Y] + 1][co[X]] == MOB)
		data->map[co[Y] + 1][co[X]] = TEMPTY;
	else if (data->map[co[Y] - 1][co[X]] == MOB)

		data->map[co[Y] - 1][co[X]] = TEMPTY;
	else if (data->map[co[Y]][co[X] + 1] == MOB)
		data->map[co[Y]][co[X] + 1] = TEMPTY;
	else if (data->map[co[Y]][co[X] - 1] == MOB)
		data->map[co[Y]][co[X] - 1] = TEMPTY;
}

void	ft_attack(t_data *data)
{
	int	co[2];

	ft_find_player_pos(data->map, &co[X], &co[Y]);
	if (data->map[co[Y]][co[X]] == PEXIT
		|| data->map[co[Y]][co[X]] == PATKEX)
		data->map[co[Y]][co[X]] = PATKEX;
	else
		data->map[co[Y]][co[X]] = PATK;
	ft_do_attack(data, co);
}
