/*matrix mul(for large dim,strassen's natrix)*/
#include<stdio.h>
#include<stdlib.h>
void large_dim_mul(int a[][5],int b[][5],int c[][5],int row1,int col1,int row2,int col2);
void strassen_mul(int a[][5],int b[][5],int c[][5],int row1,int col1,int row2,int col2);
int main()
{
int row1,col1,row2,col2,ch;
int a[5][5],b[5][5],c[5][5];
printf("enter the no of row of 1st mat: ");
scanf("%d",&row1);
printf("\nenter the no of col of 1st mat: ");
scanf("%d",&col1);
printf("\nenter the no of row of 2nd mat: ");
scanf("%d",&row2);
printf("\nenter the no of col of 2nd mat: ");
scanf("%d",&col2);
printf("\n");
while(ch!=5)
{
printf("main menu\n");
printf("1.mul of large dim matrix\n2.strassen's matrix mul\n3.exit\n");
printf("enter your choice: ");
scanf("%d",&ch);
printf("\n");
switch(ch)
{
case 1:large_dim_mul(a,b,c,row1,col1,row2,col2);
break;
case 2:strassen_mul(a,b,c,row1,col1,row2,col2);
break;
case 3:exit(0);
default:
printf("invalid ch\n");
}
}
}

void large_dim_mul(int a[][5],int b[][5],int c[][5],int row1,int col1,int row2,int col2)
{
int i,j,k,c_row,c_col;
if(col1==row2)
{
c_row=row1;
c_col=col2;
printf("enter the values of 1st matrix\n");
for(i=0;i<row1;i++)
{
for(j=0;j<col1;j++)
{
scanf("%d",&a[i][j]);
}
}
printf("enter the values of 2nd matrix\n");
for(i=0;i<row2;i++)
{
for(j=0;j<col2;j++)
{
scanf("%d",&b[i][j]);
}
}
for(i=0;i<c_row;i++)
{
for(j=0;j<c_col;j++)
{
c[i][j]=0;
for(k=0;k<c_col;k++)
{
c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
}
}
}
printf("after multiplication the result is\n");
for(i=0;i<c_row;i++)
{
printf("\n");
for(j=0;j<c_col;j++)
printf("%d\t",c[i][j]);
}
}
while(col1!=row2)
{
printf("multiplay not possible\n");
}
}

void strassen_mul(int a[][5],int b[][5],int c[][5],int row1,int col1,int row2,int col2)
{
int i,j,k,c_row,c_col;
if(col1==row2)
{
c_row=row1;
c_col=col2;
printf("enter the values of 1st matrix\n");
for(i=0;i<row1;i++)
{
for(j=0;j<col1;j++)
{
scanf("%d",&a[i][j]);
}
}
printf("enter the values of 2nd matrix\n");
for(i=0;i<row2;i++)
{
for(j=0;j<col2;j++)
{
scanf("%d",&b[i][j]);
}
}
for(i=0;i<c_row;i++)
{
for(j=0;j<c_col;j++)
{
c[i][j]=0;
for(k=0;k<c_col;k++)
{
c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
}
}
}
printf("after multiplication the result is\n");
for(i=0;i<c_row;i++)
{
printf("\n");
for(j=0;j<c_col;j++)
printf("%d\t",c[i][j]);
}
}
while(col1!=row2)
{
printf("multiplay not possible\n");
}
}

