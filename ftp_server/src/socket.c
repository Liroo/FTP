/*
** socket.c for socket in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.client_info>
**
** Started on  Sat May 20 04:49:15 2017 Pierre Monge
** Last update Sun May 21 19:19:58 2017 Pierre Monge
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>

#include "socket.h"

int			socket_open(t_socket_info *socket_info,
				    unsigned int port)
{
  struct protoent	*protocol;
  int			option_value;

  if (!(protocol = getprotobyname(PROTOTYPE_NAME)))
    return (fprintf(stderr, EINIT_SOCKET), -1);
  if ((socket_info->fd = socket(AF_INET, SOCK_STREAM, protocol->p_proto)) <= 1)
    return (perror(EINIT_SOCKET_PERROR), -1);
  option_value = 1;
  if (setsockopt(socket_info->fd, SOL_SOCKET,
		 SO_REUSEADDR, &option_value, sizeof(int)) == -1)
    perror(WINIT_SOCKET_OPT_PERROR);
  socket_info->addr.sin_family = AF_INET;
  socket_info->addr.sin_port = htons(port);
  socket_info->addr.sin_addr.s_addr = INADDR_ANY;
  if (bind(socket_info->fd, (const struct sockaddr*)&socket_info->addr,
	   sizeof(socket_info->addr)) == -1
      || listen(socket_info->fd, MAX_CLIENTS) == -1)
    {
      perror(EBIND_OR_LISTEN_SOCKET_PERROR);
      return (socket_close(socket_info->fd), -1);
    }
  return (0);
}

char		*socket_get_ip(t_socket_info socket_info)
{
  char		*str;

  if ((str = malloc(INET_ADDRSTRLEN)) == NULL)
    return (NULL);
  inet_ntop( AF_INET, &socket_info.addr.sin_addr, str, INET_ADDRSTRLEN );
  return (str);
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
