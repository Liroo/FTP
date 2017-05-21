/*
** listen_for_client.c for listen_for_client in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.client_info>
**
** Started on  Sat May 20 04:57:15 2017 Pierre Monge
** Last update Sun May 21 18:50:04 2017 Pierre Monge
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

#include "listen_for_client.h"
#include "socket.h"
#include "manage_client.h"

/*
  This is not endeable loop except on Ctrl-C, this is why
  there is a while (1).

  We will use a signal handler to catch and exit the server
*/

int		listen_for_client(t_client_info *client_buffer, char *cwd)
{
  client_buffer->client.addrlen = sizeof(struct sockaddr_in);
  while (1)
    {
      if ((client_buffer->client.fd =
	   accept(client_buffer->server.fd,
		  (struct sockaddr *)&client_buffer->client.addr,
		  &client_buffer->client.addrlen)) < -1)
	{
	  perror(EACCEPT_CLIENT);
	  return (-1);
	}
      if (manage_new_client(client_buffer, cwd) != 0)
	break;
    }
  return (0);
}
