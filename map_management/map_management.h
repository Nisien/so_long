/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_management.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 02:02:55 by nrossa            #+#    #+#             */
/*   Updated: 2023/10/31 12:16:07 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_MANAGEMENT_H
# define MAP_MANAGEMENT_H
# include <fcntl.h>
# include "../libft/libft.h"
# include "../define.h"

typedef struct s_check
{
	int	exit;
	int	start;
	int	item;
}	t_check;

char	*ft_end_of_string(char *str);
char	**ft_lst_to_arr(t_list **lst);
int		ft_check_extension(char *str);
int		ft_map_is_rectangle(t_list *map);
int		ft_find_path(char **arr, int nb);
int		ft_find_item(char **arr, int row, int column);
t_list	**ft_get_map(char *map_name);
void	ft_map_error(int error, t_list **lst, char **arr);
void	ft_find_player_pos(char **arr, int *x, int *y);
void	ft_reset_map(char **arr);

#endif
