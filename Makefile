##
## Makefile for FTP in /Users/pierre/Epitech/PSU/FTP
## 
## Made by Pierre Monge
## Login   <pierre@epitech.net>
## 
## Started on  Sat May 20 04:46:11 2017 Pierre Monge
## Last update Sat May 20 04:46:21 2017 Pierre Monge
##

PROJECT := FTP

SERVER = ./ftp_server
BUILD_SCRIPT = ./install.sh

.NOTPARALLEL:

all:
	@make --no-print-directory -C $(SERVER)
	@$(BUILD_SCRIPT) install `pwd`

debug:
	@make --no-print-directory -C $(SERVER) debug

clean:
	@make --no-print-directory -C $(SERVER) clean

fclean:
	@make --no-print-directory -C $(SERVER) fclean
	@$(BUILD_SCRIPT) uninstall `pwd`

re: fclean all

.PHONY: debug
