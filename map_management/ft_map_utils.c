/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 05:26:32 by nrossa            #+#    #+#             */
/*   Updated: 2023/10/31 13:25:47 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_management.h"

int	ft_map_is_rectangle(t_list *map)
{
	size_t	width;
	size_t	height;

	width = ft_strlen(map->content);
	height = ft_lstsize(map);
	if (width <= height)
		return (KO);
	while (map)
	{
		if (ft_strlen(map->content) != width)
			return (KO);
		map = map->next;
	}
	return (OK);
}

void	ft_find_player_pos(char **arr, int *row, int *column)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == PLAYER)
			{
				*row = i;
				*column = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_reset_map(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == CHECKED)
				arr[i][j] = EMPTY;
			if (arr[i][j] == CHEXIT)
				arr[i][j] = EXIT;
			if (arr[i][j] == CHITEM)
				arr[i][j] = ITEM;
			if (arr[i][j] == CHMOB)
				arr[i][j] = MOB;
			j++;
		}
		i++;
	}
}
