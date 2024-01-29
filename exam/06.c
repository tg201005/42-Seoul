#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

typedef struct s_client {
  int id;
  char msg[800001];
} t_client;

t_client clients[1024];

void exitError(char *str) {
  if (str) write(2, str, strlen(str));
  exit(1);
}

int main(int argc, char *argv[]) {
  fd_set active, readSock, writeSock;
  struct sockaddr_in servAddr, cli;
  int id = -1;

  if (argc != 2) exitError("Wrong number of arguments\n");

  int port = atoi(argv[1]);
  if (port < 3) exitError("Fatal error\n");

  int serverSock = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSock == -1) exitError("Fatal error\n");

  FD_ZERO(&active);
  FD_SET(serverSock, &active);
  int max = serverSock;

  servAddr.sin_family = AF_INET;
  servAddr.sin_addr.s_addr = htonl(2130706433);  // 127.0.0.1
  servAddr.sin_port = htons(port);

  if (bind(serverSock, (const struct sockaddr *)&servAddr, sizeof(servAddr)),
      sizeof(servAddr) == -1)
    exitError("Fatal error\n");

  if (listen(serverSock, 128) == -1) exitError("Fatal error\n");

  while (1) {
    readSock = active;
    writeSock = active;

    if (select(max + 1, &readSock, &writeSock, NULL, NULL) < 0) continue;

    for (int fd = 0; fd <= max; fd++) {
      if (FD_ISSET(fd, &readSock) && fd == serverSock) {
        socklen_t len = sizeof(cli);
        int clientSock = accept(serverSock, (struct sockaddr *)&cli, &len);
        if (clientSock == -1) exitError("Fatal error\n");
        id++;
        clients[clientSock].id = id;

        char buff[500];
        sprintf(buff, "server: client %d just arrived\n", id);
        for (int sock = 0; sock <= max; sock++) {
          if (FD_ISSET(sock, &active) && sock != serverSock)
            write(sock, buff, strlen(buff));
        }
        FD_SET(clientSock, &active);
        if (clientSock > max) max = clientSock;
        break;
      } else if (FD_ISSET(fd, &readSock) && fd != serverSock) {
        recv(fd, clients[fd].msg, 800000, 0);
        if (clients[fd].msg[0] == '\0') {
          char buff[500];
          sprintf(buff, "server: client %d just left\n", clients[fd].id);
          for (int sock = 0; sock <= max; sock++) {
            if (FD_ISSET(sock, &active) && sock != serverSock && sock != fd)
              write(sock, buff, strlen(buff));
          }
          clients[fd].id = 0;
          bzero(clients[fd].msg, 800001);
          FD_CLR(fd, &active);
          break;
        } else {
          char buff[800001];
          bzero(buff, 800001);
          char *start = clients[fd].msg;
          char *buffstart = buff;
          for (int i = 0; clients[fd].msg[i]; i++) {
            if (clients[fd].msg[i] == '\n') {
              clients[fd].msg[i] = '\0';
              sprintf(buffstart, "client %d: %s\n", clients[fd].id, start);
              start = clients[fd].msg + i + 1;
              buffstart = buff + strlen(buff);
            }
          }
          if (*start != '\0')
            sprintf(buffstart, "client %d: %s", clients[fd].id, start);
          for (int sock = 0; sock <= max; sock++) {
            if (FD_ISSET(sock, &active) && sock != serverSock && sock != fd)
              write(sock, buff, strlen(buff));
          }
          bzero(clients[fd].msg, 800001);
          break;
        }
      }
    }
  }
}