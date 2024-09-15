//delk
#include<stdio.h>

int n=0;

void delete_key(int arr[],int id);
void max_heapify(int arr[],int i);

int main(){
	int id,arr[20];
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
	printf("enter the id of the val to be deleted: ");
	scanf("%d",&id);
	delete_key(arr,id);
	printf("after deletion the max heap is: ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void delete_key(int arr[],int id){
	int del_ele=arr[id];
	arr[id]=arr[n-1];
	n--;
	max_heapify(arr,id);
	printf("\n%d is deleted\n",del_ele);
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
