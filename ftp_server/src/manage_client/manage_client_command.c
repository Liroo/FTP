/*
** manage_client_command.c for manage_client in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.net>
**
** Started on  Sat May 20 04:59:40 2017 Pierre Monge
** Last update Sun May 21 05:03:16 2017 Pierre Monge
*/

#include <strings.h>
#include <string.h>

#include "manage_client.h"
#include "server_command.h"
#include "request.h"

int			manage_client_command(t_client_info *client_info,
					      char *command)
{
  t_command_alias      *server_commands;

  server_commands = server_get_commands();
  while (*((char *)server_commands)) {
    if (strncasecmp(command, (*server_commands).title,
		    strlen((*server_commands).title)) == 0)
      {
	return (*server_commands).exec(client_info, command);
      }
    server_commands++;
  }
  if (!client_info->isAuthenticated)
    {
      REQUEST_RESPONSE(client_info->fd, SERVER_530);
      return (0);
    }
  REQUEST_RESPONSE(client_info->fd, SERVER_500);
  return (0);
}
