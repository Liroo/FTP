/*
** server_command_noop.c for noop in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.client_info>
**
** Started on  Sun May 21 03:56:09 2017 Pierre Monge
** Last update Sun May 21 16:32:20 2017 Pierre Monge
*/

#include "server_command.h"
#include "request.h"

int	server_command_noop(t_client_info *client_info, char *argument)
{
  (void)argument;
  REQUEST_RESPONSE(client_info->client.fd, SERVER_200);
  return (0);
}
