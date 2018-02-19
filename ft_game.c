#include "fdf.h"

int		ft_game(t_fdf *p)
{
	if (p->play == 1)
	{
		mlx_destroy_image(p->mlx, p->img);
		p->img = mlx_new_image(p->mlx, 1880, 980);
		p->data = (unsigned char *)mlx_get_data_addr(p->img,
				&p->bpp, &p->size_line, &p->endian);
		p->k += 1;
		ft_print_image(p);
	}
	else if (p->play == -1)
	{
		mlx_destroy_image(p->mlx, p->img);
		p->img = mlx_new_image(p->mlx, 1880, 980);
		p->data = (unsigned char *)mlx_get_data_addr(p->img,
				&p->bpp, &p->size_line, &p->endian);
		p->k -= 1;
		ft_print_image(p);
	}
	if (p->iso == 1)
		ft_iso(p);
	return (0);
}
