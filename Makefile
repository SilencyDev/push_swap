# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/30 13:54:50 by kmacquet          #+#    #+#              #
#    Updated: 2021/03/30 14:41:35 by kmacquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror -I./includes
NAME1 = checker
SRCS1 = srcs/checker.c
OBJS1 = $(SRCS1:.c=.o)
NAME2 = push_swap
SRCS2 =	srcs/push_swap.c
OBJS2 = $(SRCS2:.c=.o)
RM = rm -rf


all : $(NAME1) $(NAME2)

$(NAME1) : $(OBJS1)
	$(CC) $(FLAGS) $(OBJS1) -o $(NAME1)

$(NAME2) : $(OBJS2)
	$(CC) $(FLAGS) $(OBJS2) -o $(NAME2)

clean :
	$(RM) $(OBJS1)
	$(RM) $(OBJS2)

fclean : clean
	$(RM) $(NAME1)
	$(RM) $(NAME2)

re : fclean all

perfect : all clean

.PHONY : re fclean clean all perfect
