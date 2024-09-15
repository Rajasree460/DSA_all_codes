/*extract max element from max heap*/
#include <stdio.h>

void max_heapify(int arr[], int n, int i);
int extract_max_ele(int arr[], int *n); 

int main() {
    int n, i;
    printf("Enter the array size (the array is an array representation of a heap): ");  //so,heap size=arr size
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The array (heap) is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    while (n > 0) {
        int max = extract_max_ele(arr, &n); // Pass n by reference to update it
        printf("Extracted max element: %d\n", max);
    }
    
    return 0;
}

int extract_max_ele(int arr[], int *n) { // Accept an array and a pointer to n
    if (*n < 0) {
        printf("ERROR: heap underflow, there is no element in that heap\n");
        return -1; // Return a sentinel value to indicate an error
    }
    int max = arr[0];
    arr[0] = arr[(*n) - 1];  //as index is starting from 0
    (*n)--;
    max_heapify(arr, *n, 0);  //heapifying from the 1st index
    return max;
}

void max_heapify(int arr[], int n, int i) {
    int lc, rc, largest;
    lc = 2 * i + 1;
    rc = 2 * i + 2;
    if (lc < n && arr[lc] > arr[i]) {
        largest = lc;
    } else {
        largest = i;
    }
    if (rc < n && arr[rc] > arr[largest]) {
        largest = rc;
    }
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        max_heapify(arr, n, largest);
    }
}

