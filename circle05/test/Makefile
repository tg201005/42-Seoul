
.PHONY: all up down restart stop build clean fclean show

all: up

up: 
	@mkdir -p /home/tyi/data/wordpress /home/tyi/data/mariadb
	@docker compose -f srcs/docker-compose.yml up -d 

down:
	@docker compose -f srcs/docker-compose.yml down 

restart:
	@docker compose -f srcs/docker-compose.yml restart 

stop:
	@docker compose -f srcs/docker-compose.yml stop 

build:
	@docker compose -f srcs/docker-compose.yml build 

clean:
	@docker compose -f srcs/docker-compose.yml down -v 
	@sudo rm -rf /home/tyi/data

fclean:
	@docker compose -f srcs/docker-compose.yml down -v --rmi all 
	@sudo rm -rf /home/tyi/data


ls:
	@docker ps -a 
	@docker images 
	@docker volume ls 
	@docker network ls 
