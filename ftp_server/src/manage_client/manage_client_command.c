/*
** manage_client_command.c for manage_client in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.client_info>
**
** Started on  Sat May 20 04:59:40 2017 Pierre Monge
** Last update Sun May 21 18:32:23 2017 Pierre Monge
*/

#include <strings.h>
#include <string.h>

#include "manage_client.h"
#include "server_command.h"
#include "request.h"

int    	manage_client_command(t_client_info *client_info,
			      char *command)
{
  int	i;

  i = 0;
  while (server_commands[i].title) {
    if (strncasecmp(command, server_commands[i].title,
		    strlen(server_commands[i].title)) == 0)
      {
	return (server_commands[i]
		.exec(client_info, command + strlen(server_commands[i].title)));
      }
    i++;
  }
  if (!client_info->is_authenticated)
    {
      REQUEST_RESPONSE(client_info->client.fd, SERVER_530);
      return (0);
    }
  REQUEST_RESPONSE(client_info->client.fd, SERVER_500);
  return (0);
}
