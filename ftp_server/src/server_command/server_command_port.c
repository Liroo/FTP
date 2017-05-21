/*
** server_command_port.c for port in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.client_info>
**
** Started on  Sun May 21 03:56:30 2017 Pierre Monge
** Last update Sun May 21 20:47:10 2017 Pierre Monge
*/

#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

#include "server_command.h"
#include "request.h"

static int		server_command_port_init_socket(t_client_info
							*client_info,
							char **infos)
{
  char			ip[16];
  int			port;
  int			ret;
  struct protoent	*pe;

  if (request_count_arguments(infos) != 6)
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_500), 0);
  ret = sprintf(ip, "%s.%s.%s.%s", infos[0], infos[1], infos[2], infos[3]);
  ip[ret] = 0;
  port = atoi(infos[4]) * 256 + atoi(infos[5]);
  client_info->control.addrlen = sizeof(struct sockaddr_in);
  client_info->control.addr.sin_family = AF_INET;
  client_info->control.addr.sin_addr.s_addr = inet_addr(ip);
  client_info->control.addr.sin_port = htons(port);
  if (!(pe = getprotobyname(PROTOTYPE_NAME)) ||
      (client_info->control.fd = socket(client_info->control.addr.sin_family,
				     SOCK_STREAM,
				     pe->p_proto)) == -1)
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_421), -1);
  client_info->mode = ACTIV;
  return (REQUEST_RESPONSE(client_info->client.fd, SERVER_200), 0);
}

static int	server_command_port_close(t_client_info *client_info)
{
  if (client_info->mode == DEFAULT)
    return (0);
  if (socket_close(client_info->control.fd) == -1)
    return (-1);
  if (client_info->data_in_use && socket_close(client_info->control.fd))
    return (-1);
  return (0);
}

int	server_command_port(t_client_info *client_info, char *argument)
{
  char	**arguments;
  char	**infos;

  if (!client_info->is_authenticated)
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_530), 0);
  if (server_command_port_close(client_info) == -1)
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_421), -1);
  if (!(arguments = request_parse_arguments(argument)))
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_421), -1);
  if (request_count_arguments(arguments) == 0)
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_500), 0);
  if (!(infos = request_parse_arguments_delimiter(arguments[0], ',')))
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_421), -1);
  request_free_arguments(arguments);
  if (server_command_port_init_socket(client_info, infos) == -1)
    return (-1);
  request_free_arguments(infos);
  return (0);
}
