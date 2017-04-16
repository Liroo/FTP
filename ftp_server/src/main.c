#include <stdlib.h>

#include "socket.h"

int main(int argc __attribute__((unused)), char *argv[]) {
  int socket_fd;

  if ((socket_fd = socket_open(atoi(argv[1]))) == -1) {
    return (1);
  }
  if (socket_close(socket_fd) == -1) {
    return (1);
  }

  return (0);
}
