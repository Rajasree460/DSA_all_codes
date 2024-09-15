/*insertion sort*/
#include<stdio.h>
void insertion_sort(int arr[],int n);
int main(){
    int n,i;
    printf("enter the array size:\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array values\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insertion_sort(arr,n);
}
void insertion_sort(int arr[],int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		temp=arr[i];
		j=i-1;
		while(j>=0 && temp<arr[j]){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
	printf("sorted array\n");
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
}
