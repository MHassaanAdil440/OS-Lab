//Write a program in c that forms a calculator with basic functions(+-*/) each function is to be performed by a separate thread.
//Take two grobal parameters as input and print the result in the main thread.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int a, b;

void* addition(void* thread_id){
    int sum = a + b;
    printf("Sum: %d\n", sum);
}

void* subtraction(void* thread_id){
    int sub = a - b;
    printf("Subtraction: %d\n", sub);
}

void* multiplication(void* thread_id){
    int mul = a * b;
    printf("Multiplication: %d\n", mul);
}

void* division(void* thread_id){
    int div = a / b;
    printf("Division: %d\n", div);
}

int main(){
    pthread_t thread1, thread2, thread3, thread4;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    pthread_create(&thread1, NULL, addition, NULL);
    pthread_create(&thread2, NULL, subtraction, NULL);
    pthread_create(&thread3, NULL, multiplication, NULL);
    pthread_create(&thread4, NULL, division, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    return 0;
}