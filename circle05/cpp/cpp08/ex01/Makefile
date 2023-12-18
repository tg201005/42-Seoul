NAME = ./a.out

CXX = c++
CXXFLAG = -Wall -Wextra -Werror -std=c++98 -I.

spS = main.cpp \
Span.cpp


OBJS = $(spS:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAG) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re