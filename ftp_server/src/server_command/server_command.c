/*
** server_command.c for server_command.in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.net>
**
** Started on  Sun May 21 04:04:37 2017 Pierre Monge
** Last update Sun May 21 13:18:35 2017 Pierre Monge
*/

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
