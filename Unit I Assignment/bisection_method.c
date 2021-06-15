#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
float f(float); 
int main() 
{
    float xa = 0;
    float xb = 1;
    float xm;
    float epsilon = 0.05;
    float counter = 0;
    float err;
    int itr = 1;
	
	loop1:
    printf("Enter Xa:");
    scanf("%f",&xa);
    printf("Enter Xb:");
    scanf("%f",&xb);
    printf("Initial functional values:\n");
    printf("f(%.2f) = %f\n", xa, f(xa));
    printf("f(%.2f) = %f\n\n", xb, f(xb));
    printf("epsilon = %f\n\n", epsilon);
    
        if( f(xa)*f(xb) > 0)
		 {
        	printf("Error: f(xa) and f(xb) don't have opposite signs!\n\n");
        	goto loop1;
    	 }
    	 
    		printf("step\t  xa\t\tf(xa)\t\txb\t\tf(xb)\t\txm\t\tf(xm)\t\terror\n");    
    do
	{
          xm = (xa+xb)/2;
          err = fabs((xm-xa)/xm);
          printf("%d\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n", itr, xa,f(xa), xb, f(xb), xm, f(xm), err);
          
          if( f(xa)*f(xm) < 0)
              xb = xm;
          else
              xa = xm;
          counter++; 
          itr = itr + 1;
    }
    while(counter<20.0 && fabs(err)>epsilon) ;
    printf("\nNumber of iterations done: %.0f\n", counter);
    printf("The root is: %f\n", xm);
    printf("\n\n");
    return 0;  
}
float f(float x) {
       float val;
       // val = 2*pow(x,3)-5;
       // val = sin(x)+5*x-3;
       //val = exp((-x))-5;
       val= 2.303*log10(x) + 6*x - 5;
       return val;
}

