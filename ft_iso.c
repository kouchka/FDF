#include "fdf.h"

static void		ft_assign_bot(t_fdf *p, int i, int j)
{
	p->x1 = (j + (p->x / 2) - i) * p->xmap - p->tab[i][j];
	p->y1 = (i + j) * p->ymap - p->tab[i][j];
	if (i + 1 < p->y)
	{
		p->x2 = ((p->x / 2) - j - 1) * p->xmap - ((p->tab[i + 1][j]));
		p->y2 = (i + j + 1) * p->ymap - (p->tab[i + 1][j]);
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

static void		ft_assign(t_fdf *p, int i, int j)
{
	p->x1 = (j + (p->x / 2) - i) * p->xmap - p->tab[i][j];
	p->y1 = (i + j) * p->ymap - p->tab[i][j];
	if (j + 1 < p->x)
	{
		p->x2 = (j + (p->x / 2) + 1) * p->xmap - ((p->tab[i][j + 1]));
		p->y2 = (i + j + 1) * p->ymap - (p->tab[i][j + 1]);
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

void		ft_iso(t_fdf *p)
{
	int i;
	int j;

	i = 0;
	mlx_destroy_image(p->mlx, p->img);
	p->img = mlx_new_image(p->mlx, 1880, 980);
	p->data = (unsigned char *)mlx_get_data_addr(p->img,
		&p->bpp, &p->size_line, &p->endian);
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
