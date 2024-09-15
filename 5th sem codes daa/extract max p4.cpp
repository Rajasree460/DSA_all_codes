//extract max element from max heap
#include<stdio.h>

int n=0;

int extract_max(int arr[]);
void max_heapify(int arr[],int i);

int main(){
	int i,arr[20];
	printf("enter the size of array(heap):");
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
	while(n>0){  //as n=0,means no eles
		int max=extract_max(arr);
		printf("extracted max ele: %d\n",max);
	}
	return 0;
}

int extract_max(int arr[]){
	if(n<0){
		printf("error,heap underflow\n");
	}
	int max=arr[0];
	arr[0]=arr[n-1];
	n--;
	max_heapify(arr,0);
	return max;
}

void max_heapify(int arr[],int i){
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
		max_heapify(arr,largest);
	}
}
