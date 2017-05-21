/*
** server_command_help.c for help in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.client_info>
**
** Started on  Sun May 21 03:55:10 2017 Pierre Monge
** Last update Sun May 21 16:42:52 2017 Pierre Monge
*/

#include <string.h>

#include "server_command.h"
#include "request.h"

static void	server_command_help_full(t_client_info *client_info)
{
  int		i;

  i = 0;
  REQUEST_RESPONSE_L(client_info->client.fd, SERVER_HELP_FULL);
  while (server_commands[i].title)
    {
      if (i != 0 && i != 10 && i != 20 && i != 30)
	REQUEST_RESPONSE_S(client_info->client.fd, SINGLE_STRING, " ");
      REQUEST_RESPONSE_S(client_info->client.fd, SINGLE_STRING,
			 server_commands[i].title);
      if (i == 9 || i == 19 || i == 29)
	REQUEST_RESPONSE_S(client_info->client.fd, SINGLE_STRING, "\n");
      i++;
    }
  REQUEST_RESPONSE_S(client_info->client.fd, SINGLE_STRING, "\n");
  REQUEST_RESPONSE(client_info->client.fd, SERVER_214);
}

static void	server_command_help_single(t_client_info *client_info,
					   char *command)
{
  int		i;

  i = 0;
  while (server_commands[i].title)
    {
      if (strcasecmp(server_commands[i].title, command) == 0)
	{
	  REQUEST_RESPONSE_L(client_info->client.fd,
			     SINGLE_STRING, server_commands[i].help);
	  break;
	}
      i++;
    }
  if (server_commands[i].title)
    REQUEST_RESPONSE(client_info->client.fd, SERVER_211);
  else
    server_command_help_full(client_info);
}

int	server_command_help(t_client_info *client_info, char *argument)
{
  char	**arguments;

  if (!(arguments = request_parse_arguments(argument)))
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_421), -1);
  if (request_count_arguments(arguments) == 0)
    server_command_help_full(client_info);
  else
    server_command_help_single(client_info, arguments[0]);
  request_free_arguments(arguments);
  return (0);
}
