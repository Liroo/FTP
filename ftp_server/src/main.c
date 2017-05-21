/*
** main.c for main in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.client_info>
**
** Started on  Sat May 20 04:48:27 2017 Pierre Monge
** Last update Sun May 21 19:17:26 2017 Pierre Monge
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "socket.h"
#include "listen_for_client.h"

int		main(int argc, char *argv[])
{
  t_client_info	client_buffer;
  char		cwd[1024];

  if (argc != 3)
    return (USAGE(argv[0]), 0);
  if (chdir(argv[2]) == -1)
    return (perror(argv[2]), 1);
  if (getcwd(cwd, sizeof(cwd)) == NULL)
    return (perror(NULL), 1);
  memset(&client_buffer, 0, sizeof(t_client_info));
  if (socket_open(&client_buffer.server, atoi(argv[1])) == -1)
    return (1);
  if ((listen_for_client(&client_buffer, cwd)) == -1)
    return (1);
  if (socket_close(client_buffer.server.fd) == -1)
    return (1);
  return (0);
}
