# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaupied <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 19:21:48 by amaupied          #+#    #+#              #
#    Updated: 2020/03/11 18:40:16 by amaupied         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

MKLIB = ar rc

CC = gcc -Wall -Werror -Wextra -c

INCLUDES = -I./

SRCS = ft_memset.c 		\
	   ft_bzero.c 		\
	   ft_memcpy.c 		\
	   ft_memccpy.c 	\
	   ft_memmove.c 	\
	   ft_memchr.c 		\
	   ft_memcmp.c 		\
	   ft_strlen.c 		\
	   ft_strdup.c 		\
	   ft_strcpy.c 		\
	   ft_strncpy.c 	\
	   ft_strcat.c 		\
	   ft_strncat.c		\
	   ft_strlcat.c 	\
	   ft_strchr.c 		\
	   ft_strrchr.c 	\
	   ft_strstr.c 		\
	   ft_strnstr.c 	\
	   ft_strcmp.c 		\
	   ft_strncmp.c 	\
	   ft_atoi.c 		\
	   ft_memalloc.c 	\
	   ft_memdel.c 		\
	   ft_strnew.c 		\
	   ft_strdel.c 		\
	   ft_strclr.c 		\
	   ft_striter.c 	\
	   ft_striteri.c 	\
	   ft_strmap.c 		\
	   ft_strmapi.c 	\
	   ft_strequ.c 		\
	   ft_strnequ.c 	\
	   ft_strsub.c 		\
	   ft_strjoin.c		\
	   ft_strjoin2.c	\
	   ft_strtrim.c		\
	   ft_strtrimc.c	\
	   ft_strsplit.c 	\
	   ft_itoa.c 		\
	   ft_putchar.c		\
	   ft_putstr.c 		\
	   ft_putendl.c 	\
	   ft_putnbr.c 		\
	   ft_putchar_fd.c 	\
	   ft_putstr_fd.c 	\
	   ft_putendl_fd.c 	\
	   ft_putnbr_fd.c 	\
	   ft_sqrt.c		\
	   ft_factorial.c	\
	   ft_itoa_base.c	\
	   utils.c			\
	   utils2.c			\
	   ft_strjoins.c	\
	   ft_strjoin_free.c\
	   ft_strdup_free.c	\
	   ft_strnew_free.c \
	   ft_ltoa.c		\
	   ft_lltoa.c		\
	   ft_htoa.c		\
	   ft_hhtoa.c		\
	   ft_ftoa.c		\
	   check_flags.c	\
	   assign_hdioux.c	\
	   printf.c

OBJ = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all : $(NAME)

$(NAME):
	$(CC) $(INCLUDES) $(SRCS)
	$(MKLIB) $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all

