#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
  pid_t pid;
  int status;
  pid = fork();
  if(pid == -1){
    printf("Problem, NO CHILD!\n");
    return 1;
  }
  else if(pid == 0){/*im a child!*/
    pid = fork();
    if(pid == 0){
      sleep(10);
      printf("Grandchild process with process ID %d has completed.\n", getpid());
    }
    else{
      waitpid(pid, &status, 0);
      printf("Child process with process ID %d has completed.\n", getpid());
    }
    return 0;
  }
  else{
    waitpid(pid, &status, 0);
    printf("Parent process with process ID %d has finished.\n",getpid());
    return 0;
  }
}
