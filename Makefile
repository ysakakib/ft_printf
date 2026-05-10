# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusakaki <yusakaki@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/09 00:00:20 by yusakaki          #+#    #+#              #
#    Updated: 2026/05/10 18:58:21 by yusakaki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
HEADER		=	ft_printf.h

SRC		=	ft_printf.c \
			ft_printf_utils1.c \
			ft_printf_utils2.c \
			ft_printf_handlers1.c \
			ft_printf_handlers2.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror

CC		=	cc

RM		=	rm -f

AR		=	ar rcs

all:		$(NAME)

$(NAME):	$(OBJ)
			$(AR) $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
