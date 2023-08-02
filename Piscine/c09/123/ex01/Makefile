CC = gcc
CFLASGS = -Werror -Wextra -Wall
NAME = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o
INC = includes


all : $(NAME)

clean :
	rm -f $(OBJS) 
fclean : clean
	rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	ar -rc $@ $^

srcs/ft_putchar.o : srcs/ft_putchar.c 
	$(CC) $(CFLAGS) -c $^ -o srcs/ft_putchar.o -I $(INC)

srcs/ft_swap.o : srcs/ft_swap.c
	$(CC) $(CFLAGS) -c $^ -o srcs/ft_swap.o -I $(INC)

srcs/ft_putstr.o : srcs/ft_putstr.c 
	$(CC) $(CFLAGS) -c $^ -o srcs/ft_putstr.o -I $(INC)

srcs/ft_strlen.o : srcs/ft_strlen.c 
	$(CC) $(CFLAGS)  -c $^ -o srcs/ft_strlen.o -I $(INC)

srcs/ft_strcmp.o : srcs/ft_strcmp.c
	$(CC) $(CFLAGS)  -c $^ -o srcs/ft_strcmp.o -I $(INC)

.PHONY: all clean fclean re
