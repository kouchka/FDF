/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 04:14:36 by allallem          #+#    #+#             */
/*   Updated: 2018/02/17 17:42:14 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned char	*data;
	int				bpp;
	int				endian;
	int				size_line;
	int				x;
	int				y;
	int				xmap;
	int				ymap;
	float			xdiff;
	float			ydiff;
	float			temp;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				k;
	char			*tmp;
	char			**map;
	int				**tab;
}					t_fdf;

int					ft_init_fd(char *str, t_fdf *p);
int					ft_verif_tab(t_fdf *p);
void				ft_print_image(t_fdf *p);
void				ft_trace_bottom_right_left(t_fdf *p, int i);
void				ft_trace_up_left_right(t_fdf *p, int i);
void				ft_trace_bottom_left_right(t_fdf *p, int i);
void				ft_trace_up_right_left(t_fdf *p, int i);
void				ft_put_in_calcu(t_fdf *p, int x, int color);
void				ft_trace_baton(t_fdf *p);

#endif
