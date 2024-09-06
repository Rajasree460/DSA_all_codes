/*matrix add,sub,mul,transpose*/
#include<stdio.h>
void add(int a[][5],int b[][5],int sum[][5],int row1,int row2,int col1,int col2);
void subtract(int a[][5],int b[][5],int sub[][5],int row1,int row2,int col1,int col2);
void multiply(int a[][5],int b[][5],int res[][5],int row1,int row2,int col1,int col2);
void transpose(int a[][5],int trans_mat[][5],int row1,int col1);
int main()
{
	int row1,row2,col1,col2;
	int a[5][5],b[5][5],sum[5][5],sub[5][5],res[5][5],trans_mat[5][5];
	printf("enter the  no of rows in 1st matrix\n");
	scanf("%d",&row1);
	printf("enter the  no of cols in 1st matrix\n");
	scanf("%d",&col1);
	printf("enter the  no of rows in 2nd matrix\n");
	scanf("%d",&row2);
	printf("enter the  no of cols in 2nd matrix\n");
	scanf("%d",&col2);
	add(a,b,sum,row1,row2,col1,col2);
	subtract(a,b,sum,row1,row2,col1,col2);
	multiply(a,b,sum,row1,row2,col1,col2);
	transpose(a,trans_mat,row1,col1);
	return 0;
}
void add(int a[][5],int b[][5],int sum[][5],int row1,int row2,int col1,int col2)
{
	int i,j,row_sum,col_sum;
	while(row1==row2 && col1==col2)
	{
		row_sum=row1;
		col_sum=col1;
		printf("enter the elements of 1st matrix\n");
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col1;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		printf("enter the elements of 2nd matrix\n");
		for(i=0;i<row2;i++)
		{
			for(j=0;j<col2;j++)
			{
				scanf("%d",&b[i][j]);
			}
		}
		for(i=0;i<row_sum;i++)
		{
			for(j=0;j<col_sum;j++)
			{
				sum[i][j]=a[i][j]+b[i][j];
			}
		}
		printf("the resultant matrix(for sum)\n");
		for(i=0;i<row_sum;i++)
		{
			printf("\n");
			for(j=0;j<col_sum;j++);
			printf("%d\t",sum[i][j]);
		}
	}
	if(row1!=row2||col1!=col2)
	{
		printf("addition not possible\n");
	}
}
void subtract(int a[][5],int b[][5],int sub[][5],int row1,int row2,int col1,int col2)
{
	int i,j,row_sub,col_sub;
	while(row1==row2 && col1==col2)
	{
		row_sub=row1;
		col_sub=col1;
		printf("enter the elements of 1st matrix\n");
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col1;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		printf("enter the elements of 2nd matrix\n");
		for(i=0;i<row2;i++)
		{
			for(j=0;j<col2;j++)
			{
				scanf("%d",&b[i][j]);
			}
		}
		for(i=0;i<row_sub;i++)
		{
			for(j=0;j<col_sub;j++)
			{
				sub[i][j]=a[i][j]+b[i][j];
			}
		}
		printf("the resultant matrix(for sub)\n");
		for(i=0;i<row_sub;i++)
		{
			printf("\n");
			for(j=0;j<col_sub;j++);
			printf("%d\t",sub[i][j]);
		}
	}
	if(row1!=row2||col1!=col2)
	{
		printf("subtraction not possible\n");
	}
}
void multiply(int a[][5],int b[][5],int res[][5],int row1,int row2,int col1,int col2)
{
	int i,j,k,res_row,res_col;
	while(col1=row2)
	{
		res_row=row1;
		res_col=col2;
		printf("enter the elements of 1st matrix\n");
		for(i=0;i<row1;i++)
		{
			for(k=0;k<col1;k++)
			{
				scanf("%d",&a[i][k]);
			}
		}
		printf("enter the elements of 2nd matrix\n");
		for(k=0;k<row2;k++)
		{
			for(j=0;j<col2;j++)
			{
				scanf("%d",&b[k][j]);
			}
		}
		for(i=0;i<res_row;i++)
		{
			for(j=0;j<res_col;j++)
			{
				res[i][j]=0;
				for(k=0;k<res_col;k++)  //this condition isc only for square matrix
				res[i][j]=res[i][j]+(a[i][k]*b[k][j]);
			}
		}
		printf("the resultant matrix(for mul)\n");
		for(i=0;i<res_row;i++)
		{
			printf("\n");
			for(j=0;j<res_col;j++);
			printf("%d\t",res[i][j]);
		}
	}
	if(row1!=row2||col1!=col2)
	{
		printf("multiplication not possible\n");
	}
}
void transpose(int a[][5],int trans_mat[][5],int row1,int col1)
{
	int i,j;
	
		printf("enter the elements of 1st matrix\n");
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col1;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		printf("the elements of 1st matrix\n");
		for(i=0;i<row1;i++)
		{
			printf("\n");
			for(j=0;j<col1;j++)
			printf("%d\t",a[i][j]);
		}
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col1;j++)
			{
				trans_mat[j][i]=a[i][j];
			}
		}
		printf("the resultant matrix(for transpose)\n");
		for(i=0;i<row1;i++)
		{
			printf("\n");
			for(j=0;j<col1;j++);
			printf("%d\t",trans_mat[j][i]);
		}
	
}
