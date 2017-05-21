##
## Makefile for FTP_SERVER in /Users/pierre/Epitech/PSU/FTP
## 
## Made by Pierre Monge
## Login   <pierre@epitech.net>
## 
## Started on  Sat May 20 04:47:31 2017 Pierre Monge
## Last update Sun May 21 05:49:23 2017 Pierre Monge
##

PROJECT := FTP_SERVER

OBJ_DIR := obj/

# General behavior

NAME_BIN := server

SRC_GENDIR := src/
OBJ_GENDIR := $(OBJ_DIR)src/

SRC_GEN = \
	main.c \
	socket.c \
	listen_for_client.c \
	\
	request/request_argument.c \
	\
	manage_client/manage_new_client.c \
	manage_client/manage_registered_client.c \
	manage_client/manage_client_command.c \
	\
	server_command/server_command.c \
	server_command/server_command_abor.c \
	server_command/server_command_acct.c \
	server_command/server_command_allo.c \
	server_command/server_command_appe.c \
	server_command/server_command_cdup.c \
	server_command/server_command_cwd.c \
	server_command/server_command_dele.c \
	server_command/server_command_help.c \
	server_command/server_command_list.c \
	server_command/server_command_mdk.c \
	server_command/server_command_mode.c \
	server_command/server_command_nlst.c \
	server_command/server_command_noop.c \
	server_command/server_command_pass.c \
	server_command/server_command_pasv.c \
	server_command/server_command_port.c \
	server_command/server_command_pwd.c \
	server_command/server_command_quit.c \
	server_command/server_command_rein.c \
	server_command/server_command_rest.c \
	server_command/server_command_retr.c \
	server_command/server_command_rmd.c \
	server_command/server_command_rnfr.c \
	server_command/server_command_rnto.c \
	server_command/server_command_site.c \
	server_command/server_command_smnt.c \
	server_command/server_command_stat.c \
	server_command/server_command_stor.c \
	server_command/server_command_stou.c \
	server_command/server_command_stru.c \
	server_command/server_command_syst.c \
	server_command/server_command_type.c \
	server_command/server_command_user.c

OBJ_GEN = $(addprefix $(OBJ_GENDIR), $(SRC_GEN:.c=.o))

# Utility

INCDIRS := -I./include -I./src -I./src/manage_client
INCDIRS += -I./src/server_command -I./src/request

CC = gcc

FLAGS = -W -Werror -Wextra -Wall
# if debug is activated
FLAGS += $(DEBUG)
FLAGS += -D _GNU_SOURCE

CFLAGS = $(FLAGS) $(INCDIRS)

RM		:= rm -rf

# Rules

all:
	@make --no-print-directory $(NAME_BIN)

# debug: FLAGS += -DDEBUG -g
debug: fclean
	@make --no-print-directory $(NAME_BIN) DEBUG='-DDEBUG -g'

$(OBJ_GENDIR)%.o: $(SRC_GENDIR)%.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS) $(ERRLOG)

$(NAME_BIN): $(NAME_LIB) $(OBJ_GEN)
	$(CC) -o $(NAME_BIN) $(OBJ_GEN) $(CFLAGS)

clean:
	@$(RM) $(LOGFILE)
	$(RM) $(OBJ_DIR)

fclean:	clean
	$(RM) $(NAME_BIN)

re: fclean all

.PHONY: debug
