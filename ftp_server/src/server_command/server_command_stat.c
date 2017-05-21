/*
** server_command_stat.c for stat in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.net>
**
** Started on  Sun May 21 03:59:39 2017 Pierre Monge
** Last update Sun May 21 03:59:43 2017 Pierre Monge
*/

#include "server_command.h"
#include "request.h"

int	server_command_stat(t_client_info *client_info, char *argument)
{
  if (!client_info->isAuthenticated)
    {
      REQUEST_RESPONSE(client_info->fd, SERVER_530);
      return (0);
    }
  REQUEST_RESPONSE(client_info->fd, SERVER_502);
  (void)argument;
  return (0);
}
