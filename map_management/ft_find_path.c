/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:45:31 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/02 21:59:56 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_management.h"

static int	ft_spread_for_item(char **arr, int row, int column)
{
	int	i;

	i = 0;
	i += ft_find_item(arr, row - 1, column);
	i += ft_find_item(arr, row + 1, column);
	i += ft_find_item(arr, row, column - 1);
	i += ft_find_item(arr, row, column + 1);
	return (i);
}

int	ft_find_item(char **arr, int row, int column)
{
	int	i;

	i = 0;
	if (arr[row][column] == ITEM)
	{
		arr[row][column] = CHITEM;
		i += 1;
		i += ft_spread_for_item(arr, row, column);
		return (i);
	}
	else if (arr[row][column] == EMPTY || arr[row][column] == EXIT
	|| arr[row][column] == PLAYER || arr[row][column] == MOB)
	{
		if (arr[row][column] == EMPTY)
			arr[row][column] = CHECKED;
		if (arr[row][column] == EXIT)
			arr[row][column] = CHEXIT;
		if (arr[row][column] == MOB)
			arr[row][column] = CHMOB;
		i += ft_spread_for_item(arr, row, column);
		return (i);
	}
	else
		return (0);
}

static int	ft_find_exit(char **arr, int row, int column)
{
	int	i;

	i = 0;
	if (arr[row][column] == EXIT)
	{
		arr[row][column] = CHEXIT;
		return (1);
	}
	else if (arr[row][column] == EMPTY || arr[row][column] == ITEM
	|| arr[row][column] == PLAYER || arr[row][column] == MOB)
	{
		if (arr[row][column] == EMPTY)
			arr[row][column] = CHECKED;
		if (arr[row][column] == ITEM)
			arr[row][column] = CHITEM;
		if (arr[row][column] == MOB)
			arr[row][column] = CHMOB;
		i += ft_find_exit(arr, row - 1, column);
		i += ft_find_exit(arr, row + 1, column);
		i += ft_find_exit(arr, row, column - 1);
		i += ft_find_exit(arr, row, column + 1);
		return (i);
	}
	else
		return (0);
}

int	ft_find_path(char **arr, int nb)
{
	int	player_row;
	int	player_column;

	player_row = 0;
	player_column = 0;
	ft_find_player_pos(arr, &player_row, &player_column);
	if (ft_find_exit(arr, player_row, player_column))
	{
		ft_reset_map(arr);
		if (ft_find_item(arr, player_row, player_column) == nb)
		{
			ft_reset_map(arr);
			return (OK);
		}
	}
	return (KO);
}
