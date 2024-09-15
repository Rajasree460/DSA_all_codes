/*quick sort*/

#include<stdio.h>

void insertion_sort(int arr[],int n);

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
	insertion_sort(arr,n);
}
void insertion_sort(int arr[],int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		temp=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>temp){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
//	for(i=1;i<n;i++){
//		temp=arr[i];
//		j=i-1;
//		while(j>=0 && arr[j]>temp){
//			arr[j+1]=arr[j];
//			j--;
//			arr[j+1]=temp;
//		}
//	}
	printf("\nthe sorted array is: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
