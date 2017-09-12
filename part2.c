#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>

int main(){
  int pid = 0;
  int error;
  int result;
  result = 0;
  error = 0;
  printf("Please enter a process ID to KILL!\n-:");
  scanf("%d", &pid);
  printf("You entered %d!\n", pid);
  if(pid > 0){
    result = kill(pid, SIGKILL);
    if(result == -1){
      error = errno;
      switch (error){
        case EPERM:
          printf("You do not have permission to kill process %d.\n", pid);
          break;
        case ESRCH:
          printf("Process %d does not exist.\n", pid);
          break;
      }
    }
  }
  else{
    printf("Process ID must be a positive integer.");
  }
  return 0;
}
