/*
** manage_new_client.c for manage_new_client in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.net>
**
** Started on  Sat May 20 05:00:28 2017 Pierre Monge
** Last update Sun May 21 06:21:00 2017 Pierre Monge
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "return_code.h"
#include "request.h"
#include "manage_client.h"

int	manage_new_client(t_client_info client_info)
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
  client_info.username = NULL;
  client_info.isAuthenticated = false;
  REQUEST_RESPONSE(client_info.fd, SERVER_220);
  manage_registered_client(client_info);
  return (1);
}
