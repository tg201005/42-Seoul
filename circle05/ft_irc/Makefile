

NAME = ircserv

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =  channel/Channel.cpp\
		channel/ChannelManager.cpp\
		client/Client.cpp \
		client/ClientManager.cpp \
		message/Message.cpp \
		packet/PacketManager.cpp \
		packet/PacketMaker.cpp \
		packet/Commands.cpp \
		server/Server.cpp \
		socket/Socket.cpp \
		main.cpp \
		packet/ModeManager.cpp \

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CC) $(CXXFLAGS) -o $@ -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re




# docker make file

# all 		:
# 	docker build . --tag irc:my
# 	docker run --name irc --rm irc:my

# run		:
# 	docker run --name irc --rm irc:my

# ins		:
# 	docker exec -it irc inspricd -p 6667 -n one -w 1234

# local		:
# 	docker exec -it irc irssi -c host.docker.internal -p 6667 -n one -w 1234
# c1		:
# 	docker exec -it irc irssi -c 127.0.0.1 -p 6667 -n one -w 1234

# c2		:
# 	docker exec -it irc irssi -c 127.0.0.1 -p 6667 -n two

# c3		:
# 	docker exec -it irc irssi -c 127.0.0.1 -p 6667 -n three

# c4		:
# 	docker exec -it irc irssi -c 127.0.0.1 -p 6667 -n four

# c5		:
# 	docker exec -it irc irssi -c 127.0.0.1 -p 6667 -n five

# n1		:
# 	docker exec -it irc nc 127.0.0.1 6667

# n2		:
# 	docker exec -it irc nc 127.0.0.1 6667

# n3		:
# 	docker exec -it irc nc 127.0.0.1 -p 6667

# n4		:
# 	docker exec -it irc nc 127.0.0.1 -p 6667

# n5		:
# 	docker exec -it irc nc 127.0.0.1 -p 6667


# exec		:
# 	docker exec -it irc bash

# down		:
# 	docker stop irc

# clean		:
# 	docker system prune -a

# re			:
# 	make clean
# 	make all

# .PHONY		: all run c1 c2 c3 c4 c5 exec down clean re