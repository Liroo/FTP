/*
** server_command_pass.c for pass in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.client_info>
**
** Started on  Sun May 21 03:56:17 2017 Pierre Monge
** Last update Sun May 21 08:37:01 2017 Pierre Monge
*/

#include <strings.h>

#include "server_command.h"
#include "request.h"

static int	server_command_pass_fake_db_call(char *username, char *password)
{
  if (strcasecmp(username, DB_USERNAME) != 0)
    return (1);
  if (!password || strcasecmp(password, DB_PASS) == 0)
    return (0);
  return (1);
}

int	server_command_pass(t_client_info *client_info, char *argument)
{
  char	**arguments;

  if (!client_info->is_authenticated && !client_info->username)
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_503), 0);
  if (client_info->is_authenticated)
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_230), 0);
  if (!(arguments = request_parse_arguments(argument)))
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_421), -1);
  if (!server_command_pass_fake_db_call(client_info->username, arguments[0]))
    client_info->is_authenticated = true;
  if (client_info->is_authenticated)
    REQUEST_RESPONSE(client_info->client.fd, SERVER_230);
  else
    REQUEST_RESPONSE(client_info->client.fd, SERVER_530);
  request_free_arguments(arguments);
  return (0);
}
