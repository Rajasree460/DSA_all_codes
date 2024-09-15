//em
#include<stdio.h>

int n=0;

int extract_max(int arr[]);
void max_heapify(int arr[],int i);

int main(){
	            int arr[20];
	            printf("enter the array(heap) size: ");
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
}

int extract_max(int arr[]){
	if(n<0){
		printf("error,heap underflow\n");
	}
	else{
		int max=arr[0];
		arr[0]=arr[n-1];
		n--;
		max_heapify(arr,0);
		return max;
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

