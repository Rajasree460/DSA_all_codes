//insert key operation
#include<stdio.h>
int n=0;

void insert_key(int arr[],int key);
void increase_key(int arr[],int id,int key);

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
	printf("\nenter the val to be inserted: ");
	scanf("%d",&key);
	insert_key(arr,key);
	printf("\nafter insert key op the heap(max heap) is: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}


void insert_key(int arr[],int key){
	
	n++;
	arr[n-1]=-99999;
	increase_key(arr,n-1,key);
}

void increase_key(int arr[],int id,int key){
	if(arr[id]>key){
		printf("ERROR:the element is already greater than key\n");
	}
	else{
		arr[id]=key;
	    while(id>0 && arr[(id-1)/2]<arr[id])  //as key>arr[id],arr[id]>all eles of that subtree(root=id),so key>all eles of that subtree(root=id) so no need to apply mh from root to end,may the increased value is greater then its parent so apply mh to id's parent till root
		{
	    int temp=arr[(id-1)/2];
	    arr[(id-1)/2]=arr[id];
	    arr[id]=temp;
	    id=(id-1)/2;
	}
}
}

