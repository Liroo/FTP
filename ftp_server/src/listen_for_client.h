/*
** listen_for_client.h for list_for_client_h in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.net>
**
** Started on  Sat May 20 04:57:04 2017 Pierre Monge
** Last update Sun May 21 12:19:02 2017 Pierre Monge
*/

#ifndef LISTEN_FOR_CLIENT
# define LISTEN_FOR_CLIENT

# define USAGE(arg) printf("%s port root_path\n", arg)

# define EACCEPT_CLIENT "Client socket failed to connect"

/*
  listen_for_client:
    socket_fd (int):
      fd of the socket server

  Listen for all clients
  They will connect via accept() function
  This function is basicly an infinite loop which can be
  stop by ctrl-C
*/
int	listen_for_client(int socket_fd, char *cwd);

#endif /* !LISTEN_FOR_CLIENT */
