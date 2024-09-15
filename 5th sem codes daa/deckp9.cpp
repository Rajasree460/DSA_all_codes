//deck
#include<stdio.h>

int n=0;

void decrease_key(int arr[],int key,int id);
void max_heapify(int arr[],int i);

int main(){
	int id,key,arr[20];
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
	printf("enter the id of the val to be decreased: ");
	scanf("%d",&id);
	printf("\nenter the decreased val: ");
	scanf("%d",&key);
	decrease_key(arr,key,id);
	printf("after decreased key the max heap is: ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void decrease_key(int arr[],int key,int id){
	if(arr[id]<key){
		printf("\nerror,the val present at the index is already decreased\n");
	}
	else{
		arr[id]=key;
		max_heapify(arr,id);
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
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		max_heapify(arr,largest);
	}
}
