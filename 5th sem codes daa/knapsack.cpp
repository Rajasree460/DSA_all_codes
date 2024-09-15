/*greedy knapsack*/
#include<stdio.h>

void knapsack(float cal[],float p[],float w[]);

int m=0,n=0;

int main(){
int	i;
float cal[20],p[20],w[20];
printf("enter max wt of knapsack: ");
scanf("%d",&m);
printf("\nenter no. of objects: ");
scanf("%d",&n);

printf("enter weights\n");
for(i=0;i<n;i++){
printf("w[%d]= ",i);
scanf("%f",&w[i]);
}

printf("\nenter profits\n");
for(i=0;i<n;i++){
printf("p[%d]= ",i);
scanf("%f",&p[i]);
}
knapsack(cal,p,w);
return 0;
}

void knapsack(float cal[],float p[],float w[]){
	int i,j,ttlp=0,k=0;
	for(i=0;i<n;i++){
     cal[i]=p[i]/w[i];
}
//for now using bubble sort
for(i=0;i<n;i++){
for(j=i+1;j<n;j++){
if(cal[i]>cal[j]){
int t1=cal[i];
cal[i]=cal[j];
cal[j]=t1;
}
}
}
printf("\n\n p[i]\t\t w[i]\t\t cal[i]\n");
for(i=0;i<n;i++){
printf("%f\t %f\t %f\t\n",p[i],w[i],cal[i]);
}
for(i=0;i<n;i++){
	if(m>0 && w[i]<m){
		m=m-w[i]; //m-=w[i]
		ttlp=ttlp+p[i]; //p+=p[i]
	}
	else
	break;
}
if(m>0){
	ttlp=ttlp+(p[i]*cal[i]);
}
printf("\nthe selected wts are: \n");
for(i=0;i<k;i++){
printf("%d\t%f\t%f\n",i+1,w[i],p[i]);
}
printf("\n the total profit is %f\n",p);
}
