#include<stdio.h>

int size = 0;

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


void show_heap(int arr[])
{

	printf("\n max heap is now: \n");
	for(int i = 0; i<size; i++)
		printf("%d\t",arr[i]);
}


void max_heapify(int arr[], int i)
{
	int lc, rc, largest, t;

	lc = 2*i+1;
	rc = 2*i+2;

	if(lc < size && arr[lc] > arr[i])
		largest = lc;
	else
		largest = i;

	if(rc < size && arr[rc] > arr[largest])
		largest = rc;

	if(largest != i)
	{
		//t = arr[i];
		//arr[i] = arr[largest];
		//arr[largest] = t;
		//

		swap(&arr[i], &arr[largest]);

		max_heapify(arr, largest);
	}
}



void create_max_heap(int arr[])
{
	int i;
	
	for(i = (size-1)/2; i>=0; i--)
		max_heapify(arr, i);

	
	show_heap(arr);
}


void extract_max(int arr[])
{
	int max = -99999;

	printf("\n===== Extract max ====");

	if(size<1)
		printf("\n Heap Underflow");
	
	max = arr[0];
	arr[0]=arr[size-1];
	size = size-1;
	max_heapify(arr, 0);

	printf("\n max elem is %d\t",max);
	show_heap(arr);
}


void increase(int arr[],int i,int key)
{
	
	if(key < arr[i])
		printf("\n Error value is less");

	else
	{

		arr[i] = key;
	
		while(i>0 && arr[(i-1)/2] < arr[i])
		{
			swap(&arr[i], &arr[(i-1)/2]);
			i = (i-1)/2;
		}
	}


}

void increase_key(int arr[])
{

	int i, key;

	printf("\n===== Increase key =====");

	printf("\n Enter the index of the key to be increased \t");
	scanf("%d",&i);
	printf("\n Enter the key value\t");
	scanf("%d",&key);

	increase(arr,i,key);
	show_heap(arr);
}



void insert_key(int arr[])
{
	int key;

	printf("\n =====Insert a new key======");
	printf("\n enter the key value\t");
	scanf("%d",&key);
	
	arr[size]=-99999;
	size = size+1;
	increase(arr,size-1,key);
	show_heap(arr);
}


void decrease_key(int arr[])
{

	int i, key;

	printf("\n===== Decrease key =====");

	printf("\n Enter the index of the key to be decreased \t");
	scanf("%d",&i);
	printf("\n Enter the key value\t");
	scanf("%d",&key);

	if(key > arr[i])
		printf("\n Error value is higher");

	else
	{
		arr[i]=key;
		max_heapify(arr,i);
		show_heap(arr);
	}

}

void heap_sort(int arr[])
{
	int n = size;
	//create_max_heap(arr);
	printf("\n ==== heap sort ====");
	for(int i=size-1; i>=1; i--)
	{
		swap(&arr[0],&arr[i]);
		size=size-1;
		max_heapify(arr,0);
	}
	size=n;
	
	show_heap(arr);

}


int main()
{

	int i,n, arr[20],key;

	printf("Enter the number of elements\t");
	scanf("%d",&n);
	size = n;

	printf("\nEnter the elements \n");
	for(i = 0; i< size; i++)
		scanf("%d",&arr[i]);

	create_max_heap(arr);

	//printf("\n max heap is \n");
	//for(i = 0; i<size; i++)
	//	printf("%d\t",arr[i]);
	//
	//show_heap(arr);
		
	extract_max(arr);

	increase_key(arr);
	
	insert_key(arr);

	decrease_key(arr);

	//delete_key(arr);

	heap_sort(arr);
}





