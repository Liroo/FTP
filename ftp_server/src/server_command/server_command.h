/*
** commands.h<2> for commands_h in /Users/pierre/Epitech/PSU/FTP
**
** Made by Pierre Monge
** Login   <pierre@epitech.net>
**
** Started on  Sat May 20 04:57:33 2017 Pierre Monge
** Last update Sun May 21 22:51:21 2017 Pierre Monge
*/

#ifndef COMMANDS_H
# define COMMANDS_H

# include "socket.h"

/*
**  command alias to real commands
**
**  Real commands are described bellow the structure
**  according to prototypes
*/
typedef		struct s_command_alias {
  char		*title;
  char		*help;
  int		(*exec)(t_client_info *client_info, char *argument);
}		t_command_alias;

/*
**  definition of commands in server_command.c
**
**  I use global because function is maximum 25 lines
**  and I get 33 commands to be agree with rfc...
**
**  This is no because I wanted to simplify my life, the only
**  purpose of such this things is to respect the codding style
**  and to be zen when I read my code...
*/
extern t_command_alias	server_commands[34];

/*
**  server_get_commands:
**    get all commands alias
*/
t_command_alias	*server_get_commands();

int	server_remote_connection(t_client_info *client_info);
char	*server_get_real_path(char *path, char *root);

/*
**  I rewrite some part of the RFC 959 according to this project
**  to create a minimal doc about server commands.
**
**  Each commands will not be fully implemented but they will be
**  fully prototyped.
**
**  Some text refer to the RFC, remember that the RFC reference is
**  at website: https://www.ietf.org/rfc/rfc959.txt
**
**  -- Pierre
*/

/*
**  The following commands specify access control identifiers
*/

/*
**         USER NAME (USER)
**	 USER <SP> <username> <CRLF>
**
**            The argument field is a Telnet string identifying the user.
**            The user identification is that which is required by the
**            server for access to its file system.  This command will
**            normally be the first command transmitted by the user after
**            the control connections are made (some servers may require
**            this).  Additional identification information in the form of
**            a password and/or an account command may also be required by
**            some servers.  Servers may allow a new USER command to be
**            entered at any point in order to change the access control
**            and/or accounting information.  This has the effect of
**            flushing any user, password, and account information already
**            supplied and beginning the login sequence again.  All
**            transfer parameters are unchanged and any file transfer in
**            progress is completed under the old access control
**            parameters.
*/
int	server_command_user(t_client_info *client_info, char *argument);
# define HELP_USER "USER <SP> <username> <CRLF>"

/*
**         PASSWORD (PASS)
**	 PASS <SP> <password> <CRLF>
**
**            The argument field is a Telnet string specifying the user's
**            password.  This command must be immediately preceded by the
**            user name command, and, for some sites, completes the user's
**            identification for access control.  Since password
**            information is quite sensitive, it is desirable in general
**            to "mask" it or suppress typeout.  It appears that the
**            server has no foolproof way to achieve this.  It is
**            therefore the responsibility of the user-FTP process to hide
**            the sensitive password information.
*/
int	server_command_pass(t_client_info *client_info, char *argument);
# define HELP_PASS "PASS <SP> <password> <CRLF>"

/*
**         ACCOUNT (ACCT)
**	 ACCT <SP> <account-information> <CRLF>
**
**            The argument field is a Telnet string identifying the user's
**            account.  The command is not necessarily related to the USER
**            command, as some sites may require an account for login and
**            others only for specific access, such as storing files.  In
**            the latter case the command may arrive at any time.
**
**            There are reply codes to differentiate these cases for the
**            automation: when account information is required for login,
**            the response to a successful PASSword command is reply code
**            332.  On the other hand, if account information is NOT
**            required for login, the reply to a successful PASSword
**            command is 230; and if the account information is needed for
**            a command issued later in the dialogue, the server should
**            return a 332 or 532 reply depending on whether it stores
**            (pending receipt of the ACCounT command) or discards the
**            command, respectively.
*/
int	server_command_acct(t_client_info *client_info, char *argument);
# define HELP_ACCT "ACCT <SP> <account-information> <CRLF>"

/*
**         CHANGE WORKING DIRECTORY (CWD)
**	 CWD  <SP> <pathname> <CRLF>
**
**            This command allows the user to work with a different
**            directory or dataset for file storage or retrieval without
**            altering his login or accounting information.  Transfer
**            parameters are similarly unchanged.  The argument is a
**            pathname specifying a directory or other system dependent
**            file group designator.
*/
int	server_command_cwd(t_client_info *client_info, char *argument);
# define HELP_CWD "CWD  <SP> <pathname> <CRLF>"

