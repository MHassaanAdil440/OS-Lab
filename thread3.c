//write a program that takes a value n from the user first thread prints all odd numbers till n second thread prints
//all even numbers till n

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int n;

void* odd(void* thread_id){
    printf("Odd numbers till %d: ", n);
    for(int i = 1; i <= n; i++){
        if(i % 2 != 0){
            printf("%d ", i);
        }
    }
    printf("\n");
}

void* even(void* thread_id){
    printf("Even numbers till %d: ", n);
    for(int i = 1; i <= n; i++){
        if(i % 2 == 0){
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main(){
    pthread_t thread1, thread2;
    printf("Enter a number: ");
    scanf("%d", &n);
    pthread_create(&thread1, NULL, odd, NULL);
    pthread_create(&thread2, NULL, even, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}