#include<stdio.h>
#include<conio.h>
int choice,j,i=0,arr[50],b[10],s;
void main()
{
 
printf("\nEnter size of array :");
scanf("%d",&s);
printf("\nEnter elements of array:");
for(i=0;i<s;i++)
 scanf("%d",&arr[i]);
menu();

}
void insert();
void delet();
void sort();
void search();
void update();
void merge();
void append();
void retrieve();
	
menu()
{ 
 printf("\n\n Array Implemetation\n");
 printf(" ---------------------\n");
 printf("\n\n What do you want to do..?");
 printf("\n\t1. Insert");
 printf("\n\t2. Delete");
 printf("\n\t3. Sort");
 printf("\n\t4. Search");
 printf("\n\t5. Update");
 printf("\n\t6. Retrieve");
 printf("\n\t7. Merge");
 printf("\n\t8. Append");
 //printf("\n\t9. Exit");
 printf("\n\n\t Your Choice :");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1: insert();
 break;
 case 2:
 delet();
 break;
 case 3: sort();
 break;
 case 4: search();
 break;
 case 5:
 update();
 break;
 case 6: retrieve();
 break;
 case 7: merge();
 break;
 case 8: append();
 break;
 /*case 9 :
 exit(1);*/
 }
}
merge()
{ int s2;
 printf("\nEnter size of array:");
 scanf("%d",&s2);
 printf("\nEnter elements of array:");
 for(i=0;i<s2;i++)
 scanf("%d",&b[i]);
 
 printf("\n\n Array Merging\n");
 printf(" ----------------\n");
 for(i=s;i<s+s2;i++)
 arr[i]=b[i-s];
 s=s+s2;
 printf("\n\n\tNew Array : ");
 for(i=0;i<s;i++)
 printf("%d ",arr[i]);
 
 menu();
 }
search()
{ int ele,loc;
 
 printf("\n\n Array Searching\n");
 printf(" ----------------\n");
 printf("\n\n\tEnter Element to be searched : ");
 scanf("%d",&ele);
 printf("Elements Found at : ");
 for(i=0;i<s;i++)
 { if(ele==arr[i])
 printf("%d ",i+1);
 }
 
 menu();
}
retrieve()
{ int ele,loc;
 
 printf("\n\n Array Retreiving\n");
 printf(" -----------------\n");
 printf("\n\n\tEnter Location : ");
 scanf("%d",&loc);
 printf("%d",arr[loc-1]);
 
 menu();
 }
sort()
{
 
 printf("\n\n Array Sorting\n");
 printf(" ----------------\n");
 printf("\n\n\tCurrent Array : ");
 for(i=0;i<s;i++)
 printf("%d ",arr[i]);
 //Sorting elements
 for(i=0;i<s;i++)
 {
 for(j=i+1;j<s;j++)
 if (arr[i]>arr[j])
 { arr[i]=arr[i]+arr[j];
 arr[j]=arr[i]-arr[j];
 arr[i]=arr[i]-arr[j];
 }
 }
 printf("\n\n\tElements Sorted");
 printf("\n\n\tSorted Array : ");
 for(i=0;i<s;i++)
 printf("%d ",arr[i]);
 
 menu();
}
insert()
{
 int loc,ele;
 
 printf("\n\n Array Insertion\n");
 printf(" ----------------\n");
 printf("\n\n\tNew Array : ");
 for(i=0;i<s;i++)
 printf("%d ",arr[i]);
 printf("\n\n\tEnter location : ");
 scanf("%d",&loc);
 printf("Enter Element : ");
 scanf("%d", &ele);
 //shifting elements
 for(i=s;i>loc-1;i--)
 arr[i]=arr[i-1];
 arr[loc-1]=ele;
 printf("\n\n\tElement Inserted");
 printf("\n\n\tNew Array : ");
 s++;
 for(i=0;i<s;i++)
 printf("%d ",arr[i]);
 
 menu();
}
append()
{
 int loc,ele;
 
 printf("\n\n Array Insertion\n");
 printf(" ----------------\n");
 printf("\n\n\tOld Array : ");
 for(i=0;i<s;i++)
 printf("%d ",arr[i]);
 printf("Enter Element : ");
 scanf("%d", &ele);
 arr[s]=ele;
 printf("\n\n\tElement Inserted");
 printf("\n\n\tNew Array : ");
 s++;
 for(i=0;i<s;i++)
 printf("%d ",arr[i]);
 
 menu();
}
delet()
{ int loc;
 
 printf("\n\n Array Deletion\n");
 printf(" ----------------\n");
 printf("\n\n\tNew Array : ");
 for(i=0;i<s;i++)
 printf("%d ",arr[i]);
 printf("\n\n\tEnter location : ");
 scanf("%d",&loc);
 //shifting elements
 for(i=loc;i<s-1;i++)
 {
 arr[i]=arr[i+1];
 }
 arr[s-1]=NULL;
 printf("\n\n\tElement Deleted");
 printf("\n\n\tNew Array : ");
 s--;
 for(i=0;i<s;i++)
 printf("%d ",arr[i]);
 
 menu();
}
update()
{ int loc,ele;
 
 printf("\n\n Array Updation\n");
 printf(" ----------------\n");
 printf("Enter location : ");
 scanf("%d", &loc);
 printf("Enter Element : ");
 scanf("%d", &ele);
 arr[loc-1]= ele;
 printf("\n\n\tElement Updated");
 printf("New Array : ");
 for(i=0;i<s;i++)
 printf("%d ",arr[i]);
 
 menu();
}
