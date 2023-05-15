//make 2 threads first thread should take an array of size 10 input second thread should sort the array

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arr[10];

void* input(void* thread_id){
    printf("Enter 10 numbers: ");
    for(int i = 0; i < 10; i++){
        scanf("%d", &arr[i]);
    }
}

void* sort(void* thread_id){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10 - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp; 
            }
        }
    }
}

int main(){
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, input, NULL);
    pthread_join(thread1, NULL);
    pthread_create(&thread2, NULL, sort, NULL);
    pthread_join(thread2, NULL);
    printf("Sorted array: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
