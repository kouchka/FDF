/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_seg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 16:16:03 by allallem          #+#    #+#             */
/*   Updated: 2018/02/17 19:23:59 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_trace_baton(t_fdf *p)
{
	int		j;

	j = 0;
	p->ydiff = ft_abs(p->ydiff);
	while (j < p->ydiff)
	{
		ft_put_in_calcu(p, (p->x1 * 4) + (p->size_line * (j + p->y1)), 0xFFFFFF);
		j++;
	}
}

void		ft_trace_up_left(t_fdf *p)
{
	float	yjump;
	int		j;

	j = 0;
	p->xdiff = ft_abs(p->xdiff);
	p->ydiff = ft_abs(p->ydiff);
	(p->xdiff > p->ydiff) ? yjump = p->ydiff / p->xdiff : 0;
	(p->ydiff > p->xdiff) ? yjump = p->xdiff / p->ydiff : 0;
	p->temp = yjump;
	while (j < p->xdiff)
	{
		if (yjump >= 1)
		{
			p->y1--;
			ft_put_in_calcu(p, ((p->x1 - j) * 4) + (p->size_line * p->y1), 0xFFFFFF);
			yjump = yjump - 1;
		}
		else
			ft_put_in_calcu(p, ((p->x1 - j) * 4) + (p->size_line * p->y1), 0xFFFFFF);
		yjump += p->temp;
		j++;
	}
}

void		ft_trace_bottom_left(t_fdf *p)
{
	float	yjump;
	int		j;

	j = 0;
	p->xdiff = ft_abs(p->xdiff);
	p->ydiff = ft_abs(p->ydiff);
	(p->xdiff > p->ydiff) ? yjump = p->ydiff / p->xdiff : 0;
	(p->ydiff > p->xdiff) ? yjump = p->xdiff / p->ydiff : 0;
	p->temp = yjump;
	while (j < p->xdiff)
	{
		if (yjump >= 1)
		{
			p->y1++;
			ft_put_in_calcu(p, ((p->x1 - j) * 4) + (p->size_line * p->y1), 0xFFFFFF);
			yjump = yjump - 1;
		}
		else
			ft_put_in_calcu(p, ((p->x1 - j) * 4) + (p->size_line * p->y1), 0xFFFFFF);
		j++;
		yjump += p->temp;
	}
}

void		ft_trace_up_right(t_fdf *p)
{
	float	yjump;
	int		j;

	j = 0;
	p->xdiff = ft_abs(p->xdiff);
	p->ydiff = ft_abs(p->ydiff);
	(p->xdiff > p->ydiff) ? yjump = p->ydiff / p->xdiff : 0;
	(p->ydiff > p->xdiff) ? yjump = p->xdiff / p->ydiff : 0;
	p->temp = yjump;
	while (j < p->xdiff)
	{
		if (yjump >= 1)
		{
			p->y1--;
			ft_put_in_calcu(p, ((p->x1 + j) * 4) + (p->size_line * p->y1), 0xFFFFFF);
			yjump = yjump - 1;
		}
		else
			ft_put_in_calcu(p, ((p->x1 + j) * 4) + (p->size_line * p->y1), 0xFFFFFF);
		j++;
		yjump += p->temp;
	}
}

void		ft_trace_bottom_right(t_fdf *p)
{
	float	yjump;
	int		j;

	j = 0;
	p->xdiff = ft_abs(p->xdiff);
	p->ydiff = ft_abs(p->ydiff);
	(p->xdiff > p->ydiff) ? yjump = p->ydiff / p->xdiff : 0;
	(p->ydiff > p->xdiff) ? yjump = p->xdiff / p->ydiff : 0;
	p->temp = yjump;
	while (j < p->xdiff)
	{
		if (yjump >= 1)
		{
			p->y1++;
			ft_put_in_calcu(p, ((p->x1 + j) * 4) + (p->size_line * p->y1), 0xFFFFFF);
			yjump = yjump - 1;
		}
		else
			ft_put_in_calcu(p, ((p->x1 + j) * 4) + (p->size_line * p->y1), 0xFFFFFF);
		j++;
		yjump += p->temp;
	}
}