/*
**         CHANGE TO PARENT DIRECTORY (CDUP)
**	 CDUP <CRLF>
**
**            This command is a special case of CWD, and is included to
**            simplify the implementation of programs for transferring
**            directory trees between operating systems having different
**            syntaxes for naming the parent directory.  The reply codes
**            shall be identical to the reply codes of CWD.  See
**            Appendix II for further details.
**
*/
int	server_command_cdup(t_client_info *client_info, char *argument);
# define HELP_CDUP "CDUP <CRLF>"

/*
**         STRUCTURE MOUNT (SMNT)
**	 SMNT <SP> <pathname> <CRLF>
**
**            This command allows the user to mount a different file
**            system data structure without altering his login or
**            accounting information.  Transfer parameters are similarly
**            unchanged.  The argument is a pathname specifying a
**            directory or other system dependent file group designator.
*/
int	server_command_smnt(t_client_info *client_info, char *argument);
# define HELP_SMNT "SMNT <SP> <pathname> <CRLF>"

/*
**
**         REINITIALIZE (REIN)
**	 REIN <CRLF>
**
**            This command terminates a USER, flushing all I/O and account
**            information, except to allow any transfer in progress to be
**            completed.  All parameters are reset to the default settings
**            and the control connection is left open.  This is identical
**            to the state in which a user finds himself immediately after
**            the control connection is opened.  A USER command may be
**            expected to follow.
**
*/
int	server_command_rein(t_client_info *client_info, char *argument);
# define HELP_REIN "REIN <CRLF>"


/*
**         LOGOUT (QUIT)
**	 QUIT <CRLF>
**
**
**            This command terminates a USER and if file transfer is not
**            in progress, the server closes the control connection.  If
**            file transfer is in progress, the connection will remain
**            open for result response and the server will then close it.
**            If the user-process is transferring files for several USERs
**            but does not wish to close and then reopen connections for
**            each, then the REIN command should be used instead of QUIT.
**
**            An unexpected close on the control connection will cause the
**            server to take the effective action of an abort (ABOR) and a
**            logout (QUIT).
*/
int	server_command_quit(t_client_info *client_info, char *argument);
# define HELP_QUIT "QUIT <CRLF>"


/*
**  The following commands specify data transfer parameters
*/

/*
**         DATA PORT (PORT)
**	 PORT <SP> <host-port> <CRLF>
**
**            The argument is a HOST-PORT specification for the data port
**            to be used in data connection.  There are defaults for both
**            the user and server data ports, and under normal
**            circumstances this command and its reply are not needed.  If
**            this command is used, the argument is the concatenation of a
**            32-bit internet host address and a 16-bit TCP port address.
**            This address information is broken into 8-bit fields and the
**            value of each field is transmitted as a decimal number (in
**            character string representation).  The fields are separated
**            by commas.  A port command would be:
**
**               PORT h1,h2,h3,h4,p1,p2
**
**            where h1 is the high order 8 bits of the internet host
**            address.
*/
int	server_command_port(t_client_info *client_info, char *argument);
# define HELP_PORT "PORT <SP> <host-port> <CRLF>"

/*
**         PASSIVE (PASV)
**	 PASV <CRLF>
**
**            This command requests the server-DTP to "listen" on a data
**            port (which is not its default data port) and to wait for a
**            connection rather than initiate one upon receipt of a
**            transfer command.  The response to this command includes the
**            host and port address this server is listening on.
*/
int	server_command_pasv(t_client_info *client_info, char *argument);
# define HELP_PASV "PASV <CRLF>"

/*
**         REPRESENTATION TYPE (TYPE)
**	 TYPE <SP> <type-code> <CRLF>
**
**            The argument specifies the representation type as described
**            in the Section on Data Representation and Storage.  Several
**            types take a second parameter.  The first parameter is
**            denoted by a single Telnet character, as is the second
**            Format parameter for ASCII and EBCDIC; the second parameter
**            for local byte is a decimal integer to indicate Bytesize.
**            The parameters are separated by a <SP> (Space, ASCII code
**            32).
**
**            The following codes are assigned for type:
**
**                         \    /
**               A - ASCII |    | N - Non-print
**                         |-><-| T - Telnet format effectors
**               E - EBCDIC|    | C - Carriage Control (ASA)
**                         /    \
**               I - Image
**
**               L <byte size> - Local byte Byte size
**
**            The default representation type is ASCII Non-print.  If the
**            Format parameter is changed, and later just the first
**            argument is changed, Format then returns to the Non-print
**            default.
*/
int	server_command_type(t_client_info *client_info, char *argument);
# define HELP_TYPE "TYPE <SP> <type-code> <CRLF>"

