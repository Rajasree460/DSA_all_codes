
//array union & intersection
#include <stdio.h>
void printUnion(int array1[], int size1, int array2[], int size2);
void printintersection(int array1[],int n,int array2[],int m); 
{
   int index1 = 0, index2 = 0;
   while(index1 < size1 && index2 < size2) 
   {
      if (array1[index1] < array2[index2])
         
         printf("%d ", array1[index1++]);
      else if (array2[index2] < array1[index1])
         
         printf("%d ", array2[index2++]);
      else 
	  {
         
         printf("%d ", array2[index2]);
         index1++;
         index2++;
      }
  }
  
    while(index1 < size1)
    printf("%d ", array1[index1++]);
    
  while(index2 < size2)
    printf("%d ", array2[index2++]);
}

void printintersection(int array1[],int n,int array2[],int m)
{
	int i,j,k=0;
	int b[m+n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(array1[i]==array2[j])
			{
				b[k]=array1[i];
				k++;
			}
		}
	} 
	printf("after intersection the result is\n");
	for(k=0;k<m+n;k++)
	{
		printf("%d\t",b[k]);
	}
int main()
{
	int n,m;
	printf("Enter number of 1st array elements\n");
	scanf("%d",&n);
	printf("Enter number of 2nd array elements\n");
	scanf("%d",&m);
    int array1[n] ;
    int array2[m] ;
	printf("Enter 1st array elemets\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&array1[i]);
	 }
	 printf("Enter 2nd array elemets\n");
	for(int j=0;j<m;j++)
	{
		scanf("%d",&array2[j]);
	 }  
	 printf("New array elements are\n");
 
    printUnion(array1, n, array2, m);
    printintersection(array1, n, array2, m); 
    return 0;
}

