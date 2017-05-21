/*
** request.h for request_h in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.net>
**
** Started on  Sat May 20 08:04:17 2017 Pierre Monge
** Last update Sun May 21 06:13:12 2017 Pierre Monge
*/

#ifndef REQUEST_H
# define REQUEST_H

# include <stdio.h>

# define REQUEST_END "\r\n"

# define REQUEST_RESPONSE(fd, format, ...) \
  dprintf(fd, format""REQUEST_END, ##__VA_ARGS__)

/*
  request argument

  request argument is a minimal lib that provider some functions
  to parse and affect arguments on arguments passed with commands
*/

/*
  this function decompose argument request to multiple tokens
  and the other is to free them
*/
char	**request_parse_arguments(char *argument);
void	request_free_arguments(char **arguments);

/*
  this function basicly count argument of a char**
*/
int	request_count_arguments(char **arguments);

/*
  request response, code error and else
*/

# define SERVER_220 "220 (myFTP, v1.0)"
# define SERVER_221 "221 Service closing control connection."

# define SERVER_331 "331 User name okay, need password."

# define SERVER_421 "421 Service not available, closing control connection."

# define SERVER_500 "500 Syntax error, command unrecognized."
# define SERVER_502 "502 Command not implemented."
# define SERVER_530 "530 Not logged in."

#endif /* !REQUEST_H */
