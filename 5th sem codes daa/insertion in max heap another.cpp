/*insert element in max heap*/
#include <stdio.h>
int n=0; 

void insert_key(int arr[], int key);
void increase_key(int arr[], int id, int key);

int main() {
    int i,arr[20],key=0; 
    printf("Enter the array size (the array is an array representation of a heap): "); //so, heap size = arr size
    scanf("%d", &n);
    //int arr[n];
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("the array (heap) is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("enter the key to be inserted: ");
    scanf("%d", &key); 
    printf("\n");
    insert_key(arr, key);
    printf("after insertion the heap is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void insert_key(int arr[], int key)
{
	n++;
	arr[n-1]=-99999;
	int id=n-1;
	increase_key(arr, id, key);
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
