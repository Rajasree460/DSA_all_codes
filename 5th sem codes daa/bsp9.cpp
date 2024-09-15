//binary search
#include<stdio.h>

int binary_search(int arr[],int key,int low,int high);

int main(){
	int n,i,j,temp,key;
	printf("enter the array size: ");
	scanf("%d",&n);
	int arr[n];
	printf("\nenter the array eles\n");
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
	printf("after sorting the array is: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	printf("enter the value to be searched: ");
	scanf("%d",&key);
	int loc=binary_search(arr,key,0,n-1);
	printf("\n%d found at loc: %d\n",key,loc+1);
	return 0;
}

int binary_search(int arr[],int key,int low,int high){
	int mid=(low+high)/2;
	if(low<=high){
		if(arr[mid]==key){
			return mid;
		}
		else if(arr[mid]<key){
			return binary_search(arr,key,mid+1,high);
		}
		else{
			return binary_search(arr,key,low,mid-1);
		}
	}
	else{
		printf("\nkey not found\n");
	}
}
