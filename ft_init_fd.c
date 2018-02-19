/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 16:50:16 by allallem          #+#    #+#             */
/*   Updated: 2018/02/19 13:02:14 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_free(t_fdf *p, char *line, char *dr_freeman)
{
	dr_freeman = p->tmp;
	p->tmp = ft_strjoin(p->tmp, line);
	free(dr_freeman);
}

int			ft_init_fd(char *str, t_fdf *p)
{
	int		fd;
	char	*line;
	char	*dr_freeman;

	fd = 0;
	if ((fd = open(str, O_RDONLY)) < 0)
		return (0);
	while (get_next_line(fd, &line))
	{
		p->y++;
		dr_freeman = line;
		line = ft_strjoin(line, "\n");
		free(dr_freeman);
		if (p->tmp == NULL)
			p->tmp = ft_strdup(line);
		else
			ft_free(p, line, dr_freeman);
		free(line);
	}
	p->map = ft_strsplit(p->tmp, '\n');
	free(p->tmp);
	close(fd);
	return (1);
}
