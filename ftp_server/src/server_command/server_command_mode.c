/*
** server_command_mode.c for mode in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.client_info>
**
** Started on  Sun May 21 03:55:48 2017 Pierre Monge
** Last update Sun May 21 03:55:54 2017 Pierre Monge
*/

#include "server_command.h"
#include "request.h"

int	server_command_mode(t_client_info *client_info, char *argument)
{
  if (!client_info->is_authenticated)
    {
      REQUEST_RESPONSE(client_info->client.fd, SERVER_530);
      return (0);
    }
  REQUEST_RESPONSE(client_info->client.fd, SERVER_502);
  (void)argument;
  return (0);
}
