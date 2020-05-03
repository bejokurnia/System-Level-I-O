// **
#include "csapp.h"

int main(int argc, char **argv)
{
  int n;
  rio_t rio;
  char buf[MAXLINE];

  if (argc != 1) {
    int fd = open(argv[1], O_RDONLY, 0);
    if (fd == -1) {
      fprintf(stderr, "Buka: %s\n", strerror(errno));
      return EXIT_FAILURE;
    }
    int stat = dup2(fd, STDIN_FILENO);
    if (stat == -1) {
      fprintf(stderr, "dup2: %s\n", strerror(errno));
      return EXIT_FAILURE;
    }
  }

  Rio_readinitb(&rio, STDIN_FILENO);
  while ((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0)
    Rio_writen(STDOUT_FILENO, buf, n);
}
