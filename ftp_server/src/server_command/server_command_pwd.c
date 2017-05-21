/*
** server_command_pwd.c for pwd in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.client_info>
**
** Started on  Sun May 21 03:56:58 2017 Pierre Monge
** Last update Sun May 21 16:06:53 2017 Pierre Monge
*/

#include <string.h>

#include "server_command.h"
#include "request.h"

int	server_command_pwd(t_client_info *client_info, char *argument)
{
  (void)argument;
  if (!client_info->is_authenticated)
    {
      REQUEST_RESPONSE(client_info->client.fd, SERVER_530);
      return (0);
    }
  if (strcmp(client_info->root_dir, client_info->cwd) == 0)
    REQUEST_RESPONSE(client_info->client.fd, SERVER_257, "/");
  else
    REQUEST_RESPONSE(client_info->client.fd, SERVER_257,
		     client_info->cwd + strlen(client_info->root_dir));
  return (0);
}
