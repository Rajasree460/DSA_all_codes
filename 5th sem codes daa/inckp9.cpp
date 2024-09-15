//inck
#include<stdio.h>

int n=0;

void increase_key(int arr[],int key,int id);

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
	printf("enter the id of the val to be increased: ");
	scanf("%d",&id);
	printf("\nenter the increased val: ");
	scanf("%d",&key);
	increase_key(arr,key,id);
	printf("after increase key the max heap is: ");for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
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
