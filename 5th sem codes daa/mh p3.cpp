//max heapify(create max heap)
#include<stdio.h>

void create_max_heap(int arr[],int n);
void max_heapify(int arr[],int n,int i);

int main(){
	int n,i;
	printf("enter the size of array(heap):");
	scanf("%d",&n);
	int arr[n];
	printf("\nenter the array(heap) eles\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("the array(heap) is:");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	create_max_heap(arr,n);
	printf("the max heap is:");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}

void create_max_heap(int arr[],int n){
	int last_non_leaf=(n-1)/2;  //id of last non leaf ele
	for(int i=last_non_leaf;i>=0;i--){
	    max_heapify(arr,n,i);	
	}
}

void max_heapify(int arr[],int n,int i){
	int rc,lc,largest;
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
		max_heapify(arr,n,largest);
	}
}
