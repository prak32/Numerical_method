#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) pow((1-x*x),0.5) 
int main(){
	float h,x0,x1,x2,x3,fx0,fx1,fx2,fx3,v;
	int n=3;
	printf("Enter Lower & Upper Limit\n");
	scanf("%f%f",&x0,&x3);
	h=(x3-x0)/n;
	x1=x0+h;
	x2=x0+2*h;
	x3=x0+3*h;
	fx0=f(x0);
	fx1=f(x1);
	fx2=f(x2);
	fx3=f(x3);
	v=(3*h/8)*(fx0+3*fx1+3*fx2+fx3);
	printf("Value of Integration = %f\n",v);	
	getch();
	return 0; 
	}

