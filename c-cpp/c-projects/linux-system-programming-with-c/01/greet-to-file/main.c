#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main() {
  int fd;
  // Typically system calls return -1 on failure
  // Test Assign Perform idiom very common in C code
  if ((fd = open("foo", O_WRONLY | O_CREAT, 0644)) < 0) {
    // Global error variable errno that is seti to specific error numbers.

    printf("error number %d\n", errno);
    perror("foo");
    exit(1);
  }
  write(fd, "hello world", 11);
  close(fd);
}
