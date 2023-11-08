/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skin_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 01:20:23 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/07 08:08:36 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skin_select.h"

static void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

static void	ft_free_obj(t_obj obj)
{
	ft_free_arr((char **)obj.sp_arr);
}

static void	ft_free_ent(t_ent ent)
{
	ft_free_obj(ent.up);
	ft_free_obj(ent.down);
	ft_free_obj(ent.left);
	ft_free_obj(ent.right);
	ft_free_obj(ent.mv_up);
	ft_free_obj(ent.mv_down);
	ft_free_obj(ent.mv_left);
	ft_free_obj(ent.mv_right);
	ft_free_obj(ent.atk_up);
	ft_free_obj(ent.atk_down);
	ft_free_obj(ent.atk_left);
	ft_free_obj(ent.atk_right);
}

void	ft_free_skin(t_skin *skin)
{
	free(skin->name);
	skin->name = NULL;
	ft_free_arr(skin->map_arr);
	skin->map_arr = NULL;
	ft_free_obj(skin->empty);
	ft_free_obj(skin->wall);
	ft_free_obj(skin->exit);
	ft_free_obj(skin->item);
	ft_free_ent(skin->mob);
	ft_free_ent(skin->player);
}

void	ft_skin_error(int error, t_skin *skin)
{
	if (error < 0)
		ft_putstr_fd("Unknow error\n", 2);
	else if (error == NO_DIR)
		ft_putstr_fd("No directory\n", 2);
	else if (error == NO_SKIN)
		ft_putstr_fd("No skin present\n", 2);
	else if (error == NF_ITEM)
		ft_putstr_fd("Missing item file\n", 2);
	else if (error == NF_ENT)
		ft_putstr_fd("Missing mob or player file\n", 2);
	else if (error == NF_OTHER)
		ft_putstr_fd("Missing other file\n", 2);
	else if (error == SK_MALLOC)
		ft_putstr_fd("Cannot allocate more memory\n", 2);
	else if (error == NO_CHOICE)
		ft_putstr_fd("You don't know how to read, your loss\n", 2);
	ft_free_skin(skin);
	exit(KO);
}
