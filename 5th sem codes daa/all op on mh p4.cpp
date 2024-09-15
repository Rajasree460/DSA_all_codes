//all operations on max heap
#include<stdio.h>
#include<stdlib.h>

int n=0;

void create_max_heap(int arr[]);
int extract_max(int arr[]);
void insert_key(int arr[]);
void increase_key(int arr[]);
void decrease_key(int arr[]);
void delete_key(int arr[]);
void heap_sort(int arr[]);
void create_max(int arr[]);
void increase(int arr[],int id,int key);
void display(int arr[]);
void max_heapify(int arr[],int i);

int main(){
	int arr[20],ch;
	while(ch!=8){
		printf("main menu\n");
		printf("1.create max heap\n2.extract max ele\n3.insert key\n4.increase key\n5.decrease key\n6.delete key\n7.heap sort\n8.exit\n");
		printf("enter your choice: ");
		scanf("%d",&ch);
		printf("\n");
		switch(ch){
			case 1:create_max_heap(arr);
			break;
			case 2:printf("enter the size of array(heap): ");
			scanf("%d",&n);
			printf("\nenter the array(heap) eles\n");
			for(int i=0;i<n;i++){
				scanf("%d",&arr[i]);
			}
			printf("the array(heap) is: ");
			for(int i=0;i<n;i++){
				printf("%d ",arr[i]);
			}
			printf("\n");
			while(n>0){
				int max=extract_max(arr);
				printf("extracted max ele: %d\n",max);
			}
			break;
			case 3:insert_key(arr);
			break;
			case 4:increase_key(arr);
			break;
			case 5:decrease_key(arr);
			break;
			case 6:delete_key(arr);
			break;
			case 7:heap_sort(arr);
			break;
			case 8:exit(0);
			default:
				printf("invalid choice\n");
		}
	}
	return 0;
}

void create_max_heap(int arr[]){
	printf("enter the size of array(heap): ");
	scanf("%d",&n);
	printf("\nenter the array(heap) eles\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("the array(heap) is: ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	create_max(arr);
	printf("the max heap is: ");
	display(arr);
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

void insert_key(int arr[]){
	int key;
	printf("enter the size of array(heap): ");
	scanf("%d",&n);
	printf("\nenter the array(heap) eles\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("the array(heap) is: ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	printf("enter the key(value/ele) to be inserted: ");
	scanf("%d",&key);
	n++;
	arr[n-1]=-999999999;
	increase(arr,n-1,key);
	printf("\nafter insertion the max heap is: ");
	display(arr);
}

void increase_key(int arr[]){
	int key,id;
	printf("enter the size of array(heap): ");
	scanf("%d",&n);
	printf("\nenter the array(heap) eles\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("the array(heap) is: ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	printf("enter the index of the element to be increased: ");
	scanf("%d",&id);
	printf("\nenter the increased value: ");
	scanf("%d",&key);
	if(arr[id]>key){
		printf("the value at the index is already greater than key(increased value)\n");
	}
	else{
	   increase(arr,id,key);	
	}
	printf("\nafter increase the max heap is: ");
	display(arr);
}


void decrease_key(int arr[]){
	int key,id;
	printf("enter the size of array(heap): ");
	scanf("%d",&n);
	printf("\nenter the array(heap) eles\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("the array(heap) is: ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	printf("enter the index of the element to be decreased: ");
	scanf("%d",&id);
	printf("\nenter the decreased value: ");
	scanf("%d",&key);
	if(arr[id]<key){
		printf("the value at the index is already lesser than key(decreased value)\n");
	}
	else{
	   arr[id]=key;
	   max_heapify(arr,id);	
	}
	printf("\nafter decrease the max heap is: ");
	display(arr);
}


void delete_key(int arr[]){
	int id;
	printf("enter the size of array(heap): ");
	scanf("%d",&n);
	printf("\nenter the array(heap) eles\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("the array(heap) is: ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	printf("enter the index of the element to be deleted: ");
	scanf("%d",&id);
	int del_ele=arr[id];
	arr[id]=arr[n-1];
	n--;
	max_heapify(arr,id);
	printf("\n%d is deleted",del_ele);
	printf("\nafter deletion the max heap is: ");
	display(arr);
	
}


void heap_sort(int arr[]){
	printf("enter the size of array(heap): ");
	scanf("%d",&n);
	printf("\nenter the array(heap) eles\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("the array(heap) is: ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	create_max(arr);
	printf("the max heap is: ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	int copy=n;
	for(int i=n-1;n>=1;i--){
		int max=arr[0];
		arr[0]=arr[i];
		arr[i]=max;
		n--;
		max_heapify(arr,0);
	}
	n=copy;
	printf("after heap sort the result(heap) is: ");
	for(int i=n-1;i>=0;i--){
		printf("%d ",arr[i]);
	}
	printf("\n");
}


void create_max(int arr[]){
	int last_non_leaf=(n-1)/2;
	for(int i=last_non_leaf;i>=0;i--){
		max_heapify(arr,i);
	}
}


void increase(int arr[],int id,int key){
	arr[id]=key;
	while(id>0 && arr[(id-1)/2]<arr[id]){
		int temp=arr[(id-1)/2];
		arr[(id-1)/2]=arr[id];
		arr[id]=temp;
		id=(id-1)/2;
	}
}


void display(int arr[]){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
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
