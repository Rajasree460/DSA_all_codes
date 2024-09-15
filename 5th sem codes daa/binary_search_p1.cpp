//binary search
#include<stdio.h>
int binary_search(int arr[],int key,int low,int high);
int main(){
	int n,i,j,temp,key;
	printf("enter the size of array: ");
	scanf("%d",&n);
	int arr[n];
	printf("\nenter the array elements\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("the array is: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
}
	printf("sorted array: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	printf("enter the key to be searched: ");
	scanf("%d",&key);
	int loc=binary_search(arr,key,0,n-1);
	printf("\n%d found at %d loc\n",key,loc+1);
}
int binary_search(int arr[],int key,int low,int high){
	int mid=(low+high)/2;
	if(high>=low){
		if(arr[mid]==key){
			return mid;
		}
		else if(arr[mid]>key){
			return binary_search(arr,key,0,mid+1);
		}
		else{  //arr[mid]<key
			return binary_search(arr,key,mid-1,high);
	    }
	}
	else{
		printf("key not found");
	}
}
