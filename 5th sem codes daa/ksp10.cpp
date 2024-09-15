//ks
#include<stdio.h>

int n=0,m=0;

void knapsack(float w[],float p[],float cal[]);

int mian(){
	int i;
	float w[20],p[20],cal[20];
	printf("enter the max weight of ks: ");
	scanf("%d",&m);
	printf("\nenter the no. of objs: ");
	scanf("%d",&n);
	printf("\nenter weights & profits");
	for(i=0;i<n;i++){
		printf("\nweight[%d]: ",i+1);
		scanf("%f",&w[i]);
		printf("profit[%d]: ",i+1);
		scanf("%f",&p[i]);
	}
	for(i=0;i<n;i++){
		cal[i]=p[i]/w[i];
	}
	knapsack(w,p,cal);
	return 0;
}

void knapsack(float w[],float p[],float cal[]){
	int i,j;
	float temp;
	float total_profit=0;
	int selected_items[20];
	int ct=0;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(cal[i]<cal[j]){
				temp=cal[i];
				cal[i]=cal[j];
				cal[j]=temp;
				
				temp=w[i];
				w[i]=w[j];
				w[j]=temp;
				
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	printf("\n\nweight\tprofit\tcal\n");
	for(i=0;i<n;i++){
		printf("%.3f\t%.3f\t%.3f\n",w[i],p[i],cal[i]);
	}
	
	for(i=0;i<n;i++){
		if(m>0 && w[i]<=m){
			m-=w[i];
			total_profit+=p[i];
			selected_items[ct++]=i;
		}
		else{
			break;
		}
	}
	
	if(m>0 && i<n){
		float fraction=(float) m/w[i];
		total_profit+=fraction*p[i];
		selected_items[ct]=i;
	}
	printf("\nselected items\n");
	for(i=0;i<ct;i++){
		printf("item_id:%d, weight:%.2f, profit:%.2f\n",selected_items[i]+1,w[selected_items[i]],p[selected_items[i]]);
	}
	printf("\nmax profit:%.2f\n",total_profit);
}
