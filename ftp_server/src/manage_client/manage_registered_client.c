/*
** manage_registered_client.c for manage_registered_client in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.net>
**
** Started on  Sat May 20 05:01:06 2017 Pierre Monge
** Last update Sun May 21 06:34:52 2017 Pierre Monge
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>

#include "manage_client.h"
#include "request.h"

int	manage_registered_client(t_client_info client_info)
{
  int	ret = 0;
  char	command_buffer[COMMAND_LEN_MAX];

  while ((ret = read(client_info.fd, command_buffer, COMMAND_LEN_MAX + 1)) > 0)
    {
      command_buffer[ret] = 0;
      if (manage_client_command(&client_info, command_buffer) != 0)
	{
	  break;
	}
    }
  if (client_info.username)
    free(client_info.username);
  shutdown(client_info.fd, SHUT_RDWR);
  socket_close(client_info.fd);
  return (0);
}
