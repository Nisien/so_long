/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 01:33:26 by nrossa            #+#    #+#             */
/*   Updated: 2023/10/31 12:33:30 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_management.h"

static void	ft_check_line(char *line, t_check *check_list, t_list **map)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != EMPTY && line[i] != WALL && line[i] != ITEM
			&& line[i] != EXIT && line[i] != PLAYER && line[i] != MOB)
			ft_map_error(BAD_MAP, map, NULL);
		if (line[i] == EXIT)
			check_list->exit += 1;
		else if (line[i] == PLAYER)
			check_list->start += 1;
		else if (line[i] == ITEM)
			check_list->item += 1;
		i++;
	}
}

static int	ft_check_inside(t_list **map, t_check *check_list)
{
	t_list	*temp;
	char	*line;

	temp = (*map)->next;
	while (temp != ft_lstlast(temp))
	{
		line = temp->content;
		if (line[0] != WALL || *(ft_end_of_string(line)) != WALL)
			ft_map_error(NO_WALL, map, NULL);
		ft_check_line(line, check_list, map);
		temp = temp->next;
	}
	if (check_list->exit != 1)
		ft_map_error(BAD_EXIT, map, NULL);
	else if (check_list->start != 1)
		ft_map_error(BAD_START, map, NULL);
	return (check_list->item);
}

static int	ft_check_content(t_list **map)
{
	t_check	check_list;
	char	*first;
	char	*last;
	int		i;

	check_list = (t_check){0, 0, 0};
	first = (*map)->content;
	last = ft_lstlast(*map)->content;
	i = 0;
	while (first[i] && last[i])
	{
		if (first[i] != EMPTY && first[i] != WALL && first[i] != ITEM
			&& first[i] != EXIT && first[i] != PLAYER && first[i] != MOB)
			ft_map_error(BAD_MAP, map, NULL);
		if (last[i] != EMPTY && last[i] != WALL && last[i] != ITEM
			&& last[i] != EXIT && last[i] != PLAYER && last[i] != MOB)
			ft_map_error(BAD_MAP, map, NULL);
		if (first[i] != WALL || last[i] != WALL)
			ft_map_error(NO_WALL, map, NULL);
		i++;
	}
	ft_check_inside(map, &check_list);
	return (check_list.item);
}

char	**ft_check_map(char *map_name)
{
	t_list			**map_lst;
	char			**map_arr;
	int				item_nb;

	map_lst = ft_get_map(map_name);
	item_nb = ft_check_content(map_lst);
	if (item_nb <= 0)
		ft_map_error(NO_ITEM, map_lst, NULL);
	if (!ft_map_is_rectangle(*map_lst))
		ft_map_error(NOT_RECTANGLE, map_lst, NULL);
	map_arr = ft_lst_to_arr(map_lst);
	if (!ft_find_path(map_arr, item_nb))
		ft_map_error(NO_PATH, NULL, map_arr);
	return (map_arr);
}
