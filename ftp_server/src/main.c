/*
** main.c for main in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.net>
**
** Started on  Sat May 20 04:48:27 2017 Pierre Monge
** Last update Sun May 21 14:09:40 2017 Pierre Monge
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "socket.h"
#include "listen_for_client.h"

int	main(int argc, char *argv[])
{
  int	socket_fd;
  char	cwd[1024];

  if (argc != 3)
    return (USAGE(argv[0]), 0);
  if (chdir(argv[2]) == -1)
    return (perror(argv[2]), 1);
  if (getcwd(cwd, sizeof(cwd)) == NULL)
    return (perror(NULL), 1);
  if ((socket_fd = socket_open(atoi(argv[1]))) == -1)
    return (1);
  if ((listen_for_client(socket_fd, cwd)) == -1)
    return (1);
  if (socket_close(socket_fd) == -1)
    return (1);
  return (0);
}
