/*
** server_command_retr.c for retr in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.client_info>
**
** Started on  Sun May 21 03:57:45 2017 Pierre Monge
** Last update Sun May 21 22:35:51 2017 Pierre Monge
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


#include "server_command.h"
#include "request.h"

/* int		server_command_retr_exec(t_client_info *client_info, char *argument) */
/* { */
/*   char		*path; */
/*   int		fd; */
/*   char		*buf; */
/*   int		ret; */
/*   struct stat	st; */

/*   path = server_get_real_path(argument, client_info->root_dir); */
/*   printf("%s\n", path); */
/*   fstat(client_info->control.fd, &st); */
/*   buf = malloc(st.st_size + 1); */
/*   if (!buf) */
/*     return (-1); */
/*   if ((fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0755)) != -1) */
/*     { */
/*       printf("%ld\n", st.st_size); */
/*       ret = read(client_info->control.fd, buf, st.st_size); */
/*       printf("%s\n", buf); */
/*       dprintf(fd, "%s\n", buf); */
/*       buf[ret] = 0; */
/*     } */
/*   free(buf); */
/*   close(fd); */
/*   return (0); */
/* } */

/* static int	server_command_retr_close(t_client_info *client_info) */
/* { */
/*   if (client_info->mode == DEFAULT) */
/*     return (0); */
/*   if (client_info->mode == PASSIV && socket_close(client_info->data.fd) == -1) */
/*     return (-1); */
/*   if (socket_close(client_info->control.fd)) */
/*     return (-1); */
/*   return (0); */
/* } */

int	server_command_retr(t_client_info *client_info, char *argument)
{
  if (!client_info->is_authenticated)
    {
      REQUEST_RESPONSE(client_info->client.fd, SERVER_530);
      return (0);
    }
  REQUEST_RESPONSE(client_info->client.fd, SERVER_502);
  (void)argument;
  return (0);
}
