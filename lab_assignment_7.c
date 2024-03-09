#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n){
    int swapped = 0;
    int unsorted[n];
    int count[n];
    int totalSwaps = 0;
    for(int i = 0; i < n; i++){
        unsorted[i] = arr[i];
        count[i] = 0;
    }

    for(int i = 0; i < n-1; i++){
        swapped = 0;
        for(int j = 0; j < n-i-1; j++){
            if(unsorted[j] > unsorted[j+1]){
                swap(&unsorted[j], &unsorted[j+1]);
                count[j]++;
                count[j+1]++;
                swap(&count[j], &count[j+1]);
                totalSwaps++;
                swapped = 1;
            }
        }

        if(!swapped){
            break;
        }
    }
    
    for(int i = 0; i < n; i++){
        printf("%d: %d\n", unsorted[i], count[i]);
    }
    printf("%d", totalSwaps);

}

void selectionSort(int arr[], int n){
    int min;
    int unsorted[n];
    int count[n];
    int totalSwaps = 0;
    for(int i = 0; i < n; i++){
        unsorted[i] = arr[i];
        count[i] = 0;
    }

    for(int i = 0; i < n-1; i++){
        min = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(min != i){
            swap(&arr[min], &arr[i]);
            count[i]++;
            count[min]++;
            swap(&count[min], &count[i]);
            totalSwaps++;
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d: %d\n", arr[i], count[i]);
    }
    printf("%d", totalSwaps);
}

void print(int arr[], int n){
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d, ", arr[i]);
    }
}

int main(){
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = 9;
    printf("array1 bubble sort:\n");
    bubbleSort(array1, n);
    printf("\n\narray2 bubble sort:\n");
    bubbleSort(array2, n);
    printf("\n\narray1 selection sort:\n");
    selectionSort(array1, n);
    printf("\n\narray2 selection sort:\n");
    selectionSort(array2, n);
}