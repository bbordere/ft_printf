CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_utils.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

$(NAME): $(OBJS)
	ar rcs ${NAME} ${OBJS}

all : $(NAME)

clean : 
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re