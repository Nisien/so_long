/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:41:22 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/07 21:54:39 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

enum	e_map
{
	EMPTY = 48,
	WALL,
	TEMPTY,
	ITEM = 67,
	EXIT = 69,
	MOB = 77,
	PLAYER = 80,
	PEXIT,
	PATK,
	PATKEX,
	CHECKED = 54,
	CHEXIT,
	CHITEM,
	CHMOB
};

enum	e_result
{
	KO,
	OK
};

enum	e_coordinate
{
	X,
	Y
};

enum	e_direction
{
	RIGHT,
	LEFT,
	UP,
	DOWN
};

enum	e_map_error
{
	TOO_FEW_ARG,
	TOO_MANY_ARG,
	BAD_EXTENSION,
	BAD_NAME,
	NO_WALL,
	BAD_MAP,
	BAD_EXIT,
	BAD_START,
	NO_ITEM,
	NOT_RECTANGLE,
	NO_PATH
};

typedef struct s_obj
{
	int		sp_nb;
	int		state;
	void	**sp_arr;
}	t_obj;

typedef struct s_ent
{
	int		dir;
	t_obj	up;
	t_obj	down;
	t_obj	left;
	t_obj	right;
	t_obj	mv_up;
	t_obj	mv_down;
	t_obj	mv_left;
	t_obj	mv_right;
	t_obj	atk_up;
	t_obj	atk_down;
	t_obj	atk_left;
	t_obj	atk_right;
}	t_ent;

typedef struct s_skin
{
	char		*name;
	char		**map_arr;
	t_obj		empty;
	t_obj		wall;
	t_obj		exit;
	t_obj		item;
	t_ent		mob;
	t_ent		player;
}	t_skin;

#endif
