/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 02:07:09 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/07 19:42:17 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_management.h"

static void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	ft_free_lst(t_list **lst)
{
	t_list	*temp;

	if (*lst)
	{
		while (*lst)
		{
			temp = *lst;
			*lst = (*lst)->next;
			free(temp->content);
			free(temp);
		}
	}
	free(lst);
}

static void	ft_aff_error(int error)
{
	if (error == TOO_FEW_ARG)
		ft_putstr_fd("Too few arguments\n", 2);
	else if (error == TOO_MANY_ARG)
		ft_putstr_fd("Too many arguments\n", 2);
	else if (error == BAD_NAME)
		ft_putstr_fd("Invalid map name\n", 2);
	else if (error == BAD_EXTENSION)
		ft_putstr_fd("Invalid extension\n", 2);
	else if (error == BAD_MAP)
		ft_putstr_fd("Invalid map's content\n", 2);
	else if (error == NO_WALL)
		ft_putstr_fd("The map is not surrounded by walls\n", 2);
	else if (error == BAD_EXIT)
		ft_putstr_fd("No exit or more than one exit on the map\n", 2);
	else if (error == BAD_START)
		ft_putstr_fd("No start or more than one start on the map\n", 2);
	else if (error == NO_ITEM)
		ft_putstr_fd("No item on the map\n", 2);
	else if (error == NOT_RECTANGLE)
		ft_putstr_fd("The map is not a rectangle\n", 2);
	else if (error == NO_PATH)
		ft_putstr_fd("Impossible to reach at least one item or the exit\n", 2);
	else
		ft_printf("Error is catch, but unknow\nNB : %d\n", error);
}

void	ft_map_error(int error, t_list **lst, char **arr)
{
	if (error < 0)
		ft_putstr_fd("Unknow error\n", 2);
	else
		ft_aff_error(error);
	if (lst)
		ft_free_lst(lst);
	if (arr)
		ft_free_arr(arr);
	exit(KO);
}
