/*matrix mul(for large dim)*/
#include<stdio.h>

void matrix_mul(int a[][20],int b[][20],int n);
void display(int arr[][20]);

int n=0;     //n cross n(for both a & b) 

int main()
{
int a[20][20],b[20][20],c[20][20];   //2D array of random size ,matrix is square matrix
printf("enter the val of dim(dim of both matrix A & B is same and they both are sq mat): ");
scanf("%d",&n);
printf("\n");
printf("enter the values of 1st matrix: ");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d ",&a[i][j]);
}
}
printf("\n");
printf("enter the values of 2nd matrix: ");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d ",&b[i][j]);
}
}
printf("\n");
printf("the 1st matrix\n");
display(a);
printf("the 2nd matrix\n");
display(b);
matrix_mul(a,b,n);
}


void matrix_mul(int a[][20],int b[][20],int n)
{
if(n<=2){
	for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
c[i][j]=0;
for(int k=1;k<=n;k++)
{
c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
}
}
}
}
else{
	//split both matrix each into 4 matrices of n/2 dim
	return matrix_mul(a,b,n)+matrix_mul(a,b,n)
}
}

void display(int arr[][20]){
	for(i=1;i<=n;i++)
{
printf("\n");
for(j=1;j<=n;j++)
printf("%d\t",c[i][j]);
}
}
