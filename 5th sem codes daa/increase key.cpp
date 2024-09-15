/*increase key operation*/
#include <stdio.h>

int n = 0;

void increase_key(int arr[], int id, int key);

int main() {
    int i, arr[20], id=0, key=0; //taking an empty array of size 20
    printf("Enter the array size (the array is an array representation of a heap): "); //so, heap size = arr size
    scanf("%d", &n);
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("the array (heap) is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("enter the index of the element to be increased: ");
    scanf("%d", &id); 
    printf("\nenter the key (increased val): ");
    scanf("%d", &key); 
    printf("\n");
    increase_key(arr, id, key);
    printf("the heap after increase key operation: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void increase_key(int arr[], int id, int key) {
    if (arr[id] > key) {
        printf("ERROR: node value already greater than key");
        return;
    }
    arr[id] = key;
    while (id > 0 && arr[(id - 1)/ 2] < arr[id]) {
        int temp = arr[(id - 1)/ 2];
        arr[(id - 1)/ 2] = arr[id];
        arr[id] = temp;
        id = (id - 1)/ 2;
    }
}
