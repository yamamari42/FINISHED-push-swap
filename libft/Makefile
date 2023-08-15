# **************************************************************************** #
#																			   #
#														  :::	   ::::::::    #
#	 Makefile											:+:		 :+:	:+:    #
#													  +:+ +:+		  +:+	   #
#	 By: mmardere <marvin@42.fr>					+#+  +:+	   +#+		   #
#												  +#+#+#+#+#+	+#+			   #
#	 Created: 2022/11/24 14:55:56 by mmardere		   #+#	  #+#			   #
#	 Updated: 2022/12/02 17:49:55 by mmardere		  ###	########.fr		   #
#																			   #
# **************************************************************************** #

NAME = libft.a

HEADERS = libft.h

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c\
	   ft_bzero.c\
	   ft_calloc.c\
	   ft_isalnum.c\
	   ft_isalpha.c\
	   ft_isascii.c\
	   ft_isdigit.c\
	   ft_isprint.c\
	   ft_itoa.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_memcpy.c\
	   ft_memmove.c\
	   ft_memset.c\
	   ft_putchar_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c\
	   ft_putstr_fd.c\
	   ft_split.c\
	   ft_strchr.c\
	   ft_strdup.c\
	   ft_striteri.c\
	   ft_strjoin.c\
	   ft_strlcat.c\
	   ft_strlcpy.c\
	   ft_strlen.c\
	   ft_strmapi.c\
	   ft_strncmp.c\
	   ft_strnstr.c\
	   ft_strrchr.c\
	   ft_strtrim.c\
	   ft_substr.c\
	   ft_tolower.c\
	   ft_toupper.c\
	   ft_lstnew.c\
	   ft_lstsize.c\
	   ft_lstlast.c\
	   ft_lstadd_front.c\
	   ft_lstadd_back.c\
	   ft_lstdelone.c\
	   ft_lstclear.c\
	   ft_lstiter.c\
	   ft_lstmap.c\

OBJS = $(SRCS:.c=.o)


CC = gcc


.c.o:
	${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

all : ${NAME}


${NAME} :	 ${OBJS}
		@ar rc ${NAME} ${OBJS}
		@ranlib ${NAME}

#%.o:			%.c
#	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

all: $(NAME)

#$(NAME): $(OBJS) $(BONUS_OBJS)
#	$(CC) $(CFLAGS) -o $@ $^

#bonus:	$(BONUS_OBJS)
#	$(CC) $(CFLAGS) -o $@ $^

clean: 
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:

