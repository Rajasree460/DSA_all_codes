/*merge sort*/
 
#include<stdio.h>

void merge_sort(int arr[],int low,int high);
void merge(int arr[],int low,int mid,int high);


int main(){
	int n,i;
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
	merge_sort(arr,0,n-1);
	printf("\nthe sorted array is: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void merge_sort(int arr[],int low,int high){   //low=0,high=n-1
	if(low<high){           //min 2 eles are required
		int mid=(low+high)/2;
		merge_sort(arr,low,mid);
		merge_sort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}  
}

void merge(int arr[],int low,int mid,int high){
	int i,j,k,n1,n2;
	n1=mid-low+1;
	n2=high-mid;
	int l1[n1],l2[n2];
	//copy
	for(i=0;i<n1;i++){
		l1[i]=arr[low+i];
	}
	for(j=0;j<n2;j++){
		l2[j]=arr[mid+1+j];
	}
	i=j=0;
	k=low;
	while(i<n1 && j<n2){
	   if(l1[i]<l2[j]){
	   	arr[k]=l1[i];
	   	i++;
	   	k++;
	   }else{
	   	arr[k]=l2[j];
	   	j++;
	   	k++;
	   }
	}
	while(i<n1){
		arr[k]=l1[i];
	   	i++;
	   	k++;
	}
	while(j<n2){
		arr[k]=l2[j];
	   	j++;
	   	k++;
	}
	/*
	for(k=low;i<i<n1 && j<n2;k++)
	{
	if(l1[i]<l2[j]){
	   	arr[k]=l1[i];
	   	i++;
	   }else{
	   	arr[k]=l2[j];
	   	j++;
	   }
    }
    while(i<n1){
		arr[k]=l1[i];
	   	i++;
	   	k++;
	}
	while(j<n2){
		arr[k]=l2[j];
	   	j++;
	   	k++;
	}
	*/
}
