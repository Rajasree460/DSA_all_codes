/*binary search*/
#include<stdio.h>
int binary_search(int arr[],int key,int low,int high);
int main(){
    int n,a,i,j,temp,key;
    printf("enter the array size:\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array values\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
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
    printf("sorted array\n");
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    printf("enter your search element:\n");
    scanf("%d",&key);
    a=binary_search(arr,key,0,n-1);
    printf("%d found at loc: %d\n",key,a+1);
}

int binary_search(int arr[],int key,int low,int high){
    int mid=(low+high)/2;
    if(high>=low){
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            return binary_search(arr,key,low,mid-1);
        }
        else{            //arr[mid]<key
            return binary_search(arr,key,mid+1,high);
        }
    }
    else{
        printf("key not found\n"); 
    }
}
