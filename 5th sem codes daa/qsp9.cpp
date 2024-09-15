//qs
#include<stdio.h>

void quick_sort(int arr[],int low,int high);
int partition(int arr[],int low,int high);

int main(){
	int n,i;
	printf("enter the array size: ");
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
	printf("\n");
	quick_sort(arr,1,n);
	printf("after sorting the array is: ");
	for(i=1;i<=n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}

void quick_sort(int arr[],int low,int high){
	if(low<high){
		int q=partition(arr,low,high);
		quick_sort(arr,low+1,high);
		quick_sort(arr,low,high-1);
	}
}

int partition(int arr[],int low,int high){
	int i,j,temp;
	int pivot=arr[high];
	i=low-1;
	for(j=low;j<=(high-1);j++){
		if(arr[j]<=pivot){
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;
	return (i+1);
}
