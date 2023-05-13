NAME = cub3d
BONUS_NAME =
CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRCS_DIR =

COM_SRCS = 


SRCS = p_parsing.c \
	p_check_map_valid_0.c \
	p_check_map_valid_1.c \
	p_step1_0.c \
	p_step1_1.c \
	p_step2_0.c \
	p_step2_1.c \
	p_ft_func.c\
	p_utill_func.c \
get_next_line/get_next_line.c \
       get_next_line/get_next_line_utils.c \
	   get_next_line/ft_split.c \
		# get_next_line/$(GNL_SRCS)\


GNL_SRCS = get_next_line.c \
		get_next_line_utils.c \


OBJS	= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)


%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)


bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
	cc $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)	

clean :
	rm -rf $(OBJS) 
	rm -rf $(BONUS_OBJS)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)

re : fclean all

.PHONY	: all clean fclean re bonus