/*
**         FILE STRUCTURE (STRU)
**	 STRU <SP> <structure-code> <CRLF>
**
**            The argument is a single Telnet character code specifying
**            file structure described in the Section on Data
**            Representation and Storage.
**
**            The following codes are assigned for structure:
**
**               F - File (no record structure)
**               R - Record structure
**               P - Page structure
**
**            The default structure is File.
*/
int	server_command_stru(t_client_info *client_info, char *argument);
# define HELP_STRU "STRU <SP> <structure-code> <CRLF>"

/*
**         TRANSFER MODE (MODE)
**	 MODE <SP> <mode-code> <CRLF>
**
**            The argument is a single Telnet character code specifying
**            the data transfer modes described in the Section on
**            Transmission Modes.
**
**            The following codes are assigned for transfer modes:
**
**               S - Stream
**               B - Block
**               C - Compressed
**
**            The default transfer mode is Stream.
*/
int	server_command_mode(t_client_info *client_info, char *argument);
# define HELP_MODE "MODE <SP> <mode-code> <CRLF>"

/*
**  The following commands specify FTP service requests
*/

/*
**         RETRIEVE (RETR)
**	 RETR <SP> <pathname> <CRLF>
**
**            This command causes the server-DTP to transfer a copy of the
**            file, specified in the pathname, to the server- or user-DTP
**            at the other end of the data connection.  The status and
**            contents of the file at the server site shall be unaffected.
*/
int	server_command_retr(t_client_info *client_info, char *argument);
# define HELP_RETR "RETR <SP> <pathname> <CRLF>"

/*
**         STORE (STOR)
**	 STOR <SP> <pathname> <CRLF>
**
**            This command causes the server-DTP to accept the data
**            transferred via the data connection and to store the data as
**            a file at the server site.  If the file specified in the
**            pathname exists at the server site, then its contents shall
**            be replaced by the data being transferred.  A new file is
**            created at the server site if the file specified in the
**            pathname does not already exist.
*/
int	server_command_stor(t_client_info *client_info, char *argument);
# define HELP_STOR "STOR <SP> <pathname> <CRLF>"

/*
**         STORE UNIQUE (STOU)
**	 STOU <CRLF>
**
**            This command behaves like STOR except that the resultant
**            file is to be created in the current directory under a name
**            unique to that directory.  The 250 Transfer Started response
**            must include the name generated.
*/
int	server_command_stou(t_client_info *client_info, char *argument);
# define HELP_STOU "STOU <CRLF>"

/*
**         APPEND (with create) (APPE)
**	 APPE <SP> <pathname> <CRLF>
**
**            This command causes the server-DTP to accept the data
**            transferred via the data connection and to store the data in
**            a file at the server site.  If the file specified in the
**            pathname exists at the server site, then the data shall be
**            appended to that file; otherwise the file specified in the
**            pathname shall be created at the server site.
*/
int	server_command_appe(t_client_info *client_info, char *argument);
# define HELP_APPE "APPE <SP> <pathname> <CRLF>"

/*
**
**         ALLOCATE (ALLO)
**	 ALLO <SP> <decimal-integer>
**                [<SP> R <SP> <decimal-integer>] <CRLF>
**
**            This command may be required by some servers to reserve
**            sufficient storage to accommodate the new file to be
**            transferred.  The argument shall be a decimal integer
**            representing the number of bytes (using the logical byte
**            size) of storage to be reserved for the file.  For files
**            sent with record or page structure a maximum record or page
**            size (in logical bytes) might also be necessary; this is
**            indicated by a decimal integer in a second argument field of
**            the command.  This second argument is optional, but when
**            present should be separated from the first by the three
**            Telnet characters <SP> R <SP>.  This command shall be
**            followed by a STORe or APPEnd command.  The ALLO command
**            should be treated as a NOOP (no operation) by those servers
**            which do not require that the maximum size of the file be
**            declared beforehand, and those servers interested in only
**            the maximum record or page size should accept a dummy value
**            in the first argument and ignore it.
*/
int	server_command_allo(t_client_info *client_info, char *argument);
# define HELP_ALLO "ALLO <SP> <decimal-integer>"

