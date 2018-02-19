/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 16:51:40 by allallem          #+#    #+#             */
/*   Updated: 2018/02/19 17:32:03 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_init_seg(t_fdf *p, float *yjump)
{
	p->xdiff = ft_abs(p->xdiff);
	p->ydiff = ft_abs(p->ydiff);
	(p->xdiff >= p->ydiff) ? *yjump = p->ydiff / p->xdiff : 0;
	(p->ydiff >= p->xdiff) ? *yjump = p->xdiff / p->ydiff : 0;
	p->temp = *yjump;
}

static void	ft_path_number(int i, int *j, int *count, t_fdf *p)
{
	if (p->map[i][*j] >= 48 && p->map[i][*j] <= 57)
	{
		while (p->map[i][*j] != ' ' && p->map[i][*j])
			*j = *j + 1;
		*count = *count + 1;
	}
	else
		*j = *j + 1;
}

int			ft_verif_tab(t_fdf *p)
{
	int i;
	int j;
	int count;

	i = 0;
	while (p->map[i])
	{
		count = 0;
		j = 0;
		while (p->map[i][j])
			ft_path_number(i, &j, &count, p);
		if (p->x == 0)
			p->x = count;
		else if (count != p->x)
			return (0);
		i++;
	}
	return (1);
}
