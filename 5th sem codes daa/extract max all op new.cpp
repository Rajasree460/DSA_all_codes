/*all ops of extract max*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void delete_key(int arr[], int *n);
void decrease_key(int arr[], int n);
void insert_key(int arr[], int *n);
void increase_key(int arr[], int n);
void heap_sort(int arr[], int n);
void display(int arr[], int n);
void create_max_heap(int arr[], int n);
void max_heapify(int arr[], int n, int i);
void increase(int arr[], int i, int key);

int main() {
    int ch = 0, n = 0;
    int arr[MAX_SIZE];

    printf("Enter the array size (the array is an array representation of a heap, max size is %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n > MAX_SIZE || n < 1) {
        printf("Invalid array size. Please enter a valid size between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter %d array elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The array (heap) is: ");
    display(arr, n);

    while (ch != 7) {
        printf("\nMain menu:\n");
        printf("1. Delete from max heap\n2. Decrease key\n3. Insert in max heap\n4. Increase key\n5. Heap sort\n6. Display\n7. Exit\n");
        printf("Choose your option: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                delete_key(arr, &n);
                break;
            case 2:
                decrease_key(arr, n);
                break;
            case 3:
                insert_key(arr, &n);
                break;
            case 4:
                increase_key(arr, n);
                break;
            case 5:
                heap_sort(arr, n);
                break;
            case 6:
                display(arr, n);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void delete_key(int arr[], int *n) {
    int id = 0;

    if (*n == 0) {
        printf("Heap is empty. Nothing to delete.\n");
        return;
    }

    printf("Enter the index of the key to be deleted: ");
    scanf("%d", &id);

    if (id < 0 || id >= *n) {
        printf("Invalid index\n");
        return;
    }

    int del_ele = arr[id];
    arr[id] = arr[(*n) - 1];
    (*n)--;
    max_heapify(arr, *n, id);
    printf("%d deleted\n", del_ele);
}

void decrease_key(int arr[], int n) {
    int id = 0, key = 0;

    if (n == 0) {
        printf("Heap is empty. Cannot decrease key.\n");
        return;
    }

    printf("Enter the index of the element to be decreased: ");
    scanf("%d", &id);

    if (id < 0 || id >= n) {
        printf("Invalid index\n");
        return;
    }

    printf("Enter the key (decreased value): ");
    scanf("%d", &key);

    if (arr[id] < key) {
        printf("ERROR: Node value is already lesser than the key\n");
        return;
    }

    arr[id] = key;
    max_heapify(arr, n, id);
    printf("Decrease key done\n");
}

void insert_key(int arr[], int *n) {
    int key = 0;

    if (*n >= MAX_SIZE) {
        printf("Heap size exceeded. Cannot insert more elements\n");
        return;
    }

    printf("Enter the key to be inserted: ");
    scanf("%d", &key);
    (*n)++;
    arr[*n - 1] = key;
    int id = *n - 1;
    increase(arr, id, key);
    printf("Insertion done\n");
}

void increase_key(int arr[], int n) {
    int id = 0, key = 0;

    if (n == 0) {
        printf("Heap is empty. Cannot increase key.\n");
        return;
    }

    printf("Enter the index of the element to be increased: ");
    scanf("%d", &id);

    if (id < 0 || id >= n) {
        printf("Invalid index\n");
        return;
    }

    printf("Enter the key (increased value): ");
    scanf("%d", &key);

    increase(arr, id, key);
    printf("Increase key done\n");
}

void heap_sort(int arr[], int n) {
    int copy = n; // Store the original size
    create_max_heap(arr, n);
    for (int i = n - 1; i >= 1; i--) {
        int max = arr[0];
        arr[0] = arr[i];
        arr[i] = max;
        n--;
        max_heapify(arr, n, 0);
    }
    n = copy; // Restore the original size
    printf("Heap sort done\n");
}

void display(int arr[], int n) {
    if (n == 0) {
        printf("Heap is empty\n");
        return;
    }

    printf("After operation the array(heap): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void create_max_heap(int arr[], int n) {
    int last_non_leaf = (n - 1) / 2;
    for (int i = last_non_leaf; i >= 0; i--) {
        max_heapify(arr, n, i);
    }
}

void max_heapify(int arr[], int n, int i) {
    int lc, rc, largest = i;
    lc = 2 * i + 1;
    rc = 2 * i + 2;

    if (lc < n && arr[lc] > arr[largest]) {
        largest = lc;
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

void increase(int arr[], int i, int key) {
    if (arr[i] > key) {
        printf("ERROR: Node value is already greater than the key\n");
        return;
    }

    arr[i] = key;

    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        int temp = arr[(i - 1) / 2];
        arr[(i - 1) / 2] = arr[i];
        arr[i] = temp;
        i = (i - 1) / 2;
    }
}

