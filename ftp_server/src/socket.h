/*
** socket.h for socket_h in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.net>
**
** Started on  Sat May 20 04:56:45 2017 Pierre Monge
** Last update Sun May 21 22:52:07 2017 Pierre Monge
*/

#ifndef SOCKET_H
# define SOCKET_H

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <stdbool.h>

/*
**  error define for socket
**
**  bind or listen is defined in the same macro pre processor
**  because fuck the epitech coding style THANK YOU
*/
# define EINIT_SOCKET "Initialization of socket failed"
# define EINIT_SOCKET_PERROR "Initialization of socket failed"
# define WINIT_SOCKET_OPT_PERROR "Cannot configure correctly socket"
# define EBIND_OR_LISTEN_SOCKET_PERROR "Binding or listen socket failed"
# define ESOCKET_CLOSE "Socket failed to close"

/*
**  Max client handle by server
*/
# define MAX_CLIENTS 1024

/*
**  Prototype are defined in /etc/protocols
**  The one who are using provide TCP implementation
**
**  As long as TCP existed, I assume there is not
**  possible that some distribution didn't implement
**  TCP protocol
*/
# define PROTOTYPE_NAME "TCP"

/*
**  typedef struct s_client_info t_client_info:
**    fd (int):
**      fd of the given client
**
**    addr (struct sockaddr):
**    addrelen (socklen_t):
**      opaque info about client
*/
typedef enum   	e_ftp_mode {
  DEFAULT,
  PASSIV,
  ACTIV,
}		t_ftp_mode;

typedef			struct s_socket_info
{
  int			fd;
  struct sockaddr_in	addr;
  socklen_t		addrlen;
}			t_socket_info;

typedef			struct s_client_info
{
  t_socket_info		client;
  t_socket_info		server;
  t_socket_info		control;
  t_socket_info		data;

  bool			data_in_use;

  t_ftp_mode		mode;
  char			root_dir[4096];
  char			cwd[4096];
  char			*username;
  bool			is_authenticated;

}			t_client_info;

/*
**  open_socket:
**    port (unsigned int):
**      Port numbers are 16 bits integers. Unsigned.
**      So that's not possible to get an int
**      Anyway, this one will be cast in unsigned.
**
**
**  Open a socket in TCP protocol and bind it to the port
*/
int	socket_open(t_socket_info *socket_info, unsigned int port);

/*
**  socket_close:
**    socket_fd (int):
**      file descriptor that is close
**      If there is an open socket during the program,
**      this one should be close by using this function
**
**  Close the file descriptor associed to socket
*/
int	socket_close(int socket_fd);

/*
**  socket_get_ip (t_socket_info)
**  get ip of socket
*/
char		*socket_get_ip(t_socket_info socket_info);

#endif /* !SOCKET */
