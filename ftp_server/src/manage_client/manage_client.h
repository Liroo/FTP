/*
** manage_client.h for manage_client_h in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.net>
**
** Started on  Sat May 20 04:58:19 2017 Pierre Monge
** Last update Sat May 20 05:10:44 2017 Pierre Monge
*/

#ifndef MANAGE_CLIENT_H
# define MANAGE_CLIENT_H

# include "socket.h"

# define EFORK "Fork failed"
# define COMMAND_LEN_MAX 1024

/*
  manage_new_client:
    client_info (t_client_info):
      client info used to future handling of commands

      This function will also send a welcome message on
*/

int	manage_new_client(t_client_info client_info);

/*
  manage_registered_client:
    client_info (t_client_info):
      client info used to future handling of commands

      This function will also send a welcome message on
*/

int	manage_registered_client(t_client_info client_info);

/*
  manage_client_command:
    client_info (t_client_info *):
      client info
    command (const char *):
      command which one is get by read the remote socket.
      this means the command is an user command
*/
int	manage_client_command(t_client_info *client_info, const char *command);

#endif /* !MANAGE_CLIENT_H */
