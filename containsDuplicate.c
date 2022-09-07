#include <stdio.h>

typedef enum { false, true } bool;

void swap(int* a, int* b) {
    int temp = *a;

    *a = *b;
    *b = temp;
}

void heapify(int arr[], int N, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest]) largest = left;

    if (right < N && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--) heapify(arr, N, i);

    for (int i = N - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

bool containsDuplicate(int* nums, int numsSize) {
    int i;

    heapSort(nums, numsSize);
    for (i = 0; i < numsSize - 1; ++i)
        if (!(nums[i] < nums[i + 1])) return true;
    return false;
}

/*Tests*/
int main() {
    int arr1[] = {1, 2, 3, 1};                   /*expected: true*/
    int arr2[] = {1, 2, 3, 4};                   /*expected: false*/
    int arr3[] = {3, 1, 1, 3, 3, 4, 3, 2, 4, 2}; /*expected: true*/

    if (containsDuplicate(arr1, 10))
        printf("arr1: true\n");
    else
        printf("arr1: false\n");

    if (containsDuplicate(arr2, 10))
        printf("arr2: true\n");
    else
        printf("arr2: false\n");

    if (containsDuplicate(arr3, 10))
        printf("arr3: true\n");
    else
        printf("arr3: false\n");

    return 0;
}
