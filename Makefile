NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

INC 		= 	ft_printf.h

SRCS 		= 	ft_atoi.c		\
				ft_itoa.c		\
				ft_printf.c		\
				print_hexa.c	\
				print_pointeur.c\
				ft_uitoa.c		\
				print_classic.c \
				ft_bzero.c 		\


OBJS = ${SRCS:.c=.o}
 
%.o: %.c $(INC)
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar -rsc $(NAME) $(OBJS)

all: $(NAME)

clean:	
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME) 

re:	fclean all

.PHONY: re clean fclean