/*
**         RESTART (REST)
**	 REST <SP> <marker> <CRLF>
**
**            The argument field represents the server marker at which
**            file transfer is to be restarted.  This command does not
**            cause file transfer but skips over the file to the specified
**            data checkpoint.  This command shall be immediately followed
**            by the appropriate FTP service command which shall cause
**            file transfer to resume.
*/
int	server_command_rest(t_client_info *client_info, char *argument);
# define HELP_REST "REST <SP> <marker> <CRLF>"

/*
**         RENAME FROM (RNFR)
**	 RNFR <SP> <pathname> <CRLF>
**
**            This command specifies the old pathname of the file which is
**            to be renamed.  This command must be immediately followed by
**            a "rename to" command specifying the new file pathname.
*/
int	server_command_rnfr(t_client_info *client_info, char *argument);
# define HELP_RNFR "RNFR <SP> <pathname> <CRLF>"

/*
**         RENAME TO (RNTO)
**	 RNTO <SP> <pathname> <CRLF>
**
**            This command specifies the new pathname of the file
**            specified in the immediately preceding "rename from"
**            command.  Together the two commands cause a file to be
**            renamed.
*/
int	server_command_rnto(t_client_info *client_info, char *argument);
# define HELP_RNTO "RNTO <SP> <pathname> <CRLF>"

/*
**
**         ABORT (ABOR)
**	 ABOR <CRLF>
**
**            This command tells the server to abort the previous FTP
**            service command and any associated transfer of data.  The
**            abort command may require "special action", as discussed in
**            the Section on FTP Commands, to force recognition by the
**            server.  No action is to be taken if the previous command
**            has been completed (including data transfer).  The control
**            connection is not to be closed by the server, but the data
**            connection must be closed.
**
**            There are two cases for the server upon receipt of this
**            command: (1) the FTP service command was already completed,
**            or (2) the FTP service command is still in progress.
**               In the first case, the server closes the data connection
**               (if it is open) and responds with a 226 reply, indicating
**               that the abort command was successfully processed.
**
**               In the second case, the server aborts the FTP service in
**               progress and closes the data connection, returning a 426
**               reply to indicate that the service request terminated
**               abnormally.  The server then sends a 226 reply,
**               indicating that the abort command was successfully
**               processed.
**
*/
int	server_command_abor(t_client_info *client_info, char *argument);
# define HELP_ABOR "ABOR <CRLF>"

/*
**         DELETE (DELE)
**	 DELE <SP> <pathname> <CRLF>
**
**            This command causes the file specified in the pathname to be
**            deleted at the server site.  If an extra level of protection
**            is desired (such as the query, "Do you really wish to
**            delete?"), it should be provided by the user-FTP process.
*/
int	server_command_dele(t_client_info *client_info, char *argument);
# define HELP_DELE "DELE <SP> <pathname> <CRLF>"

/*
**         REMOVE DIRECTORY (RMD)
**	 RMD  <SP> <pathname> <CRLF>
**
**            This command causes the directory specified in the pathname
**            to be removed as a directory (if the pathname is absolute)
**            or as a subdirectory of the current working directory (if
**            the pathname is relative).  See Appendix II.
*/
int	server_command_rmd(t_client_info *client_info, char *argument);
# define HELP_RMD "RMD  <SP> <pathname> <CRLF>"

/*
**         MAKE DIRECTORY (MKD)
**	 MKD  <SP> <pathname> <CRLF>
**
**            This command causes the directory specified in the pathname
**            to be created as a directory (if the pathname is absolute)
**            or as a subdirectory of the current working directory (if
**            the pathname is relative).  See Appendix II.
*/
int	server_command_mdk(t_client_info *client_info, char *argument);
# define HELP_MDK "MKD  <SP> <pathname> <CRLF>"

/*
**         PRINT WORKING DIRECTORY (PWD)
**	 PWD  <CRLF>
**
**            This command causes the name of the current working
**            directory to be returned in the reply.  See Appendix II.
*/
int	server_command_pwd(t_client_info *client_info, char *argument);
# define HELP_PWD "PWD  <CRLF>"

