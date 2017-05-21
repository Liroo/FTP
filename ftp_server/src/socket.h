/*
** socket.h for socket_h in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.net>
**
** Started on  Sat May 20 04:56:45 2017 Pierre Monge
** Last update Sun May 21 14:18:49 2017 Pierre Monge
*/

#ifndef SOCKET_H
# define SOCKET_H

# include <sys/types.h>
# include <sys/socket.h>
# include <stdbool.h>

/*
  error define for socket

  bind or listen is defined in the same macro pre processor
  because fuck the epitech coding style THANK YOU
*/
# define EINIT_SOCKET "Initialization of socket failed"
# define EINIT_SOCKET_PERROR "Initialization of socket failed"
# define WINIT_SOCKET_OPT_PERROR "Cannot configure correctly socket"
# define EBIND_OR_LISTEN_SOCKET_PERROR "Binding or listen socket failed"
# define ESOCKET_CLOSE "Socket failed to close"

/*
  Max client handle by server
*/
# define MAX_CLIENTS 1024

/*
  Prototype are defined in /etc/protocols
  The one who are using provide TCP implementation

  As long as TCP existed, I assume there is not
  possible that some distribution didn't implement
  TCP protocol
*/
# define PROTOTYPE_NAME "TCP"

/*
  typedef struct s_client_info t_client_info:
    fd (int):
      fd of the given client

    addr (struct sockaddr):
    addrelen (socklen_t):
      opaque info about client
*/
typedef			struct s_client_info
{
  int			fd;
  struct sockaddr	addr;
  socklen_t		addrlen;

  char			root_dir[4096];
  char			cwd[4096];
  char			*username;
  bool			isAuthenticated;

}			t_client_info;

/*
  open_socket:
    port (unsigned int):
      Port numbers are 16 bits integers. Unsigned.
      So that's not possible to get an int
      Anyway, this one will be cast in unsigned.


  Open a socket in TCP protocol and bind it to the port
*/
int	socket_open(unsigned int port);

/*
  socket_close:
    socket_fd (int):
      file descriptor that is close
      If there is an open socket during the program,
      this one should be close by using this function

  Close the file descriptor associed to socket
*/
int	socket_close(int socket_fd);

#endif /* !SOCKET */
