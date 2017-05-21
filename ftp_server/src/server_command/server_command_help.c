/*
** server_command_help.c for help in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.net>
**
** Started on  Sun May 21 03:55:10 2017 Pierre Monge
** Last update Sun May 21 05:12:42 2017 Pierre Monge
*/

#include "server_command.h"
#include "request.h"

int	server_command_help(t_client_info *client_info, char *argument)
{
  REQUEST_RESPONSE(client_info->fd, SERVER_502);
  (void)argument;
  return (0);
}
