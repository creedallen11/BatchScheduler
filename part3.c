#include <stdio.h>
#include <sys/types.h> // for pid_t
#include <signal.h>
#include <errno.h>
#include <unistd.h> // for fork
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/*
Example program input \"batch-shell> ./program1 ../program2 \" will run program1 in the 
current directory and program2 in the parent directory. The sheduler can also execute linux commands
with no arguments or flags. Ex. 'ls'. 
*/
int main(void) {
	char str[BUFSIZ]; // buffer to hold each line of user input.                                                                                                                                                                        

	printf("Batch Scheduling Shell. Enter 'quit' to exit. For run examples see README.txt file.\n");
	while (1) { 
		printf("batch-shell> ");                                                                                                                                                                
		fgets(str, sizeof(str), stdin);                                                                                                                                                                             
  		//fgets(buffer, sizeof(buffer), stdin)
  		char *token; 
  		char *whiteSpace = " \t\n\f\r";
 
  		token = strtok(str, whiteSpace); /* store the next program */
  		
  		while (token != NULL) /* process line of input */
  		{	
  			if (strcmp(token, "quit") == 0) return 0;

  			pid_t pid;
  			pid = fork();

  			if (pid == 0) { /* Child Process */
 				char *args[] = {token, 0};
 				printf("Child process %d is executing %s.\n", getpid(), token);
 				execvp(token, args);
 				printf("ERRNO occured running %s, check the path and program name.\n", token);
				exit(errno); 
 			}
 			else { /* Parent Process */
 				waitpid(pid, 0, 0);
 				printf("Child completed on %s...\n", token);
 				token = strtok(NULL, whiteSpace); /* get the next user program. */
 			}
  		}
  	}                                                                                                                                                           
}
