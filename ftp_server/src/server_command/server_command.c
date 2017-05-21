/*
** server_command.c for server_command.in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.net>
**
** Started on  Sun May 21 04:04:37 2017 Pierre Monge
** Last update Sun May 21 08:13:22 2017 Pierre Monge
*/

#include <stdio.h>

#include "server_command.h"

t_command_alias			*server_get_commands()
{
  static t_command_alias	server_commands[34] = {
    { "USER", "", &server_command_user }, { "PASS", "", &server_command_pass },
    { "QUIT", "", &server_command_quit }, { "QUIT", "", &server_command_quit },
    { "QUIT", "", &server_command_quit }, { "QUIT", "", &server_command_quit },
    { "QUIT", "", &server_command_quit }, { "QUIT", "", &server_command_quit },
    { "QUIT", "", &server_command_quit }, { "QUIT", "", &server_command_quit },
    { "QUIT", "", &server_command_quit }, { "QUIT", "", &server_command_quit },
    { "QUIT", "", &server_command_quit }, { "QUIT", "", &server_command_quit },
    { "QUIT", "", &server_command_quit }, { "QUIT", "", &server_command_quit },
    { "QUIT", "", &server_command_quit }, { "QUIT", "", &server_command_quit },
    { "QUIT", "", &server_command_quit }, { "QUIT", "", &server_command_quit },
    { "QUIT", "", &server_command_quit }, { "QUIT", "", &server_command_quit },
    { "QUIT", "", &server_command_quit }, { "QUIT", "", &server_command_quit },
    { "QUIT", "", &server_command_quit }, { "QUIT", "", &server_command_quit },
    { "QUIT", "", &server_command_quit }, { "QUIT", "", &server_command_quit },
    { "QUIT", "", &server_command_quit }, { "QUIT", "", &server_command_quit },
    { "QUIT", "", &server_command_quit }, { "QUIT", "", &server_command_quit },
    { "QUIT", "", &server_command_quit },
    { 0 }
    };

  return server_commands;
}
