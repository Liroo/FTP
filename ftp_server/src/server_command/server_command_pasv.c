/*
** server_command_pasv.c for server_command_pasv in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.client_info>
**
** Started on  Sun May 21 13:19:08 2017 Pierre Monge
** Last update Sun May 21 19:44:24 2017 Pierre Monge
*/

#include <string.h>
#include <stdlib.h>

#include "socket.h"
#include "server_command.h"
#include "request.h"

static int	server_command_pasv_init_server(t_client_info *client_info)
{
  if (socket_open(&client_info->control, 0) == -1 ||
      getsockname(client_info->control.fd,
		  (struct sockaddr *)&client_info->control.addr,
		  &client_info->control.addrlen) == -1)
    return (-1);
  return (0);
}

static int	server_command_pasv_close(t_client_info *client_info)
{
  if (client_info->mode == DEFAULT)
    return (0);
  if (socket_close(client_info->control.fd) == -1)
    return (-1);
  if (client_info->data_in_use && socket_close(client_info->data.fd))
    return (-1);
  return (0);
}

int	server_command_pasv(t_client_info *client_info,
			    char *argument __attribute__((__unused__)))
{
  char	*ip;
  int	control_port;
  char	*ip_t[4];

  client_info->control.addrlen = sizeof(struct sockaddr);
  if (!client_info->is_authenticated)
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_530), 0);
  if (server_command_pasv_close(client_info) == -1)
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_421), -1);
  if (server_command_pasv_init_server(client_info) == -1)
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_421), -1);
  if ((ip = socket_get_ip(client_info->server)) == NULL)
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_421), -1);
  control_port = ntohs(client_info->control.addr.sin_port);
  ip_t[0] = strtok(ip, ".");
  ip_t[1] = strtok(NULL, ".");
  ip_t[2] = strtok(NULL, ".");
  ip_t[3] = strtok(NULL, ".");
  REQUEST_RESPONSE(client_info->client.fd, SERVER_227,
		   ip_t[0], ip_t[1], ip_t[2], ip_t[3],
		   control_port / 256, control_port % 256);
  client_info->mode = PASSIV;
  free(ip);
  return (0);
}
