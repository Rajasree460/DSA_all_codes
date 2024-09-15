//max heapify(create max heap)
#include<stdio.h>

int n=0;

void create_max_heap(int arr[]);
void max_heapify(int arr[],int i);

int main(){
	int arr[20],i;
	printf("enter the array(heap) size: ");
	scanf("%d",&n);
	printf("\nenter the array(heap) eles\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("the array(heap) is: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	create_max_heap(arr);
	printf("the max heap is: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void create_max_heap(int arr[]){
	int last_non_leaf=(n-1)/2;
	for(int i=last_non_leaf;i>=0;i--){
		max_heapify(arr,i);
	}
}

void max_heapify(int arr[],int i){
	int lc,rc,largest;
	lc=2*i+1;
	rc=2*i+2;
	if(lc<n && arr[lc]>arr[i]){
		largest=lc;
	}
	else{
		largest=i;
	}
	if(rc<n && arr[rc]>arr[largest]){
		largest=rc;
	}
	if(largest!=i){
		int temp=arr[largest];
		arr[largest]=arr[i];
		arr[i]=temp;
		max_heapify(arr,largest);
	}
}
