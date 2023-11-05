/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skin_select.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:12:04 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/03 20:49:33 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skin_select.h"

static void	ft_free_arr(char **skin_arr)
{
	int	i;

	i = 0;
	while (skin_arr[i])
	{
		free(skin_arr[i]);
		i++;
	}
	free(skin_arr);
}

static char	**ft_fill_skin_arr(char **skin_arr, int skin_nb, t_skin *skin)
{
	DIR			*dir;
	t_dirent	*entry;
	int			i;

	dir = opendir(SKIN_DIR);
	if (!dir)
		ft_skin_error(NO_DIR, skin);
	entry = readdir(dir);
	i = 0;
	while (i < skin_nb)
	{
		if (entry->d_type == DT_DIR)
		{
			skin_arr[i] = ft_strdup(entry->d_name);
			if (!ft_strcmp(skin_arr[i], ".") || !ft_strcmp(skin_arr[i], ".."))
				free(skin_arr[i]);
			else
				i++;
		}
		entry = readdir(dir);
	}
	skin_arr[skin_nb] = NULL;
	closedir(dir);
	return (skin_arr);
}

static char	*ft_get_choice(char **skin_arr)
{
	int		i;
	int		nb;
	char	*choice;

	i = 0;
	ft_putstr_fd("Select a skin from this list (choose with number):\n", 1);
	while (skin_arr[i])
	{
		ft_printf("%d - %s\n", i + 1, skin_arr[i]);
		i++;
	}
	ft_putstr_fd("\nYour choice : ", 1);
	choice = get_next_line(0);
	nb = ft_atoi(choice);
	free(choice);
	if (nb < 1 || nb > i)
		return (NULL);
	else
	{
		ft_printf("\nYou have selected : %s\n\n", skin_arr[nb - 1]);
		return (ft_strjoin(SKIN_DIR, skin_arr[nb - 1]));
	}
}

static void	ft_do_try(t_skin *skin, char **skin_arr)
{
	int		try_nb;

	try_nb = 0;
	skin->name = ft_get_choice(skin_arr);
	while (!skin->name)
	{
		if (try_nb < 2)
		{
			try_nb++;
			ft_putstr_fd("Invalid number, choose again\n", 1);
			ft_printf("You have %d remaining try\n\n", 3 - try_nb);
		}
		else
		{
			ft_free_arr(skin_arr);
			ft_skin_error(NO_CHOICE, skin);
		}
		skin->name = ft_get_choice(skin_arr);
	}
}

void	ft_skin_select(t_skin *skin)
{
	int		skin_nb;
	char	**skin_arr;

	skin_nb = ft_getent_nb(skin, SKIN_DIR, DT_DIR);
	if (skin_nb <= 0)
		ft_skin_error(NO_DIR, skin);
	skin_arr = malloc(sizeof(char *) * (skin_nb + 1));
	if (!skin_arr)
		ft_skin_error(SK_MALLOC, skin);
	skin_arr = ft_fill_skin_arr(skin_arr, skin_nb, skin);
	ft_do_try(skin, skin_arr);
	ft_free_arr(skin_arr);
	ft_check_skin(skin);
	free(skin->name);
	skin->name = NULL;
}
