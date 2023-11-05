/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:58:30 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/04 04:37:11 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skin_select.h"

static int	ft_check_sprite(char *str, int nb)
{
	int	str_nb;

	str_nb = ft_atoi(str + 2);
	if (str_nb == nb)
		return (OK);
	else
		return (KO);
}

static void	**ft_sort_sprites(void **arr, int *sp_nb, int nb)
{
	void	**temp_arr;
	int		i;
	int		j;

	temp_arr = malloc(sizeof(void *) * (nb + 1));
	if (!temp_arr)
		return (free(arr), NULL);
	temp_arr[nb] = NULL;
	i = 0;
	while (i < nb)
	{
		j = -1;
		while (arr[++j])
		{
			if (i < nb)
			{
				if (ft_check_sprite(arr[j], sp_nb[i]))
				{
					temp_arr[i] = arr[j];
					i++;
				}
			}
		}
	}
	return (free(arr), free(sp_nb), temp_arr);
}

static void	ft_sort_sprite_nb(int *arr, int nb)
{
	int	i;
	int	temp;

	i = 0;
	while (i < nb - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}
		i++;
	}
	i = 0;
	while (i < nb - 1)
	{
		if (arr[i] > arr[i + 1])
			ft_sort_sprite_nb(arr, nb);
		i++;
	}
}

static int	*ft_get_sprite_nb(void **arr, int nb)
{
	int	i;
	int	*arr_nb;

	arr_nb = malloc(sizeof(int) * (nb));
	if (!arr_nb)
		return (NULL);
	i = 0;
	while (arr[i] && i < nb)
	{
		arr_nb[i] = ft_atoi(arr[i] + 2);
		i++;
	}
	ft_sort_sprite_nb(arr_nb, nb);
	return (arr_nb);
}

void	**ft_get_sprites(t_obj *obj, DIR *dir)
{
	t_dirent	*entry;
	void		**temp_arr;
	int			*sp_nb;
	int			i;

	temp_arr = malloc(sizeof(void *) * (obj->sp_nb + 1));
	if (!temp_arr)
		return (NULL);
	temp_arr[obj->sp_nb] = NULL;
	i = 0;
	entry = readdir(dir);
	while (entry)
	{
		if (entry->d_type == DT_REG && ft_check_xpm(entry->d_name))
		{
			temp_arr[i] = ft_strdup(entry->d_name);
			i++;
		}
		entry = readdir(dir);
	}
	sp_nb = ft_get_sprite_nb(temp_arr, obj->sp_nb);
	temp_arr = ft_sort_sprites(temp_arr, sp_nb, obj->sp_nb);
	return (temp_arr);
}
