//decrease key operation
#include<stdio.h>
int n=0;

void decrease_key(int arr[],int id,int key);
void max_heapify(int arr[],int i);

int main(){
	int arr[20],i,id,key;
	printf("enter the size of array(heap): ");
	scanf("%d",&n);
	printf("\nenter the array eles\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("the array(heap) is: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\nenter the index of the element to be decreased: ");
	scanf("%d",&id);
	printf("\nenter the decreased val: ");
	scanf("%d",&key);
	decrease_key(arr,id,key);
	printf("\nafter decrease key the heap(max heap) is: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void decrease_key(int arr[],int id,int key){
	if(arr[id]<key){
		printf("ERROR:the element is already lesser than key\n");
	}
	else{
		arr[id]=key;
		max_heapify(arr,id); //as key<arr[id],arr[id]<arr[root],so key<arr[root] so no need to apply mh from root
	}
}

void max_heapify(int arr[],int i){
	int rc,lc,largest;
	lc=2*i+1;
	rc=2*i+2;
	if(lc<n && arr[i]<arr[lc]){
		largest=lc;
	}
	else{
		largest=i;
	}
	if(rc<n && arr[largest]<arr[rc]){
		largest=rc;
	}
	if(largest!=i){
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		max_heapify(arr,largest);
	}
}
