/*
** server_command_list.c for list in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.client_info>
**
** Started on  Sun May 21 03:55:20 2017 Pierre Monge
** Last update Sun May 21 22:36:10 2017 Pierre Monge
*/

#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "server_command.h"
#include "request.h"

int	server_command_list_loop(t_client_info *client_info, char *argument)
{
  FILE	*in;
  char	stdout[4096];
  int	i;

  (void)argument;
  i = 0;
  if (!(in = popen("ls -l", "r")))
    return (-1);
  while (fgets(&stdout[i], 4096 - i, in))
    i = strlen(stdout);
  pclose(in);
  REQUEST_RESPONSE(client_info->data.fd, SINGLE_STRING, stdout);
  return (0);
}

static int	server_command_list_close(t_client_info *client_info)
{
  if (client_info->mode == DEFAULT)
    return (0);
  if (client_info->mode == PASSIV && socket_close(client_info->data.fd) == -1)
    return (-1);
  if (socket_close(client_info->control.fd))
    return (-1);
  return (0);
}

int	server_command_list(t_client_info *client_info, char *argument)
{
  if (!client_info->is_authenticated)
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_530), 0);
  if (client_info->mode == DEFAULT)
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_425), 0);
  if (server_remote_connection(client_info) == -1)
    return (-1);
  client_info->data_in_use = true;
  REQUEST_RESPONSE(client_info->client.fd, SERVER_150);
  if (server_command_list_loop(client_info, argument) == -1)
    return (-1);
  REQUEST_RESPONSE(client_info->client.fd, SERVER_226);
  if (server_command_list_close(client_info) == -1)
    return (-1);
  client_info->data_in_use = false;
  return (0);
}
