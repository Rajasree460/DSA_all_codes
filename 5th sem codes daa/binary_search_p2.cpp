/*binary search*/
#include<stdio.h>

int binary_search(int arr[],int low,int high,int key);

int main(){
	int n,i,j,temp,key;
	printf("enter the size of array: ");
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
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("\nthe sorted array is: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\nenter the ele to be searched: ");
	scanf("%d",&key);
	int id=binary_search(arr,0,n-1,key);
	printf("the key ele is found at loc: %d\n",id+1);
}

int binary_search(int arr[],int low,int high,int key){
	int mid=(low+high)/2;
	if(low<=high){
		if(arr[mid]==key){
			return mid;
		}
		else if(arr[mid]<key){
			return binary_search(arr,mid+1,high,key);
		}
		else   //arr[mid]>key
		{
			return binary_search(arr,low,mid-1,key);
		}
	}
	if(low>high){
		printf("key not found\n");
	}
	/*int flag=0;
	for(int i=low;i<high+1,i++){
		if(key!=arr[i]){
			flag=1;
		}
	}
	if(flag==1){
	printf("key doesnt exist at this array\n");
    }
    */
}
