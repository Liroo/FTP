PROJECT := FTP

CLIENT = ./ftp_client
SERVER = ./ftp_server
BUILD_SCRIPT = ./install.sh

.NOTPARALLEL:

all:
	@make --no-print-directory -C $(CLIENT)
	@make --no-print-directory -C $(SERVER)
	@$(BUILD_SCRIPT) install `pwd`

debug:
	@make --no-print-directory -C $(CLIENT) debug
	@make --no-print-directory -C $(SERVER) debug

clean:
	@make --no-print-directory -C $(CLIENT) clean
	@make --no-print-directory -C $(SERVER) clean

fclean:
	@make --no-print-directory -C $(CLIENT) fclean
	@make --no-print-directory -C $(SERVER) fclean
	@$(BUILD_SCRIPT) uninstall `pwd`

re: fclean all

.PHONY: debug
