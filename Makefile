
NAME = push_swap

CHECKER = checker

SRCS = main.c \
	   parsing.c \
	   parsing2.c \
	   utils_list.c \
	   utils_list2.c \
	   push.c \
	   swap.c \
	   rotate.c \
	   reverse_rotate.c \
	   sort.c \
	   small_algo.c \
	   big_algo.c \
	   big_algo2.c \
	   do_move.c

SRCS_BONUS	=	ch_main.c \
		ch_move.c \
		ch_push.c \
		ch_rotate.c \
		ch_revrotate.c \
		ch_swap.c \
		get_next_line_utils.c \
		get_next_line.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
#Regle pour le lieu des .objets

CC = clang

CFLAGS = -Werror -Wall -Wextra -g

RM =rm -f

LIBFT = libft/libft.a

LDFLAGS = -L libft -lft

all : $(NAME) $(OBJS_BONUS)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(CHECKER) : $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LDFLAGS) -o $@

%.o: %.c
	@${CC} ${CFLAGS} -I./ -c $< -o ${<:.c=.o}

$(LIBFT) :
	@make -C libft

clean :
	make clean -C libft
	$(RM) $(OBJS) $(OBJS_BONUS) $(LIBFT)

fclean : clean
	$(RM) ${NAME} ${CHECKER}

re : fclean all

.PHONY : all clean fclean re

