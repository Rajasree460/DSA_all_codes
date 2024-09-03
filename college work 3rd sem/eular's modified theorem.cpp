/*eular's modified theorem*/
#include<stdio.h>
#include<math.h>
#include<string.h>
Float fun(float,float);
int main()
 {
 Int I,j,c;
 Float x[100],y[100],h,m[100],m1,m2,a,s[100],w;
 Printf(“\n C program for Modified Euler Method \n\n”);
 Printf(“ Enter the initial value of x:”);
 Scanf(“%f”,&x[0]);
 Printf(“\n Enter the value of increment h:”);
 Scanf(“%f”,&h);
 Printf(“\n Enter the final value of x:”);
 Scanf(“%f”,&a);
 Printf(“\n Enter the initial value of the variable y :”);
 Scanf(“%f”,&y[0]);
 S[0]=y[0];
 For(i=1;x[i-1]<a;i++)
 {
 W=100.0;
 X[i]= x[i-1]+h;
 M[i]=fun(x[i-1],y[i-1]);
 C=0;
 While(w>0.0001)
 {
 M1=fun(x[i],s[c]);
 M2=(m[i]+m1)/2;
 S[c+1]=y[i-1]+m2*h;
 W=s[c]-s[c+1];
 W=fabs(w);
 C=c+1;
 }
 Y[i]=s[c];
 }
 Printf(“\n\n The respective values of x and y are\n x \t y\n\n”);
 For(j=0;j<I;j++)
 {
 Printf(“ %f\t%f”,x[j],y[j]);
 Printf(“\n”);
 }
 }
Float fun(float a,float b)
 {
 Float c;
 C=a*a+b;
 Return c;
 }
