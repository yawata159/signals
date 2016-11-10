#include <stdlib.h>
#include <stdio.h>

#include <fcntl.h>
#include <sys/types.h>

#include <unistd.h>
#include <signal.h>

static void sighandler(int signo) {
  if (signo == SIGINT) {
    int fd = open("log", O_RDWR | O_CREAT | O_APPEND, 0644);
    char message[50] = "Program Exited due to SIGINT\n";
    write(fd, message, sizeof(message));
    close(fd);
    exit(0);
  }
  else if (signo == SIGUSR1) {
    printf("Parent Process PID: %d\n", getppid());
    return;
  }
  return;
}

int main() {
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  
  while (1) {
    printf("The pid of this process is %d\n", getpid());
    sleep(1);
  }
  return 0;
}
