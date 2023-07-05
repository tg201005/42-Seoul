NAME = convert

CXX = c++
CXXFLAGS  = -Wall -Wextra -Werror -std=c++98

# SRCS = main.cpp \
# ScalarConvert.cpp

SRCS = main.cpp \
ScalarConvert.cpp \


OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS ) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS ) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re