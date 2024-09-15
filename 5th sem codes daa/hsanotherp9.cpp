//hs
#include<stdio.h>

int n=0;

void heap_sort(int arr[]);
void max_heapify(int arr[],int i);

int main(){
	int arr[20];
	printf("enter the array(heap) size: ");
	scanf("%d",&n);
	printf("\nenter the heap eles\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("the array(heap) is: ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	heap_sort(arr);
	printf("after heap sort,the result is: ");
	for(int i=n-1;i>=0;i--){
		printf("%d ",arr[i]);
	}
	printf("\n");
}


void heap_sort(int arr[]){
	int copy=n;
	for(int i=n-1;i>=1;i--){
		int max=arr[0];
		arr[0]=arr[i];
		arr[i]=max;
		n--;
		max_heapify(arr,0);
	}
	n=copy;
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
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		max_heapify(arr,largest);
	}
}
