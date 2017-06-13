#include "forFork.h"

void createProcessFork()
{
    printf("Create Process by Fork\n");
    pid_t pid = fork();
    int status; 
    if(pid == 0)
    {
	printf("Creating child process\n");
	sleep(2);
        exit(1);
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
