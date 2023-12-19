NAME = ./btc

CXX = c++
CXXFLAG = -Wall -Wextra -Werror -std=c++98 -I.

SRCS = main.cpp \
BitcoinExchange.cpp \


OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAG) $(OBJS) -o $(NAME)

clean:
	mv $(OBJS) ~/.Trash

fclean: clean
	mv $(NAME) ~/.Trash

re: fclean all

.PHONY: all clean fclean re