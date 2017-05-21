/*
** main.c for main in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.net>
**
** Started on  Sat May 20 04:48:27 2017 Pierre Monge
** Last update Sun May 21 06:23:16 2017 Pierre Monge
*/

#include <stdlib.h>
#include <stdio.h>

#include "socket.h"
#include "listen_for_client.h"

int	main(int argc __attribute__((unused)), char *argv[])
{
  int	socket_fd;

  if ((socket_fd = socket_open(atoi(argv[1]))) == -1)
    return (1);
  if ((listen_for_client(socket_fd)) == -1)
    return (1);
  if (socket_close(socket_fd) == -1)
    return (1);
  return (0);
}
