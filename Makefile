#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allallem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 18:42:15 by allallem          #+#    #+#              #
#    Updated: 2018/02/19 17:20:27 by allallem         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	fdf

SRCS	=	main.c ft_tab.c ft_init_fd.c ft_print_image.c ft_trace_seg.c ft_game.c ft_iso.c

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIBX	= -L minilibx_macos -lmlx -framework OpenGL -framework appkit

LIB		= -L libft -lft

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			make -C libft
			make -C minilibx_macos
			$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBX) $(LIB)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
		make -C libft fclean
		make -C minilibx_macos clean
		$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
