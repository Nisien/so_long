/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 01:37:40 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/07 19:00:32 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "define.h"

char	**ft_check_map(char *map_name);
void	ft_map_error(int error, t_list **lst, char **arr);
void	ft_window_maker(t_skin *skin);
void	ft_skin_select(t_skin *skin);
void	ft_free_skin(t_skin *skin);

#endif
