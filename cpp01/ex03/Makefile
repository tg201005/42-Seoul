NAME = a.out

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = HumanA.cpp\
HumanB.cpp\
Weapon.cpp\
main.cpp\

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re