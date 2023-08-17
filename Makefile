# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmardere <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 16:21:43 by mmardere          #+#    #+#              #
#    Updated: 2023/08/17 16:21:49 by mmardere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

SRCS =	srcs/push_swap/main.c \
		srcs/push_swap/parsing.c \
		srcs/push_swap/parsing2.c \
		srcs/push_swap/utils_list.c \
		srcs/push_swap/utils_list2.c \
		srcs/push_swap/push.c \
		srcs/push_swap/swap.c \
		srcs/push_swap/rotate.c \
		srcs/push_swap/reverse_rotate.c \
		srcs/push_swap/sort.c \
		srcs/push_swap/small_algo.c \
		srcs/push_swap/big_algo.c \
		srcs/push_swap/big_algo2.c \
		srcs/push_swap/do_move.c \

SRCS_BONUS =	srcs/bonus/ch_main_utils.c \
		srcs/bonus/ch_main_utils2.c \
		srcs/bonus/ch_main_utils3.c \
		srcs/bonus/ch_main_utils4.c \
		srcs/bonus/ch_main.c \
		srcs/bonus/ch_move.c \
		srcs/bonus/ch_push.c \
		srcs/bonus/ch_swap.c \
		srcs/bonus/ch_rotate.c \
		srcs/bonus/ch_revrotate.c \
		srcs/get_next_line/get_next_line.c \
		srcs/get_next_line/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
#Regle pour le lieu des .objets

CC = clang

CFLAGS = -Werror -Wall -Wextra -g

RM =rm -f

LIBFT = libft/libft.a

LDFLAGS = -L libft -lft

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(CHECKER) : $(OBJS_BONUS) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LDFLAGS) -o $@

%.o: %.c
	@${CC} ${CFLAGS} -I./include -Ilibft -c $< -o ${<:.c=.o}

$(LIBFT) :
	@make -C libft

clean :
	make clean -C libft
	$(RM) $(OBJS) $(LIBFT) $(OBJS_BONUS)

fclean : clean
	$(RM) ${NAME} ${CHECKER}

re : fclean all

.PHONY : all clean fclean re

