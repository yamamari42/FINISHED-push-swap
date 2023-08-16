
NAME = push_swap

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
	   do_move.c

OBJS = $(SRCS:.c=.o)
#Regle pour le lieu des .objets

CC = clang

CFLAGS = -Werror -Wall -Wextra -g

RM =rm -f

LIBFT = libft/libft.a

LDFLAGS = -L libft -lft

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

%.o: %.c
	@${CC} ${CFLAGS} -I./ -c $< -o ${<:.c=.o}

$(LIBFT) :
	@make -C libft

clean :
	make clean -C libft
	$(RM) $(OBJS) $(LIBFT)

fclean : clean
	$(RM) ${NAME}

re : fclean all

.PHONY : all clean fclean re