/*
**         LIST (LIST)
**	 LIST [<SP> <pathname>] <CRLF>
**
**            This command causes a list to be sent from the server to the
**            passive DTP.  If the pathname specifies a directory or other
**            group of files, the server should transfer a list of files
**            in the specified directory.  If the pathname specifies a
**            file then the server should send current information on the
**            file.  A null argument implies the user's current working or
**            default directory.  The data transfer is over the data
**            connection in type ASCII or type EBCDIC.  (The user must
**            ensure that the TYPE is appropriately ASCII or EBCDIC).
**            Since the information on a file may vary widely from system
**            to system, this information may be hard to use automatically
**            in a program, but may be quite useful to a human user.
**
*/
int	server_command_list(t_client_info *client_info, char *argument);
# define HELP_LIST "LIST [<SP> <pathname>] <CRLF>"

/*
**
**         NAME LIST (NLST)
**	 NLST [<SP> <pathname>] <CRLF>
**
**            This command causes a directory listing to be sent from
**            server to user site.  The pathname should specify a
**            directory or other system-specific file group descriptor; a
**            null argument implies the current directory.  The server
**            will return a stream of names of files and no other
**            information.  The data will be transferred in ASCII or
**            EBCDIC type over the data connection as valid pathname
**            strings separated by <CRLF> or <NL>.  (Again the user must
**            ensure that the TYPE is correct.)  This command is intended
**            to return information that can be used by a program to
**            further process the files automatically.  For example, in
**            the implementation of a "multiple get" function.
*/
int	server_command_nlst(t_client_info *client_info, char *argument);
# define HELP_NLST "NLST [<SP> <pathname>] <CRLF>"

/*
**
**         SITE PARAMETERS (SITE)
**	 SITE <SP> <string> <CRLF>
**
**            This command is used by the server to provide services
**            specific to his system that are essential to file transfer
**            but not sufficiently universal to be included as commands in
**            the protocol.  The nature of these services and the
**            specification of their syntax can be stated in a reply to
**            the HELP SITE command.
*/
int	server_command_site(t_client_info *client_info, char *argument);
# define HELP_SITE "SITE <SP> <string> <CRLF>"

/*
**         SYSTEM (SYST)
**	 SYST <CRLF>
**
**            This command is used to find out the type of operating
**            system at the server.  The reply shall have as its first
**            word one of the system names listed in the current version
**            of the Assigned Numbers document [4].
*/
int	server_command_syst(t_client_info *client_info, char *argument);
# define HELP_SYST "SYST <CRLF>"

/*
**         STATUS (STAT)
**	 STAT [<SP> <pathname>] <CRLF>
**
**            This command shall cause a status response to be sent over
**            the control connection in the form of a reply.  The command
**            may be sent during a file transfer (along with the Telnet IP
**            and Synch signals--see the Section on FTP Commands) in which
**            case the server will respond with the status of the
**            operation in progress, or it may be sent between file
**            transfers.  In the latter case, the command may have an
**            argument field.  If the argument is a pathname, the command
**            is analogous to the "list" command except that data shall be
**            transferred over the control connection.  If a partial
**            pathname is given, the server may respond with a list of
**            file names or attributes associated with that specification.
**            If no argument is given, the server should return general
**            status information about the server FTP process.  This
**            should include current values of all transfer parameters and
**            the status of connections.
*/
int	server_command_stat(t_client_info *client_info, char *argument);
# define HELP_STAT "STAT [<SP> <pathname>] <CRLF>"

/*
**         HELP (HELP)
**	 HELP [<SP> <string>] <CRLF>
**
**            This command shall cause the server to send helpful
**            information regarding its implementation status over the
**            control connection to the user.  The command may take an
**            argument (e.g., any command name) and return more specific
**            information as a response.  The reply is type 211 or 214.
**            It is suggested that HELP be allowed before entering a USER
**            command. The server may use this reply to specify
**            site-dependent parameters, e.g., in response to HELP SITE.
*/
int	server_command_help(t_client_info *client_info, char *argument);
# define HELP_HELP "HELP [<SP> <string>] <CRLF>"

/*
**         NOOP (NOOP)
**	 NOOP <CRLF>
**
**            This command does not affect any parameters or previously
**            entered commands. It specifies no action other than that the
**            server send an OK reply.
*/
int	server_command_noop(t_client_info *client_info, char *argument);
# define HELP_NOOP "NOOP <CRLF>"

#endif /* !COMMANDS_H */
