/*
** request.h for request_h in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.net>
**
** Started on  Sat May 20 08:04:17 2017 Pierre Monge
** Last update Sun May 21 22:52:28 2017 Pierre Monge
*/

#ifndef REQUEST_H
# define REQUEST_H

# include <stdio.h>

# define REQUEST_DELIMITER ' '
# define REQUEST_DELIMITER_PTR " "
# define REQUEST_L "\n"
# define REQUEST_END "\r\n"

# define DB_USERNAME "anonymous"
# define DB_PASS ""

# define REQUEST_RESPONSE(fd, format, ...) \
  dprintf(fd, format""REQUEST_END, ##__VA_ARGS__)

# define REQUEST_RESPONSE_S(fd, format, ...) \
  dprintf(fd, format, ##__VA_ARGS__)

# define REQUEST_RESPONSE_L(fd, format, ...) \
  dprintf(fd, format""REQUEST_L, ##__VA_ARGS__)

# define SINGLE_STRING "%s"
/*
**  request argument
**
**  request argument is a minimal lib that provider some functions
**  to parse and affect arguments on arguments passed with commands
*/

/*
**  this function decompose argument request to multiple tokens
**  and the other is to free them
*/
char	**request_parse_arguments(char *argument);
char	**request_parse_arguments_delimiter(char *argument, char delimiter);
void	request_free_arguments(char **arguments);

/*
**  this function basicly count argument of a char**
*/
int	request_count_arguments(char **arguments);

/*
**  request response, utils
*/
# define SERVER_HELP_FULL "Server recognize these commands:"

/*
**  request response, code error and else
*/

# define SERVER_150 "150 File status okay; about to open data connection."

# define SERVER_200 "200 Command okay."
# define SERVER_211 "211 System status, or system help reply."
# define SERVER_214 "214 Help message."
# define SERVER_220 "220 (myFTP, v1.0)"
# define SERVER_221 "221 Service closing control connection."
# define SERVER_226 "226 Closing data connection."
# define SERVER_227 "227 Entering Passive Mode (%s,%s,%s,%s,%d,%d)."
# define SERVER_230 "230 User logged in, proceed."
# define SERVER_250 "250 Requested file action okay, completed."
# define SERVER_257 "257 \"%s\" created."

# define SERVER_331 "331 User name okay, need password."

# define SERVER_421 "421 Service not available, closing control connection."
# define SERVER_425 "425 Can't open data connection."

# define SERVER_500 "500 Syntax error, command unrecognized."
# define SERVER_502 "502 Command not implemented."
# define SERVER_503 "503 Bad sequence of commands."
# define SERVER_530 "530 Not logged in."
# define SERVER_550 "550 Requested action not taken."

#endif /* !REQUEST_H */
