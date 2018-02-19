/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:01:21 by allallem          #+#    #+#             */
/*   Updated: 2018/02/19 17:53:18 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_put_in_calcu(t_fdf *p, int x, int color)
{
	if (x < 0 || x > 1920 * 1080 * 4 ||
		!(x >= p->size_line * p->y1 && x <= p->size_line * (p->y1 + 1)))
		return ;
	p->data[x] = color & 0xFF;
	p->data[x + 1] = (color >> 8) & 0xFF;
	p->data[x + 2] = (color >> 16) & 0xFF;
}

static void	ft_redirect(t_fdf *p)
{
	if (p->xdiff > 0 && p->ydiff >= 0 && p->xdiff >= p->ydiff)
		ft_trace_up_left_right(p, 1);
	else if (p->xdiff > 0 && p->ydiff < 0 && p->xdiff >= ft_abs(p->ydiff))
		ft_trace_bottom_right_left(p, 1);
	else if (p->xdiff < 0 && p->ydiff > 0 && ft_abs(p->xdiff) >= p->ydiff)
		ft_trace_up_left_right(p, 0);
	else if (p->xdiff < 0 && p->ydiff < 0
		&& ft_abs(p->xdiff) >= ft_abs(p->ydiff))
		ft_trace_bottom_right_left(p, 0);
	else if (p->xdiff < 0 && p->ydiff < 0
		&& ft_abs(p->xdiff) <= ft_abs(p->ydiff))
		ft_trace_bottom_left_right(p, 0);
	else if (p->xdiff > 0 && p->ydiff < 0 && p->xdiff <= ft_abs(p->ydiff))
		ft_trace_bottom_left_right(p, 1);
	else if (p->xdiff < 0 && p->ydiff > 0 && ft_abs(p->xdiff) <= p->ydiff)
		ft_trace_up_right_left(p, 0);
	else if (p->xdiff >= 0 && p->ydiff > 0 && p->xdiff <= p->ydiff)
		ft_trace_up_right_left(p, 1);
	else if (p->xdiff == 0 && (p->ydiff < 0 || p->ydiff > 0))
		ft_trace_baton(p);
}

static void	ft_assign_bot(t_fdf *p, int i, int j)
{
	p->x1 = j * p->xmap - ((p->tab[i][j] * p->k) / 2);
	p->y1 = i * p->ymap - (p->tab[i][j] * p->k);
	if (i + 1 < p->y)
	{
		p->x2 = j * p->xmap - ((p->tab[i + 1][j] * p->k) / 2);
		p->y2 = (i + 1) * p->ymap - (p->tab[i + 1][j] * p->k);
		p->xdiff = p->x2 - p->x1;
		p->ydiff = p->y1 - p->y2;
	}
	else
	{
		p->x2 = p->x1;
		p->y2 = p->y1;
		p->xdiff = p->x1 - p->x2;
		p->ydiff = p->y1 - p->y2;
	}
	ft_redirect(p);
}

static void	ft_assign(t_fdf *p, int i, int j)
{
	p->x1 = j * p->xmap - ((p->tab[i][j] * p->k) / 2);
	p->y1 = i * p->ymap - (p->tab[i][j] * p->k);
	if (j + 1 < p->x)
	{
		p->x2 = (j + 1) * p->xmap - ((p->tab[i][j + 1] * p->k) / 2);
		p->y2 = i * p->ymap - (p->tab[i][j + 1] * p->k);
		p->xdiff = p->x2 - p->x1;
		p->ydiff = p->y1 - p->y2;
	}
	else
	{
		p->x2 = p->x1;
		p->y2 = p->y1;
		p->xdiff = p->x1 - p->x2;
		p->ydiff = p->y1 - p->y2;
	}
	ft_redirect(p);
	ft_assign_bot(p, i, j);
}

void		ft_print_image(t_fdf *p)
{
	int i;
	int j;

	i = 0;
	p->xmap = 1820 / p->x;
	p->ymap = 980 / p->y;
	while (i < p->y)
	{
		j = 0;
		while (j < p->x)
		{
			ft_assign(p, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 50, 50);
}
