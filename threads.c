
//create thread in c 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_hello(void* thread_id){
    print("Hello World");
    printf("Thread ID: %d\n", thread_id);
}
int amin(){
    pthread_t thread;
    pthread_create(&thread, NULL, print_hello, NULL);
    pthread_join(thread, NULL);
    return 0;
}
