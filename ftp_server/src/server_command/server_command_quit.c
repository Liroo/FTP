/*
** server_command_quit.c for quit in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.client_info>
**
** Started on  Sun May 21 03:57:06 2017 Pierre Monge
** Last update Sun May 21 07:22:50 2017 Pierre Monge
*/

#include "server_command.h"
#include "request.h"

int	server_command_quit(t_client_info *client_info, char *argument)
{
  (void)argument;
  REQUEST_RESPONSE(client_info->client.fd, SERVER_221);
  return (1);
}
