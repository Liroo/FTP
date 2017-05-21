/*
** server_command_cdup.c for cdup in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.client_info>
**
** Started on  Sun May 21 03:54:36 2017 Pierre Monge
** Last update Sun May 21 16:05:49 2017 Pierre Monge
*/

#include <string.h>
#include <unistd.h>

#include "server_command.h"
#include "request.h"

int	server_command_cdup(t_client_info *client_info, char *argument)
{
  (void)argument;
  if (!client_info->is_authenticated)
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_530), 0);
  if (chdir("..") == -1)
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_550), 0);
  if (getcwd(client_info->cwd, sizeof(client_info->cwd)) == NULL)
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_421), -1);
  if (strncmp(client_info->root_dir, client_info->cwd,
	      strlen(client_info->root_dir)) != 0)
    chdir(client_info->root_dir);
  if (getcwd(client_info->cwd, sizeof(client_info->cwd)) == NULL)
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_421), -1);
  REQUEST_RESPONSE(client_info->client.fd, SERVER_250);
  return (0);
}
