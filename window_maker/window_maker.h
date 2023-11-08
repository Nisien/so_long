/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_maker.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:08:19 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/08 04:29:59 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_MAKER_H
# define WINDOW_MAKER_H
# include <sys/time.h>
# include "../so_long.h"
# define IMG_SIZE 100
# ifndef SL_TITLE
#  define SL_TITLE "Unlimited So Long"
# endif

enum	e_key
{
	W_KEY = 119,
	S_KEY = 115,
	A_KEY = 97,
	D_KEY = 100,
	Q_KEY = 113,
	K_SPACE = 32,
	K_LEFT = 65361,
	K_UP,
	K_RIGHT,
	K_DOWN
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
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	char		**map;
	int			map_x;
	int			map_y;
	int			max_x;
	int			max_y;
	int			last_x;
	int			last_y;
	int			last_max_x;
	int			last_max_y;
	int			win_x;
	int			win_y;
	int			img_size;
	int			img_x;
	int			img_y;
	int			item_nb;
	int			move_nb;
	long long	time;
	t_skin		*skin;
}	t_data;

int			ft_game_loop(t_data *data);
int			ft_handle_hook(int keysym, t_data *data);
int			ft_cross_close(t_data *data);
int			ft_set_map(t_data *data);
void		ft_get_map_aff(t_data *data, int *co, int *max);
void		ft_set_img(t_data *data);
void		ft_put_img(t_data *data, void *img, int option);
void		ft_put_obj(t_data *data, t_obj *obj);
void		ft_put_exit(t_data *data, t_obj *obj);
void		ft_put_ent(t_data *data, t_ent *ent);
void		ft_draw_img(t_img *src, t_img *dst, int x, int y);
void		ft_draw_with_black(t_img *src, t_img *dst, int x, int y);
void		ft_draw_rectangle(t_img *dst, int x, int y);
void		ft_unset_img(t_data *data);
void		ft_find_player_pos(char **arr, int *x, int *y);
void		ft_move_row(t_data *data, int dir);
void		ft_move_column(t_data *data, int dir);
void		ft_attack(t_data *data);
void		ft_put_attack_ent(t_data *data, t_ent *ent, char *area);
void		ft_put_move_count(t_data *data);
long long	ft_get_time(void);

#endif
