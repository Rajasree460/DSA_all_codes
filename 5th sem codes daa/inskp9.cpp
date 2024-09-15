//insk
#include<stdio.h>

int n=0;

void insert_key(int arr[],int key);
void increase_key(int arr[],int key,int id);

int main(){
	int key,arr[20];
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
	printf("enter the val to be inserted: ");
	scanf("%d",&key);
	insert_key(arr,key);
	printf("after insertion the max heap is: ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void insert_key(int arr[],int key){
	n++;
	arr[n-1]=-9999999;
	increase_key(arr,key,n-1);
}

void increase_key(int arr[],int key,int id){
	if(arr[id]>key){
		printf("\nerror,the val present at the index is already increased\n");
	}
	else{
		arr[id]=key;
		while(id>0 && arr[(id-1)/2]<arr[id]){
			int temp=arr[(id-1)/2];
			arr[(id-1)/2]=arr[id];
			arr[id]=temp;
			id=(id-1)/2;
		}
	}
}
