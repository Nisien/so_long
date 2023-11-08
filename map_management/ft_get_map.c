/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 02:08:50 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/07 19:43:38 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_management.h"

char	**ft_lst_to_arr(t_list **lst)
{
	char	**array;
	t_list	*temp;
	int		len;
	int		i;

	if (!lst || !*lst)
		return (NULL);
	len = ft_lstsize(*lst);
	array = malloc(sizeof(char *) * (len + 1));
	if (!array)
		return (NULL);
	i = 0;
	temp = *lst;
	while (temp && i < len)
	{
		array[i] = temp->content;
		*lst = temp;
		temp = temp->next;
		free(*lst);
		i++;
	}
	array[len] = NULL;
	free(lst);
	return (array);
}

static void	ft_replace_nl(char *str)
{
	char	*last;

	last = ft_end_of_string(str);
	if (*last == '\n')
		*last = '\0';
}

static void	ft_map_to_lst(t_list **lst, int fd)
{
	char	*temp;

	if (!lst || fd < 0)
		return ;
	temp = get_next_line(fd);
	if (!temp)
	{
		free(lst);
		return ;
	}
	ft_replace_nl(temp);
	*lst = ft_lstnew(temp);
	while (temp)
	{
		temp = get_next_line(fd);
		if (temp)
		{
			ft_replace_nl(temp);
			ft_lstadd_back(lst, ft_lstnew(temp));
		}
	}
}

t_list	**ft_get_map(char *map_name)
{
	int		fd;
	t_list	**map;

	if (!map_name)
		return (NULL);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_map_error(BAD_NAME, NULL, NULL);
	map = malloc(sizeof(t_list **));
	if (!map)
		return (NULL);
	if (!ft_check_extension(map_name))
		ft_map_error(BAD_EXTENSION, map, NULL);
	ft_map_to_lst(map, fd);
	close(fd);
	if (!map || !*map)
		return (NULL);
	return (map);
}
