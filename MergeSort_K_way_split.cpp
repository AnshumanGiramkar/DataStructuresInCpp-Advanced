#include <iostream>
#include <stdlib.h>
#define INT_MAX 2000
// Merge two sorted arrays
using namespace std;
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int leftIndex = 0;
    int rightIndex = 0;
    int mergeIndex = 0;

    while (leftIndex < leftSize && rightIndex < rightSize) {
        if (left[leftIndex] <= right[rightIndex]) {
            arr[mergeIndex] = left[leftIndex];
            leftIndex++;
        } else {
            arr[mergeIndex] = right[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }

    // Copy remaining elements from left or right array
    while (leftIndex < leftSize) {
        arr[mergeIndex] = left[leftIndex];
        leftIndex++;
        mergeIndex++;
    }

    while (rightIndex < rightSize) {
        arr[mergeIndex] = right[rightIndex];
        rightIndex++;
        mergeIndex++;
    }
}

// Merge sort using K-way split
void mergeSort(int arr[], int size, int k) {
    if (size <= 1) {
        return;
    }

    int chunkSize = size / k;
    int remaining = size % k;
    int** chunks = (int**)malloc(k * sizeof(int*));
    int i, j, start = 0;

    for (i = 0; i < k; i++) {
        int chunkSizeCurrent = chunkSize + (i < remaining ? 1 : 0);
        chunks[i] = (int*)malloc(chunkSizeCurrent * sizeof(int));

        for (j = 0; j < chunkSizeCurrent; j++) {
            chunks[i][j] = arr[start];
            start++;
        }

        mergeSort(chunks[i], chunkSizeCurrent, k);
    }

    // Perform K-way merge
    int* indexes = (int*)malloc(k * sizeof(int));
    int* mergedArray = (int*)malloc(size * sizeof(int));

    for (i = 0; i < k; i++) {
        indexes[i] = 0;
    }

    int mergeIndex = 0;
    int minIndex, minValue;
    while (mergeIndex < size) {
        minIndex = -1;
        minValue = INT_MAX;

        for (i = 0; i < k; i++) {
            if (indexes[i] < (chunkSize + (i < remaining ? 1 : 0)) && chunks[i][indexes[i]] < minValue) {
                minIndex = i;
                minValue = chunks[i][indexes[i]];
            }
        }

        mergedArray[mergeIndex] = minValue;
        indexes[minIndex]++;
        mergeIndex++;
    }

    // Copy merged array back to the original array
    for (i = 0; i < size; i++) {
        arr[i] = mergedArray[i];
    }

    // Free memory
    for (i = 0; i < k; i++) {
        free(chunks[i]);
    }
    free(chunks);
    free(indexes);
    free(mergedArray);
}

// Print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter Number of Elements in Array:");
    scanf("%d", &size);
    int arr[size];
    cout<<"Enter Array ELements One-by-One:";
    for(int i=0; i<size; i++){
        scanf("%d",&arr[i]);
    }
    int k = 4;

    printf("Original array: ");
    printArray(arr, size);

    mergeSort(arr, size, k);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
