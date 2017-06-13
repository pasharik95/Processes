#include "forExec.h"

void createProcessExec()
{
    pid_t pid = fork();
    int status; 
    if(pid == 0)
    {
	printf("Creating process by exec (echo HomeTask1)\n");
        execl("/bin/bash", "bash", "-c", "echo HomeTask1", (char *) 0);
    }
    else if(pid > 0)
    {
        printf("Waiting child proccess\n");
	
	if((pid = waitpid(pid, &status, 0)) && WIFEXITED(status))
        {
            printf("Child process is compated\n");
        }
    }
    else
        printf("Error  : cannot create fork process!!!\n");
}
