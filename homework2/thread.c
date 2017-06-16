#include <pthread.h>
#include <stdio.h>
#include <limits.h>

// Function for calculation
// sum from 1 to n
void* sum(void* n) 
{
    int sum = 0;
    int i = 1;
	do
        {  
	    sum += i;
            i++;
        }while(i <= *((int*)n)); 
    return (void*)sum; 
}

int main(void)
{
    pthread_t thread_id; // thread for calculation
    pthread_attr_t attr; // attributes for thread
    
    pthread_attr_init(&attr); // init attributes

    void* stack_addr_bases = (void*)malloc(sizeof(void)); // get memory in heap for stack
    size_t stack_size = PTHREAD_STACK_MIN; // get minimum of stack size

    pthread_attr_setstack(&attr, stack_addr_bases, stack_size); // set params of stack
    
    // getting value for calculation
    int n;
    printf("\nn = ");
    scanf("%d", &n);

    pthread_create(&thread_id, &attr, &sum, &n); // create thread
    
    int result;
    pthread_join(thread_id, (void*)&result); // waiting for finish of working thread

    printf("result = %d\n", result);

    return 0;
}
