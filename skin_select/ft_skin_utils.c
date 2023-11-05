/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 04:19:19 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/03 07:32:43 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skin_select.h"

int	ft_check_xpm(char *str)
{
	int	i;

	if (!str)
		return (KO);
	if (ft_strlen(str) < 7)
		return (KO);
	if (str[0] != 's' || str[1] != 'p')
		return (KO);
	i = 2;
	while (ft_isdigit((int)str[i]))
		i++;
	if (str[i] != '.' || str[i + 1] != 'x'
		|| str[i + 2] != 'p' || str[i + 3] != 'm')
		return (KO);
	return (OK);
}

int	ft_getxpm_nb(t_skin *skin, char *dir_name)
{
	int			i;
	DIR			*dir;
	t_dirent	*entry;

	i = 0;
	dir = opendir(dir_name);
	if (!dir)
	{
		free(dir_name);
		ft_skin_error(NO_DIR, skin);
	}
	entry = readdir(dir);
	while (entry)
	{
		if (entry->d_type == DT_REG && ft_check_xpm(entry->d_name))
			i++;
		entry = readdir(dir);
	}
	closedir(dir);
	return (i);
}

int	ft_getent_nb(t_skin *skin, char *dir_name, int flag)
{
	int			i;
	DIR			*dir;
	t_dirent	*entry;

	if (flag == DT_DIR)
		i = -2;
	else if (flag == DT_REG)
		i = 0;
	else
		ft_skin_error(NO_DIR, skin);
	dir = opendir(dir_name);
	if (!dir)
		ft_skin_error(NO_DIR, skin);
	entry = readdir(dir);
	while (entry)
	{
		if (entry->d_type == flag)
			i++;
		entry = readdir(dir);
	}
	closedir(dir);
	return (i);
}
