/*
** server_command_user.c for user in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.net>
**
** Started on  Sun May 21 04:00:42 2017 Pierre Monge
** Last update Sun May 21 08:37:37 2017 Pierre Monge
*/

#include <string.h>
#include <stdlib.h>

#include "server_command.h"
#include "request.h"

int	server_command_user(t_client_info *client_info, char *argument)
{
  char	**arguments;

  if (client_info->isAuthenticated)
    return (REQUEST_RESPONSE(client_info->fd, SERVER_530), 0);
  if (!(arguments = request_parse_arguments(argument)))
    return (REQUEST_RESPONSE(client_info->fd, SERVER_421), -1);
  if (request_count_arguments(arguments) == 0)
    return (REQUEST_RESPONSE(client_info->fd, SERVER_530), 0);
  if (client_info->username)
    free(client_info->username);
  if (!(client_info->username = strdup(arguments[0])))
    return (REQUEST_RESPONSE(client_info->fd, SERVER_421), -1);
  REQUEST_RESPONSE(client_info->fd, SERVER_331);
  request_free_arguments(arguments);
  return (0);
}
