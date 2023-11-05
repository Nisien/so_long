/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_skin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:04:00 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/04 05:17:39 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skin_select.h"

static void	ft_set_path(t_skin *skin, t_obj *obj, char *name)
{
	char	*str1;
	char	*str2;
	int		i;

	i = 0;
	while (i < obj->sp_nb)
	{
		str1 = obj->sp_arr[i];
		str2 = ft_strjoin("/", str1);
		free(str1);
		str1 = ft_strjoin(name, str2);
		free(str2);
		obj->sp_arr[i] = ft_strjoin(skin->name, str1);
		free(str1);
		i++;
	}
}

static int	ft_check_dir(t_skin *skin, t_obj *obj, char *dir_name)
{
	DIR			*dir;
	char		*name;

	name = ft_strjoin(skin->name, dir_name);
	if (!name)
		return (KO);
	obj->sp_nb = ft_getxpm_nb(skin, name);
	if (!obj->sp_nb)
		return (free(name), KO);
	dir = opendir(name);
	free(name);
	if (!dir)
		return (KO);
	obj->sp_arr = ft_get_sprites(obj, dir);
	ft_set_path(skin, obj, dir_name);
	closedir(dir);
	if (!obj->sp_arr)
		return (KO);
	return (OK);
}

static void	ft_check_ent_dir(t_skin *skin, t_obj *obj, char *dir, char *subdir)
{
	char	*temp;

	temp = ft_strjoin(dir, subdir);
	if (!temp)
		ft_skin_error(NF_ENT, skin);
	if (!ft_check_dir(skin, obj, temp))
	{
		free(temp);
		ft_skin_error(NF_ENT, skin);
	}
	free(temp);
}

static void	ft_check_ent(t_skin *skin, t_ent *ent, char *dir_name)
{
	ft_check_ent_dir(skin, &ent->up, dir_name, "/up");
	ft_check_ent_dir(skin, &ent->down, dir_name, "/down");
	ft_check_ent_dir(skin, &ent->left, dir_name, "/left");
	ft_check_ent_dir(skin, &ent->right, dir_name, "/right");
	ft_check_ent_dir(skin, &ent->mv_up, dir_name, "/up/move");
	ft_check_ent_dir(skin, &ent->mv_down, dir_name, "/down/move");
	ft_check_ent_dir(skin, &ent->mv_left, dir_name, "/left/move");
	ft_check_ent_dir(skin, &ent->mv_right, dir_name, "/right/move");
}

void	ft_check_skin(t_skin *skin)
{
	if (!skin || !skin->name)
		ft_skin_error(-1, skin);
	if (!ft_check_dir(skin, &skin->empty, "/empty"))
		ft_skin_error(NF_OTHER, skin);
	if (!ft_check_dir(skin, &skin->wall, "/wall"))
		ft_skin_error(NF_OTHER, skin);
	if (!ft_check_dir(skin, &skin->exit, "/exit"))
		ft_skin_error(NF_OTHER, skin);
	if (!ft_check_dir(skin, &skin->item, "/item"))
		ft_skin_error(NF_ITEM, skin);
	ft_check_ent(skin, &skin->mob, "/mob");
	ft_check_ent(skin, &skin->player, "/player");
}
