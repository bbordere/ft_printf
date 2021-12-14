CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_str.c ft_putnbr.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

$(NAME): $(OBJS)
	ar rcs ${NAME} ${OBJS}
	ranlib ${NAME}

all : $(NAME)

clean : 
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re