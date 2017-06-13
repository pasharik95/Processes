#include "all.h"

int main(void)
{
    createProcessSystem();
    createProcessFork();
    createProcessExec();

    setsid();
    daemon(1, 1);

    while(1);
    return getpid();
}
