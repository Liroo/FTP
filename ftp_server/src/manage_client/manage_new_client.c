/*
** manage_new_client.c for manage_new_client in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.client_info>
**
** Started on  Sat May 20 05:00:28 2017 Pierre Monge
** Last update Sun May 21 19:42:53 2017 Pierre Monge
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "request.h"
#include "manage_client.h"

static void	manage_new_client_init(t_client_info *client_info,
				       char *cwd)
{
  strcpy(client_info->root_dir, cwd);
  strcpy(client_info->cwd, cwd);
  strcat(client_info->cwd, "/");
  client_info->mode = DEFAULT;
  REQUEST_RESPONSE(client_info->client.fd, SERVER_220);
}

int	manage_new_client(t_client_info *client_info, char *cwd)
{
  int	instance_pid;

  if ((instance_pid = fork()) < 0)
    {
      perror(EFORK);
      return (-1);
    }
  if (instance_pid != 0)
    {
      return (0);
    }
  manage_new_client_init(client_info, cwd);
  manage_registered_client(client_info);
  return (1);
}
