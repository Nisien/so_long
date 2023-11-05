/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_maker.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:08:19 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/05 22:22:13 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_MAKER_H
# define WINDOW_MAKER_H
# include "../so_long.h"
# define IMG_SIZE 100
# ifndef SL_TITLE
#  define SL_TITLE "Unlimited So Long"
# endif

enum	e_winmaker_error
{
	MLX
};

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	char	**map;
	int		map_x;
	int		map_y;
	int		win_x;
	int		win_y;
	int		img_size;
	int		img_x;
	int		img_y;
	t_skin	*skin;
}	t_data;

int		ft_render(t_data *data);
int		ft_set_handle(int keysym, t_data *data);
void	ft_set_img(t_data *data);
void	ft_put_img(t_data *data, void *img);
void	ft_put_obj(t_data *data, t_obj *obj);
void	ft_put_ent(t_data *data, t_ent *ent);
void	ft_unset_img(t_data *data);

#endif
