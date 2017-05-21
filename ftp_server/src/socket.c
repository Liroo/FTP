/*
** socket.c for socket in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.net>
**
** Started on  Sat May 20 04:49:15 2017 Pierre Monge
** Last update Sun May 21 13:44:37 2017 Pierre Monge
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>

#include "socket.h"

int			socket_open(unsigned int port)
{
  struct protoent	*protocol;
  int			socket_fd;
  int			option_value;
  struct sockaddr_in	s_in;

  if (port == 0 || !(protocol = getprotobyname(PROTOTYPE_NAME)))
    return (fprintf(stderr, EINIT_SOCKET), -1);
  if ((socket_fd = socket(AF_INET, SOCK_STREAM, protocol->p_proto)) <= 1)
    return (perror(EINIT_SOCKET_PERROR), -1);
  option_value = 1;
  if (setsockopt(socket_fd, SOL_SOCKET,
		 SO_REUSEADDR, &option_value, sizeof(int)) == -1)
    perror(WINIT_SOCKET_OPT_PERROR);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  if (bind(socket_fd, (const struct sockaddr*)&s_in, sizeof(s_in)) == -1
      || listen(socket_fd, MAX_CLIENTS) == -1)
    {
      perror(EBIND_OR_LISTEN_SOCKET_PERROR);
      return (socket_close(socket_fd), -1);
    }
  return (socket_fd);
}

int	socket_close(int socket_fd)
{
  if (close(socket_fd) == -1)
    {
      perror(ESOCKET_CLOSE);
      return (-1);
    }

  return (0);
}
