/*quick sort*/

#include<stdio.h>

void quick_sort(int arr[],int low,int high);
int partition(int arr[],int low,int high);


int main(){
	int n,i,j,temp,key;
	printf("enter the size of array: ");
	scanf("%d",&n);
	int arr[n];
	printf("\nenter the array eles\n");
	for(i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	printf("the array is: ");
	for(i=1;i<=n;i++){
		printf("%d ",arr[i]);
	}
	quick_sort(arr,1,n);
	printf("\nthe sorted array is: ");
	for(i=1;i<=n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void quick_sort(int arr[],int low,int high){
	if(low<high){                   //low=1,high=n
		int q=partition(arr,low,high);  
		quick_sort(arr,low,high-1);     
		quick_sort(arr,low+1,high);     
	}
}

int partition(int arr[],int low,int high){
	int i,j;
	int pivot=arr[high];
	i=low-1;
	for(j=low;j<=high-1;j++){
		if(arr[j]<=pivot){
			i++;
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	int temp=arr[i+1];
	arr[i+1]=arr[high]; //pivot=arr[high]
	arr[high]=temp;
	return (i+1);
}
