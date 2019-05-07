# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 09:35:23 by astripeb          #+#    #+#              #
#    Updated: 2019/03/18 10:20:44 by astripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

CC = gcc

IDIR = ./includes/

SRCDIR = ./srcs/

CFLAGS = -Wall -Werror -Wextra

OBJ = *.o

SOURCES = $(SRCDIR)*.c

all: bin bsq clean

bsq:
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJ)

bin:
	@ $(CC) $(CFLAGS) -I $(IDIR) -c $(SOURCES)

clean:
	@ rm -f $(OBJ) 

fclean:
	@ rm -f $(OBJ) $(NAME)

re: fclean all
