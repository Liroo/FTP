/*
** server_command.c for server_command.in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.client_info>
**
** Started on  Sun May 21 04:04:37 2017 Pierre Monge
** Last update Sun May 21 22:33:08 2017 Pierre Monge
*/

#include <string.h>
#include <limits.h>
#include <stdlib.h>

#include "request.h"
#include "server_command.h"

t_command_alias	server_commands[34] = {
  { "USER", HELP_USER, &server_command_user },
  { "PASS", HELP_PASS, &server_command_pass },
  { "ACCT", HELP_ACCT, &server_command_acct },
  { "CWD", HELP_CWD, &server_command_cwd },
  { "CDUP", HELP_CDUP, &server_command_cdup },
  { "SMNT", HELP_SMNT, &server_command_smnt },
  { "REIN", HELP_REIN, &server_command_rein },
  { "QUIT", HELP_QUIT, &server_command_quit },
  { "PORT", HELP_PORT, &server_command_port },
  { "PASV", HELP_PASV, &server_command_pasv },
  { "TYPE", HELP_TYPE, &server_command_type },
  { "STRU", HELP_STRU, &server_command_stru },
  { "MODE", HELP_MODE, &server_command_mode },
  { "RETR", HELP_RETR, &server_command_retr },
  { "STOR", HELP_STOR, &server_command_stor },
  { "STOU", HELP_STOU, &server_command_stou },
  { "APPE", HELP_APPE, &server_command_appe },
  { "ALLO", HELP_ALLO, &server_command_allo },
  { "REST", HELP_REST, &server_command_rest },
  { "RNFR", HELP_RNFR, &server_command_rnfr },
  { "RNTO", HELP_RNTO, &server_command_rnto },
  { "ABOR", HELP_ABOR, &server_command_abor },
  { "DELE", HELP_DELE, &server_command_dele },
  { "RMD", HELP_RMD, &server_command_rmd },
  { "MDK", HELP_MDK, &server_command_mdk },
  { "PWD", HELP_PWD, &server_command_pwd },
  { "LIST", HELP_LIST, &server_command_list },
  { "NLST", HELP_NLST, &server_command_nlst },
  { "SITE", HELP_SITE, &server_command_site },
  { "SYST", HELP_SYST, &server_command_syst },
  { "STAT", HELP_STAT, &server_command_stat },
  { "HELP", HELP_HELP, &server_command_help },
  { "NOOP", HELP_NOOP, &server_command_noop },
  { 0 }
};

int	server_remote_connection(t_client_info *client_info)
{
  client_info->data.addrlen = sizeof(struct sockaddr);
  if (client_info->mode == PASSIV)
    {
      if ((client_info->data.fd =
	  accept(client_info->control.fd,
		 (struct sockaddr *)&client_info->data.addr,
		 &client_info->data.addrlen)) == -1)
	return (REQUEST_RESPONSE(client_info->client.fd, SERVER_421), -1);
    }
  else if (client_info->mode == ACTIV &&
	   connect(client_info->data.fd,
		   (struct sockaddr *)&client_info->data.addr,
		   client_info->data.addrlen) == -1)
    return (REQUEST_RESPONSE(client_info->client.fd, SERVER_421), -1);
  return (0);
}

char	*server_get_real_path(char *path, char *root)
{
  char	*real_path;
  char	ret_path[4096];

  printf("test\n");
  if (path[0] == '/')
    {
      sprintf(ret_path, "%s/%s", root, path);
      real_path = realpath(strdup(ret_path), NULL);
    }
  else if (!(real_path = realpath(path, NULL)))
    {
      return (NULL);
    }
  printf("test1\n");
  return (real_path);
}
