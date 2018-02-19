/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 04:16:23 by allallem          #+#    #+#             */
/*   Updated: 2018/02/19 15:51:54 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_my_key_event(int key, t_fdf *p)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 126)
	{
		mlx_destroy_image(p->mlx, p->img);
		p->img = mlx_new_image(p->mlx, 1980, 1080);
		p->data = (unsigned char *)mlx_get_data_addr(p->img, &p->bpp, &p->size_line, &p->endian);
		p->k += 1;
		ft_print_image(p);
	}
	if (key == 125)
	{
		mlx_destroy_image(p->mlx, p->img);
		p->img = mlx_new_image(p->mlx, 1980, 1080);
		p->data = (unsigned char *)mlx_get_data_addr(p->img, &p->bpp, &p->size_line, &p->endian);
		p->k -= 1;
		ft_print_image(p);
	}
	return (0);
}

static int	ft_init_tab(t_fdf *p)
{
	int i;

	i = 0;
	if (!(p->tab = ft_memalloc(sizeof(int *) * p->y)))
		return (0);
	while (i < p->y)
	{
		if (!(p->tab[i] = ft_memalloc(sizeof(int) * p->x)))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_get_tab(t_fdf *p)
{
	int i;
	int j;
	int k;

	if (!ft_init_tab(p))
		return (0);
	i = 0;
	while (p->map[i])
	{
		j = 0;
		k = 0;
		while (p->map[i][j])
		{
			if ((p->map[i][j] >= 48 && p->map[i][j] <= 57) || p->map[i][j] == '-')
			{
				p->tab[i][k] = ft_atoi(p->map[i] + j);
				k++;
				while (p->map[i][j] != ' ' && p->map[i][j])
					j++;
			}
			else
				j++;
		}
		i++;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_fdf	st;
	t_fdf	*p;
	
	if (argc == 2)
	{
		p = &st;
		ft_bzero(p, sizeof(t_fdf));
		p->k = 4;
		if (!ft_init_fd(argv[1], p))
			return (0);
		if (!ft_verif_tab(p))
			return (0);
		if (!ft_get_tab(p))
			return (0);
		p->mlx = mlx_init();
		p->img = mlx_new_image(p->mlx, 1920, 1080);
		p->data = (unsigned char *)mlx_get_data_addr(p->img, &p->bpp,
				&p->size_line, &p->endian);
		p->win = mlx_new_window(p->mlx, 1920, 1080, "fdf");
		ft_print_image(p);
		mlx_key_hook(p->win, ft_my_key_event, p);
		mlx_loop(p->mlx);
	}
	return (0);
}
