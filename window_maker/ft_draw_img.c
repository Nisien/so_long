/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 03:46:04 by nrossa            #+#    #+#             */
/*   Updated: 2023/11/06 19:08:23 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_maker.h"

static void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	ft_draw_rectangle(t_img *dst, int x, int y)
{
	int		y_px;
	int		x_px;

	y_px = 0;
	while (y_px < 20)
	{
		x_px = 0;
		while (x_px < 115)
		{
			img_pix_put(dst, x_px + x, y_px + y, 0xFF000000);
			x_px++;
		}
		y_px++;
	}
}

void	ft_draw_with_black(t_img *src, t_img *dst, int x, int y)
{
	char	*px;
	int		y_px;
	int		x_px;

	y_px = 0;
	while (y_px < IMG_SIZE)
	{
		x_px = 0;
		while (x_px < IMG_SIZE)
		{
			px = src->addr + (y_px * src->len + x_px * (src->bpp / 8));
			img_pix_put(dst, x_px + x, y_px + y, *(unsigned int *)px);
			x_px++;
		}
		y_px++;
	}
}

void	ft_draw_img(t_img *src, t_img *dst, int x, int y)
{
	char	*px;
	int		y_px;
	int		x_px;

	y_px = 0;
	while (y_px < IMG_SIZE)
	{
		x_px = 0;
		while (x_px < IMG_SIZE)
		{
			px = src->addr + (y_px * src->len + x_px * (src->bpp / 8));
			if (*(unsigned int *)px != 0xFF000000)
				img_pix_put(dst, x_px + x, y_px + y, *(unsigned int *)px);
			x_px++;
		}
		y_px++;
	}
}
