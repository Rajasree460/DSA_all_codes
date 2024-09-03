/*lagrange interpolation*/
#include<stdio.h>
#include<math.h>
int main()
{
float x[10],y[10],temp=1,f[10],sum,p;
int i,n,j,k=0,c;
printf("how many record you will be enter: \n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter the value of x%d\n",i);
scanf("%f",&x[i]);
printf("Enter the value of f(x%d)\n ",i);
scanf("%f",&y[i]);
}
printf("Enter x for finding f(x)\n");
scanf("%f",&p);
for(i=0;i<n;i++)
{
temp=1;
k=i;
for(j=0;j<n;j++)
{
if(k==j)
{
continue;
}
else
{
temp=temp*((p-x[j])/(x[k]-x[j]));
}
}
f[i]=y[i]*temp;
}
for(i=0;i<n;i++)
{
sum=sum+f[i];
}
printf("f(%.1f) = %f \n",p,sum);
}
