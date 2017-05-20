/*
** manage_new_client.c for manage_new_client in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.net>
**
** Started on  Sat May 20 05:00:28 2017 Pierre Monge
** Last update Sat May 20 05:00:39 2017 Pierre Monge
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "return_code.h"
#include "manage_new_client.h"
#include "manage_registered_client.h"

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
  write(client_info.fd, WELCOME_CLIENT, strlen(WELCOME_CLIENT));
  manage_registered_client(client_info);
  return (-1);
}
