/*
** server_command.c for server_command.in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.net>
**
** Started on  Sun May 21 04:04:37 2017 Pierre Monge
** Last update Sun May 21 05:04:18 2017 Pierre Monge
*/

#include <stdio.h>

#include "server_command.h"

t_command_alias			*server_get_commands()
{
  static t_command_alias	server_commands[2] = {
    { "USER", "", &server_command_user },
    { 0 }
    };

  return server_commands;
}
