/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skin_select.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:14:43 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/03 23:58:06 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKIN_SELECT_H
# define SKIN_SELECT_H
# include <dirent.h>
# include "../so_long.h"
# ifndef SKIN_DIR
#  define SKIN_DIR "./sprites/"
# endif

enum	e_skin_error
{
	NO_DIR,
	NO_SKIN,
	NF_ITEM,
	NF_ENT,
	NF_OTHER,
	SK_MALLOC,
	NO_CHOICE
};

typedef struct dirent	t_dirent;

int		ft_getent_nb(t_skin *skin, char *dir_name, int flag);
int		ft_getxpm_nb(t_skin *skin, char *dir_name);
int		ft_check_xpm(char *str);
void	ft_skin_error(int error, t_skin *skin);
void	ft_check_skin(t_skin *skin);
void	ft_free_skin(t_skin *skin);
void	**ft_get_sprites(t_obj *obj, DIR *dir);

#endif
