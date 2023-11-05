/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 01:38:30 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/05 01:49:33 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_skin	skin;

	if (argc < 2)
		ft_map_error(TOO_FEW_ARG, NULL, NULL);
	else if (argc > 2)
		ft_map_error(TOO_MANY_ARG, NULL, NULL);
	ft_bzero(&skin, sizeof(skin));
	skin.map_arr = ft_check_map(argv[1]);
	ft_skin_select(&skin);
	ft_window_maker(&skin);
	ft_free_skin(&skin);
	return (OK);
}
